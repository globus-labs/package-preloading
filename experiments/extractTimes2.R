library(jsonlite)

getTime <- function(x){
  as.numeric(gsub("s", "", tail(unlist(strsplit(x," ")),1)))
}

getInstall <- function(app){
  if(grepl("install", app[1])){
    ins.start <- unlist(strsplit(app[grepl("install", app)], " "))[1]
    ins.stop <- unlist(strsplit(app[which(grepl("start$", app))-1], " "))[1]
    
    ins.stop <- as.POSIXct(ins.stop, format = "%Y-%m-%dT%H:%M:%OSZ") 
    ins.start <- as.POSIXct(ins.start, format = "%Y-%m-%dT%H:%M:%OSZ")
    
    installtime <- as.numeric(ins.stop - ins.start)
    
  } else {
    installtime <- -1
    
  }
  
  return(installtime)
}

folder <- "onthefly"
setwd("~")
dirs <- list.dirs(folder)

for(run in 1:1){
  data <- c()
  
  for(d in dirs[-1]){
    setwd("~")
    setwd(d)
    
    build <- readLines(paste("build",run,".txt",sep=""))
    times <- build[grepl("DONE", build)]
    times <- sapply(times, getTime)
    
    js <- read_json(paste("con",run,".txt", sep=""))
    created <- js[[1]]$Created
    started <- js[[1]]$State$StartedAt
    finished <- js[[1]]$State$FinishedAt
    
    app <- readLines(paste("run",run,".txt",sep=""))
    import.start <- unlist(strsplit(app[grepl("start loading", app)], " "))[1]
    import.stop <- unlist(strsplit(app[grepl("finish import", app)], " "))[1]
    
    if(is.null(import.stop)){
      import.stop <- unlist(strsplit(app[length(app)], " "))[1]
    }
    
    installtime <- getInstall(app)
    

    
    info <- cbind(unlist(strsplit(d,"/"))[2], sum(times), 
                  installtime, created, started, finished, import.start, import.stop)
    
    for(j in 1:5){
      js <- read_json(paste("con",run,"_", j,".txt", sep=""))
      
      created <- js[[1]]$Created
      started <- js[[1]]$State$StartedAt
      finished <- js[[1]]$State$FinishedAt
      
      app <- readLines(paste("run",run,"_", j,".txt",sep=""))
      import.start <- unlist(strsplit(app[grepl("start loading", app)], " "))[1]
      import.stop <- unlist(strsplit(app[grepl("finish import", app)], " "))[1]
      
      if(is.null(import.stop)){
        import.stop <- unlist(strsplit(app[length(app)], " "))[1]
      }
      
      installtime <- getInstall(app)
      
      info <- cbind(info, created, started, finished, import.start, import.stop, installtime)
    }
    
    data <- rbind(data, info)
    
    
    
    
  }
  
  colnames(data)[1:2] <- c("imports", "buldingtime")
  
  for(j in 1:5){
    colnames(data)[(9:14)+6*(j-1)] <- paste("run",j,".",colnames(data)[(9:14)+6*(j-1)],sep="")
  }
  
  setwd("~")
  write.table(data,paste(folder,run,".csv",sep=""), row.names = F, quote=F, sep=",")
  
}




