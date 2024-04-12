#include <main.h>
#define MAXCHAR 1000

void read_workload(char* input_job_file)
{
	int index = 0;
	double total_start_time_hot = 0;
	int len = 0;
	
	printf("Reading the workload\n");
	
	job_list = (struct Job_List*) malloc(sizeof(struct Job_List));
	job_list->head = NULL;
	job_list->tail = NULL;
	
	FILE *f = fopen(input_job_file, "r");
	if (!f)
	{
		perror("fopen");
        exit(EXIT_FAILURE);
	}
	
	char row[MAXCHAR];
    char *token;
    
    /* Skipping the first line */
    if (!fgets(row, MAXCHAR, f)) { perror("Error reading first line\n"); exit(EXIT_FAILURE); }
    while (feof(f) != true)
    {
        if (!fgets(row, MAXCHAR, f)) { break; }
		
		/* New job */
		struct Job *new = (struct Job*) malloc(sizeof(struct Job));
		new->unique_id = total_number_jobs;
		
        index = 0;
        token = strtok(row, ",");
        total_start_time_hot = 0;

        while (token != NULL)
        {
			//~ printf("%s /", token);
			switch (index)
			{
				case 4: /* Submission time */
					len = strlen(token);
					token[len-5] = '\0';
					new->subtime = atof(token)*1000000000;
					if (new->subtime < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 5: /* Function name */
					new->function_name = token;
					break;
				case 6: /* Runtime */
					new->runtime = atof(token);
					if (new->runtime < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 10: /* Build time */
					new->build_time = atof(token);
					if (new->build_time < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 12: /* Start time cold */
					new->start_time_cold = atof(token);
					if (new->start_time_cold < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 15: /* Start time hot 1 */
					total_start_time_hot += atof(token);
					if (total_start_time_hot < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 16: /* Start time hot 2 */
					total_start_time_hot += atof(token);
					if (total_start_time_hot < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 17: /* Start time hot 3 */
					total_start_time_hot += atof(token);
					if (total_start_time_hot < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 18: /* Start time hot 4 */
					total_start_time_hot += atof(token);
					if (total_start_time_hot < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					break;
				case 19: /* Start time hot 5 and take the mean */
					total_start_time_hot += atof(token);
					if (total_start_time_hot < 0) { printf("Error value < 0 when reading worklaod\n"); exit(1); }
					new->start_time_hot = total_start_time_hot/5;
					break;
			}
            token = strtok(NULL, ",");
            index++;
        }
        
        insert_tail_job_list(job_list, new);
        total_number_jobs++;
        
        if (total_number_jobs%50000 == 0) { printf("Read %d jobs\n", total_number_jobs); }
    }
    
	fclose(f);
	printf("Finished reading workload.\n");
}
