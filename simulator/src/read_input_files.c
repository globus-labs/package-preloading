#include <main.h>

void read_workload(char* input_job_file)
{
	//~ job_list = (struct Job_List*) malloc(sizeof(struct Job_List));
		
	//~ job_list->head = NULL;
	//~ job_list->tail = NULL;
	//~ job_list_to_start_from_history = (struct Job_List*) malloc(sizeof(struct Job_List));
	//~ job_list_to_start_from_history->head = NULL;
	//~ job_list_to_start_from_history->tail = NULL;
	//~ scheduled_job_list = (struct Job_List*) malloc(sizeof(struct Job_List));
	//~ scheduled_job_list->head = NULL;
	//~ scheduled_job_list->tail = NULL;
	//~ running_jobs = (struct Job_List*) malloc(sizeof(struct Job_List));
	//~ running_jobs->head = NULL;
	//~ running_jobs->tail = NULL;
	//~ new_job_list = (struct Job_List*) malloc(sizeof(struct Job_List));
	//~ new_job_list->head = NULL;
	//~ new_job_list->tail = NULL;
	
	//~ FILE *f = fopen(input_job_file, "r");
	//~ if (!f)
	//~ {
		//~ perror("fopen");
        //~ exit(EXIT_FAILURE);
	//~ }
	
	//~ int index_node = 0;
	//~ char s[100];
    //~ char id[100];
    //~ char subtime[100];
    //~ char delay[100];
    //~ char walltime[100];
    //~ char cores[100];
    //~ char data[100];
    //~ char data_size[100];
    //~ char workload[100];
    //~ char start_time_from_history[100];
    //~ char start_node_from_history[100];
    
    //~ int user_id = 0;
    //~ char* current_user = malloc(sizeof(char)*9);
    //~ char* last_user = malloc(sizeof(char)*9);
    //~ int unique_id = 0;
    
    //~ /** START ENERGY INCENTIVE **/
//~ #ifdef ENERGY_INCENTIVE
    //~ while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", s, s, id, s, subtime, s, delay, s, walltime, s, cores, s, current_user, s, data, s, data_size, s, workload, s, start_time_from_history, s, start_node_from_history, s) == 24)
	//~ {	
		
		//~ struct Job *new = (struct Job*) malloc(sizeof(struct Job));
		//~ new->unique_id = unique_id;
		//~ unique_id += 1;
		//~ new->subtime = atoi(subtime);
		//~ new->delay = atoi(delay);	
		//~ new->walltime = atoi(walltime);
		//~ new->cores = atoi(cores);
		//~ new->data = atoi(data);
		//~ new->data_size = atof(data_size);
		//~ new->workload = atoi(workload);
		//~ new->start_time_from_history = atoi(start_time_from_history);
		//~ new->node_from_history = atoi(start_node_from_history);
		
		//~ new->duration_on_machine = malloc(sizeof(double)*total_number_nodes);
		//~ new->energy_on_machine = malloc(sizeof(double)*total_number_nodes);
		//~ new->number_of_nodes = malloc(sizeof(double)*total_number_nodes);
		
		//~ char duration_on_machine[100];
		//~ for (int i = 0; i < total_number_nodes; i++)
		//~ {
			//~ if (fscanf(f, "%s", duration_on_machine) != 1) { exit(EXIT_FAILURE); }
			//~ new->duration_on_machine[i] = atof(duration_on_machine);
		//~ }
		//~ if (fscanf(f, "%s", s) != 1) { exit(EXIT_FAILURE); };
		//~ char energy_on_machine[100];
		//~ for (int i = 0; i < total_number_nodes; i++)
		//~ {
			//~ if (fscanf(f, "%s", energy_on_machine) != 1) { exit(EXIT_FAILURE); }
			//~ new->energy_on_machine[i] = atof(energy_on_machine);
		//~ }
		//~ if (fscanf(f, "%s", s) != 1) { exit(EXIT_FAILURE); };
		//~ char number_of_nodes[100];
		//~ for (int i = 0; i < total_number_nodes; i++)
		//~ {
			//~ if (fscanf(f, "%s", number_of_nodes) != 1) { exit(EXIT_FAILURE); }
			//~ new->number_of_nodes[i] = atof(number_of_nodes);
		//~ }
		
		//~ char nb_of_repetition[100];
		//~ if (fscanf(f, "%s %s %s %s", s, s, s, nb_of_repetition) != 4) { exit(EXIT_FAILURE); };
		//~ new->nb_of_repetition = atoi(nb_of_repetition);
		
		//~ total_number_jobs += new->nb_of_repetition;
		//~ total_number_jobs_no_repetition += 1;
		//~ if (total_number_jobs%10000 == 0) { printf("Read %d jobs, %d without repetition\n", total_number_jobs, total_number_jobs_no_repetition); }

		//~ if (fscanf(f, "%s", s) != 1) { exit(EXIT_FAILURE); };
		
		//~ if (strcmp(current_user, last_user) == 0)
		//~ {
			//~ new->user = user_id;
		//~ }
		//~ else
		//~ {
			//~ strcpy(last_user, current_user);
			//~ user_id++;
			//~ new->user = user_id;
		//~ }
		
		//~ /* Get index_node */
		//~ if (constraint_on_sizes != 0)
		//~ {
			//~ if ((atof(data_size)*10)/(atoi(cores)*10) == 0.0)
			//~ {
				//~ index_node = 0;
			//~ }
			//~ else if ((atof(data_size)*10)/(atoi(cores)*10) == 6.4)
			//~ {
				//~ index_node = 0;
			//~ }
			//~ else if ((atof(data_size)*10)/(atoi(cores)*10) == 12.8)
			//~ {
				//~ index_node = 1;
			//~ }
			//~ else if ((atof(data_size)*10)/(atoi(cores)*10) == 51.2)
			//~ {
				//~ index_node = 2;
			//~ }
			//~ else
			//~ {
				//~ printf("Job %d: %f x 10 divided by %d x 10 = %f\n", atoi(id), atof(data_size), atoi(cores), (atof(data_size)*10)/(atoi(cores)*10)); fflush(stdout);
				//~ perror("Error data size in read_workload"); fflush(stdout);
				//~ exit(EXIT_FAILURE);
			//~ }
		//~ }
		//~ else
		//~ {
			//~ index_node = 0;
		//~ }
		//~ new->index_node_list = index_node;
		
		//~ new->start_time = -1; 
		//~ new->end_time = 0; 
		//~ new->end_before_walltime = false;
		
		//~ new->node_used = (struct Node*) malloc(sizeof(struct Node));
		//~ new->node_used = NULL;
		
		//~ /** START ENERGY INCENTIVE **/
		//~ new->user_behavior = atoi(current_user);
		//~ /** END ENERGY INCENTIVE **/
		
		//~ new->cores_used = (int*) malloc(new->cores*sizeof(int));
				
		//~ new->transfer_time = 0;
		//~ new->waiting_for_a_load_time = 0;
		//~ new->next = NULL;
		
		//~ /* Add in job list or job to start from history */
		//~ if (new->workload != -2)
		//~ {
			//~ insert_tail_job_list(job_list, new);
		//~ }
		//~ else
		//~ {			
			//~ insert_job_in_sorted_list(job_list_to_start_from_history, new);
		//~ }
	//~ }
    //~ /** END ENERGY INCENTIVE **/
//~ #else
    //~ while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", s, s, id, s, subtime, s, delay, s, walltime, s, cores, s, current_user, s, data, s, data_size, s, workload, s, start_time_from_history, s, start_node_from_history, s) == 24)
	//~ {
		//~ total_number_jobs += 1;
		
		//~ struct Job *new = (struct Job*) malloc(sizeof(struct Job));
		//~ new->unique_id = atoi(id);
		//~ new->subtime = atoi(subtime);
		//~ new->delay = atoi(delay);	
		//~ new->walltime = atoi(walltime);
		//~ new->cores = atoi(cores);
		//~ new->data = atoi(data);
		//~ new->data_size = atof(data_size);
		//~ new->workload = atoi(workload);
		//~ new->start_time_from_history = atoi(start_time_from_history);
		//~ new->node_from_history = atoi(start_node_from_history);
		
		//~ if (strcmp(current_user, last_user) == 0)
		//~ {
			//~ new->user = user_id;
		//~ }
		//~ else
		//~ {
			//~ strcpy(last_user, current_user);
			//~ user_id++;
			//~ new->user = user_id;
		//~ }
		
		//~ /* Get index_node */
		//~ if (constraint_on_sizes != 0)
		//~ {
			//~ if ((atof(data_size)*10)/(atoi(cores)*10) == 0.0)
			//~ {
				//~ index_node = 0;
			//~ }
			//~ else if ((atof(data_size)*10)/(atoi(cores)*10) == 6.4)
			//~ {
				//~ index_node = 0;
			//~ }
			//~ else if ((atof(data_size)*10)/(atoi(cores)*10) == 12.8)
			//~ {
				//~ index_node = 1;
			//~ }
			//~ else if ((atof(data_size)*10)/(atoi(cores)*10) == 51.2)
			//~ {
				//~ index_node = 2;
			//~ }
			//~ else
			//~ {
				//~ printf("Job %d: %f x 10 divided by %d x 10 = %f\n", atoi(id), atof(data_size), atoi(cores), (atof(data_size)*10)/(atoi(cores)*10)); fflush(stdout);
				//~ perror("Error data size in read_workload"); fflush(stdout);
				//~ exit(EXIT_FAILURE);
			//~ }
		//~ }
		//~ else
		//~ {
			//~ index_node = 0;
		//~ }
		//~ new->index_node_list = index_node;
		
		//~ new->start_time = -1; 
		//~ new->end_time = 0; 
		//~ new->end_before_walltime = false;
		
		//~ new->node_used = (struct Node*) malloc(sizeof(struct Node));
		//~ new->node_used = NULL;
		
		//~ /** START ENERGY INCENTIVE **/
		//~ if (strcmp(current_user, "credit") == 0)
		//~ {
			//~ new->user_behavior = 0;
		//~ }
		//~ else if (strcmp(current_user, "energy") == 0)
		//~ {
			//~ new->user_behavior = 1;
		//~ }
		//~ else if (strcmp(current_user, "runtime") == 0)
		//~ {
			//~ new->user_behavior = 2;
		//~ }
		//~ else if (strcmp(current_user, "random") == 0)
		//~ {
			//~ new->user_behavior = 3;
		//~ }
		//~ else
		//~ {
			//~ new->user_behavior = 0;
		//~ }
		//~ /** END ENERGY INCENTIVE **/
		
		//~ new->cores_used = (int*) malloc(new->cores*sizeof(int));
		
		
		//~ new->transfer_time = 0;
		//~ new->waiting_for_a_load_time = 0;
		//~ new->next = NULL;
		
		//~ /* Add in job list or job to start from history */
		//~ if (new->workload != -2)
		//~ {
			//~ insert_tail_job_list(job_list, new);
		//~ }
		//~ else
		//~ {			
			//~ insert_job_in_sorted_list(job_list_to_start_from_history, new);
		//~ }
	//~ }
//~ #endif
	//~ fclose(f);
	
	//~ free(current_user);
	//~ free(last_user);
	//~ printf("Finished reading workload.\n");
//~ }

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
}

//~ int get_first_time_day_0(struct Job* l)
//~ {
	//~ struct Job *j = l;
	//~ while (j != NULL && j->workload != 0) /* Attention il faut mettre le j != NULL avant car sinon le j->workload sur un maillon NULL fais un segfault. */
	//~ {
		//~ j = j->next;
	//~ }
	//~ /* Cas où il n'y a pas de jobs de catégorie 0, comme dans les tests. */
	//~ if (j == NULL)
	//~ {
		//~ printf("No jobs of category 0. First subtime day 0 is set to 0.\n");
		//~ return 0;
	//~ }
	//~ return j->subtime;
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
