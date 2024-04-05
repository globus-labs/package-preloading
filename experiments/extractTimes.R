library(jsonlite)

getTime <- function(x){
  as.numeric(gsub("s", "", tail(unlist(strsplit(x," ")),1)))
}

folder <- "intelligent"
setwd("~")
dirs <- list.dirs(folder)

for(run in 1:10){
  data <- c()
  
  for(d in dirs[-1]){
    setwd("~")
    setwd(d)
    
    build <- readLines(paste("build",run,".txt",sep=""))
    times <- build[grepl("DONE", build)]
    times <- sapply(times, getTime)
    
    installtime <- build[grepl("RUN cat requirements.txt", build)]
    if(length(installtime)==0){
      installtime <- -1
    } else {
      ind <- unlist(strsplit(installtime," "))[1]
      installtime <- times[grepl(ind, names(times))]
    }
    
    js <- read_json(paste("con",run,".txt", sep=""))
    
    created <- js[[1]]$Created
    started <- js[[1]]$State$StartedAt
    finished <- js[[1]]$State$FinishedAt
    
    app <- readLines(paste("run",run,".txt",sep=""))
    import.start <- unlist(strsplit(app[3], " "))[1]
    import.stop <- unlist(strsplit(app[4], " "))[1]
    
    info <- cbind(unlist(strsplit(d,"/"))[2], sum(times), 
                  installtime, created, started, finished, import.start, import.stop)
    
    for(j in 1:5){
      js <- read_json(paste("con",run,"_", j,".txt", sep=""))
      
      created <- js[[1]]$Created
      started <- js[[1]]$State$StartedAt
      finished <- js[[1]]$State$FinishedAt
      
      app <- readLines(paste("run",run,"_", j,".txt",sep=""))
      import.start <- unlist(strsplit(app[3], " "))[1]
      import.stop <- unlist(strsplit(app[4], " "))[1]
      
      info <- cbind(info, created, started, finished, import.start, import.stop)
    }
    
    data <- rbind(data, info)
    
    
    
    
  }
  
  colnames(data)[1:2] <- c("imports", "buldingtime")
  
  for(j in 1:5){
    colnames(data)[(9:13)+5*(j-1)] <- paste("run",j,".",colnames(data)[(9:13)+5*(j-1)],sep="")
  }
  
  setwd("~")
  write.table(data,paste(folder,run,".csv",sep=""), row.names = F, quote=F, sep=",")
  
}




