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
			printf("%s /", token);
			switch (index)
			{
				case 4: /* Submission time */
					len = strlen(token);
					token[len-5] = '\0';
					new->subtime = atof(token)*1000000000;
					break;
				case 5: /* Function name */
					new->function_name = token;
					break;
				case 6: /* Runtime */
					new->runtime = atof(token);
					break;
				case 9: /* Build time */
					new->build_time = atof(token);
					break;
				case 11: /* Start time cold */
					new->start_time_cold = atof(token);
					printf("\nNew runtime: %f\n", new->start_time_cold);
					if (new->start_time_cold == -1) { exit(1); }
					break;
				case 14: /* Start time hot 1 */
					total_start_time_hot += atof(token);
					break;
				case 15: /* Start time hot 2 */
					total_start_time_hot += atof(token);
					break;
				case 16: /* Start time hot 3 */
					total_start_time_hot += atof(token);
					break;
				case 17: /* Start time hot 4 */
					total_start_time_hot += atof(token);
					break;
				case 18: /* Start time hot 5 and take the mean */
					total_start_time_hot += atof(token);
					new->start_time_hot = total_start_time_hot/5;
					break;
			}
            token = strtok(NULL, ",");
            index++;
        }
        
        insert_tail_job_list(job_list, new);
        total_number_jobs++;
    }
    
	fclose(f);
	exit(1);
	printf("Finished reading workload.\n");
}

//~ int get_nb_job_to_evaluate(struct Job* l)
//~ {
	//~ struct Job *j = l;
	//~ int count = 0;
	//~ while (j != NULL)
	//~ {
		//~ if (j->workload == 1)
		//~ {
			//~ count += 1;
		//~ }
		//~ j = j->next;
	//~ }
	//~ return count;
//~ }

//~ void write_in_file_first_times_all_day(struct Job* l, int first_subtime_day_0)
//~ {
	//~ struct Job *j = l;
	//~ bool first_before_0 = false;
	//~ bool first_day_1 = false;
	//~ bool first_day_2 = false;
	//~ int first_subtime_before_0 = 0;
	//~ int first_subtime_day_1 = 0;
	//~ int first_subtime_day_2 = 0;
	
	//~ while (j != NULL)
	//~ {
		//~ if (j->workload == -1 && first_before_0 == false)
		//~ {
			//~ first_before_0 = true;
			//~ first_subtime_before_0 = j->subtime;
		//~ }
		//~ else if (j->workload == 1 && first_day_1 == false)
		//~ {
			//~ first_day_1 = true;
			//~ first_subtime_day_1 = j->subtime - first_subtime_day_0;
		//~ }
		//~ else if (j->workload == 2 && first_day_2 == false)
		//~ {
			//~ first_day_2 = true;
			//~ first_subtime_day_2 = j->subtime - first_subtime_day_0;
		//~ }
		//~ j = j->next;
	//~ }
	
	//~ FILE *f = fopen("outputs/Start_end_evaluated_slice.txt", "w");
	//~ if (!f)
	//~ {
		//~ perror("fopen");
        //~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f, "%d %d %d %d", first_subtime_before_0, 0, first_subtime_day_1, first_subtime_day_2);
	//~ fclose(f);
//~ }
