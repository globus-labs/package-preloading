#include <main.h>

char* input_job_file;

//~ int planned_or_ratio; /* O = planned, 1 = ratio */
//~ int constraint_on_sizes;
//~ int nb_cores;
//~ int nb_job_to_evaluate;
int finished_jobs;
int total_number_jobs;
//~ int total_number_jobs_no_repetition;
//~ int total_number_nodes;
struct Job_List* job_list; /* All jobs not available yet */
//~ struct Job_List* new_job_list; /* New available jobs */
//~ struct Job_List* job_list_to_start_from_history; /* With -2 and before start */
//~ struct Job_List* scheduled_job_list; /* Scheduled or available */
//~ struct Job_List* running_jobs; /* Started */
//~ struct Node_List** node_list;
//~ struct To_Print_List* jobs_to_print_list;
//~ int running_cores;
//~ int running_nodes;
//~ #ifdef PRINT_CLUSTER_USAGE
//~ int running_cores_from_workload_1;
//~ int running_nodes_workload_1;
//~ int mixed_mode;
//~ #endif
//~ int total_queue_time;
//~ int first_subtime_day_0;
//~ int nb_job_to_schedule;
//~ int nb_cores_to_schedule;
char* scheduler;
char* output_file;
//~ struct Next_Time_List* end_times;
//~ struct Next_Time_List* start_times;
//~ int nb_job_to_evaluate_started;
//~ long long Allocated_Area[3][3];
//~ long long Planned_Area[3][3];
//~ int number_node_size[3];
//~ int busy_cluster;
//~ int backfill_mode;
//~ #ifdef PLOT_STATS
//~ int number_of_backfilled_jobs;
//~ int number_of_tie_breaks_before_computing_evicted_files_fcfs_score;
//~ int total_number_of_scores_computed;
//~ int data_persistence_exploited;
//~ #endif
//~ int biggest_hole;
//~ int biggest_hole_unique_id;
//~ int global_nb_non_available_cores_at_time_t;
//~ int nb_data_reuse;
//~ int busy_cluster_threshold;

//~ #ifdef NB_HOUR_MAX
//~ int nb_h_scheduled;
//~ #endif

//~ int nb_call_finished_jobs;
//~ int nb_call_new_jobs;

int main(int argc, char *argv[])
{
	/* Init global variables */
	finished_jobs = 0;
	total_number_jobs = 0;
	
	/* Init struct */
	job_list = (struct Job_List*) malloc(sizeof(struct Job_List));
	job_list->head = NULL;
	job_list->tail = NULL;
	struct Job* job_pointer = (struct Job*) malloc(sizeof(struct Job));
		
	//~ end_times = malloc(sizeof(*end_times));
	//~ end_times->head = NULL;
	//~ start_times = malloc(sizeof(*start_times));
	//~ start_times->head = NULL;
	//~ jobs_to_print_list = malloc(sizeof(*jobs_to_print_list));
	//~ jobs_to_print_list->head = NULL;
	//~ jobs_to_print_list->tail = NULL;
		
	/* Get args */
	input_job_file = argv[1];
	scheduler = argv[2];
	output_file = argv[3];
	if (output_file == NULL)
	{
		printf("ERROR: Need output file.\n");
		exit(1);
	}
	printf("Workload: %s\n", input_job_file);
	printf("Scheduler: %s\n", scheduler);

	/* Read workload */
	read_workload(input_job_file);
	
	//~ #ifdef PRINT_CLUSTER_USAGE
	//~ write_in_file_first_times_all_day(job_list->head, first_subtime_day_0);
	//~ #endif
		
	//~ int t = first_subtime_day_0;

	//~ /* getting the number of jobs we need to schedule */
	//~ if (need_to_resume_state == false)
	//~ {
		//~ job_pointer = scheduled_job_list->head;
		//~ nb_job_to_schedule = 0;
		//~ nb_cores_to_schedule = 0;
		//~ while(job_pointer != NULL)
		//~ {
			//~ nb_job_to_schedule += 1;
			//~ nb_cores_to_schedule += job_pointer->cores;
			//~ job_pointer = job_pointer->next;
		//~ }
		//~ /* Just for -2 jobs here */
		//~ if (scheduled_job_list->head != NULL)
		//~ {
			//~ start_jobs(t, scheduled_job_list->head);
		//~ }
	//~ }

	//~ #ifdef PRINT_SCORES_DATA
	//~ FILE* f_fcfs_score = fopen("outputs/Scores_data.txt", "w");
	//~ if (!f_fcfs_score)
	//~ {
		//~ perror("fopen in main");
        //~ exit(EXIT_FAILURE);
	//~ }
	//~ fclose(f_fcfs_score);
	//~ #endif
	
	//~ /* Initializings stats on choosen method. */
	//~ #ifdef PLOT_STATS
	//~ FILE* f_stats_choosen_method = fopen("outputs/choosen_methods.txt", "w");
	//~ if (!f_stats_choosen_method)
	//~ {
		//~ perror("Error opening file outputs/choosen_methods.txt.");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f_stats_choose valeriehayot@gmail.com has been added as a collaborator on the repository. n_method, "Job_id,Chosen_method\n");
	//~ fclose(f_stats_choosen_method);
	//~ #endif
	
	//~ #ifdef PRINT_CLUSTER_USAGE
	//~ /* Fichier complet */
	//~ char* title = malloc(100*sizeof(char));
	//~ strcpy(title, "outputs/Stats_");
	//~ strcat(title, scheduler);
	//~ strcat(title, ".csv");
	//~ FILE* f_stats = fopen(title, "w");
	//~ if (!f_stats)
	//~ {
		//~ perror("fopen in main");
        //~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f_stats, "Time,Used cores,Used nodes,Scheduled jobs,Used nodes workload 1,Cores required in queue,Cores required from evaluated jobs in queue, Nodes loading a file, Used cores from workload 1, Cores loading a file\n");
	//~ int nb_jobs_in_queue = 0;
	//~ int nb_cores_in_queue = 0;
	//~ int nb_cores_from_workload_1_in_queue = 0;
	//~ free(title);
	//~ #endif
	
	//~ int i = 0;
	//~ int j = 0;
	
	//~ /** START OF SIMULATION **/
	//~ printf("Start simulation.\n"); fflush(stdout);
	
	//~ nb_call_finished_jobs = 0;
	//~ nb_call_new_jobs = 0;
		
	//~ int nusers = atoi(argv[8]);
	//~ printf("There are %d users and %d jobs, %d without repetition.\n", nusers, total_number_jobs, total_number_jobs_no_repetition);
	//~ double max_watt_hour = 0; /* Max watt-hour the machine can use */
	
	//~ /* Number of times I want to repeat the same workload */
	//~ int number_workload_repetition = 2; /* Good for default database */
	
	//~ double credit_to_each_user = 0;
	//~ bool is_credit = true;
	//~ if (strcmp(argv[10], "credit") == 0)
	//~ {
		//~ credit_to_each_user = 400000000; /* Good for count database */
	//~ }
	//~ else if (strcmp(argv[10], "carbon") == 0)
	//~ {
		//~ is_credit = false;
		//~ printf("%s\n", input_node_file);
		//~ if (strcmp(input_node_file, "inputs/clusters/set_of_endpoints_1") == 0)
		//~ {
			//~ credit_to_each_user = 300000000; /* Good for count database */
		//~ }
		//~ else if (strcmp(input_node_file, "inputs/clusters/set_of_endpoints_2") == 0)
		//~ {
			//~ credit_to_each_user = 50000000; /* Good for count database with set_of_endpoints_2 */
		//~ }
		//~ else if (strcmp(input_node_file, "inputs/clusters/set_of_endpoints_3") == 0)
		//~ {
			//~ credit_to_each_user = 100000000; /* Good for count database with set_of_endpoints_2 */
		//~ }
		//~ else
		//~ {
			//~ printf("Error set_of_endpoints.\n");
			//~ exit(EXIT_FAILURE);
		//~ }
	//~ }
	//~ else
	//~ {
		//~ printf("Wrong credit value in 10th argument\n");
		//~ exit(1);
	//~ }
	
	//~ /* Credit of each user in watt-hours */
	//~ double credit_users[nusers];
	//~ for (i = 0; i < nusers; i++)
	//~ {
		//~ credit_users[i] = credit_to_each_user;
	//~ }
	
	//~ double** next_available_time_endpoint = (double**) malloc(nusers*sizeof(double*)); //largeur /* next available time of the machine. I consider that all cores must be available as the functions sue as many threads as there are cores. */
	//~ for (i = 0; i < nusers; i++)
	//~ {
		//~ next_available_time_endpoint[i] = malloc(total_number_nodes*sizeof(double)); //largeur
	//~ }
	//~ for (i = 0; i < nusers; i++)
	//~ {
		//~ for (j = 0; j < total_number_nodes; j++)
		//~ {
			//~ next_available_time_endpoint[i][j] = 0;
		//~ }
	//~ }
	
	//~ int nb_job_forbidden_for_desktop = 0;

	//~ printf("Get association of each of the %d jobs (no rep) energy consumption and credit for each of the %d machines...\n", total_number_jobs_no_repetition, total_number_nodes);
	//~ double** tab_function_machine_energy = (double**) malloc(total_number_jobs_no_repetition*sizeof(double*)); //hauteur
	//~ double** tab_function_machine_credit = (double**) malloc(total_number_jobs_no_repetition*sizeof(double*)); //hauteur
	//~ job_pointer = job_list->head;
	//~ for (i = 0; i < total_number_jobs_no_repetition; i++)
	//~ {
		//~ if (i%25000 == 0) { printf("%d/%d\n", i, total_number_jobs_no_repetition); }
		
		//~ tab_function_machine_energy[i] = malloc(total_number_nodes*sizeof(double)); //largeur
		//~ tab_function_machine_credit[i] = malloc(total_number_nodes*sizeof(double)); //largeur
		//~ struct Node* n = node_list[0]->head;
		//~ for (j = 0; j < total_number_nodes; j++)
		//~ {
			//~ if (((strcmp(argv[9], "alok") == 0) && (job_pointer->cores > n->ncores*n->ncpu)) || (j == 2 && job_pointer->number_of_nodes[j] > 1))/* If the job requires too many core, we put -1 in tab_function_machine_energy to signifie that this association is not possible. We then use tab_function_machine_energy when selecting the endpoint to avoid choosing an impossible combination. The second part of the if is a work around for emmy and meggie database */
			//~ {
				//~ nb_job_forbidden_for_desktop ++;
				//~ tab_function_machine_energy[i][j] = -1;
			//~ }
			//~ else
			//~ {
				//~ /* Filling the values for job i on endpoint j */
				//~ if (strcmp(argv[9], "alok") == 0)
				//~ {
					//~ tab_function_machine_energy[i][j] = ((job_pointer->energy_on_machine[j]*0.000001)/3600)*job_pointer->cores + n->idle_power*(job_pointer->duration_on_machine[j]/3600)*job_pointer->number_of_nodes[j]; /* Energy in micro joules that I  convert to joule then divide by 3600 to get watt-hours and multiply by the number of cores used by the job + energy of the start up (idle power) but converted to the right duration */
					//~ max_watt_hour = n->tdp*n->ncpu*(job_pointer->duration_on_machine[j]/3600); /* max watt-hour of the machine on the given duration. Calculated as NCPU times CPU TDP times job duration on the machine in hours */
				//~ }
				//~ else /* Meggie and Emmy */
				//~ {
					//~ tab_function_machine_energy[i][j] = job_pointer->energy_on_machine[j]/3600; /* For meggie and emmy databse the energy is already computed like needed, just need to switch it to watt-hours */
					//~ max_watt_hour = n->tdp*n->ncpu*job_pointer->number_of_nodes[j]*(job_pointer->duration_on_machine[j]/3600); /* max watt-hour of the machine on the given duration. Calculated as NCPU times Nnodes times CPU TDP times job duration on the machine in hours */
				//~ }
				
				//~ if (is_credit == true)
				//~ {
					//~ tab_function_machine_credit[i][j] = (tab_function_machine_energy[i][j] + max_watt_hour)/2; /* credit that would be used with this combination. */
				//~ }
				//~ else
				//~ {
					//~ tab_function_machine_credit[i][j] = ((tab_function_machine_energy[i][j] + max_watt_hour)/2)*((n->carbon_intensity + n->carbon_rate)/1000); /* Carbon credit. Divided by 1000 because the value were in kwh */
					
					
				//~ }
					
			//~ }
			//~ n = n->next;
		//~ }
		//~ job_pointer = job_pointer->next;
	//~ }
	
	
	//~ /* Putting in a tab the carbon cost per Wh for printing in output file. */
	//~ double* carbon_cost_per_wh = malloc(total_number_nodes*sizeof(double));
	//~ double* carbon_intensity_per_wh = malloc(total_number_nodes*sizeof(double));
	//~ double* carbon_rate_per_wh = malloc(total_number_nodes*sizeof(double));
	//~ double* tdp_for_carbon = malloc(total_number_nodes*sizeof(double));
	//~ struct Node* n = node_list[0]->head;
	//~ for (i = 0; i < total_number_nodes; i++)
	//~ {
		//~ carbon_cost_per_wh[i] = (n->carbon_intensity + n->carbon_rate)/1000;
		//~ carbon_intensity_per_wh[i] = (n->carbon_intensity)/1000;
		//~ carbon_rate_per_wh[i] = (n->carbon_rate)/1000;
		//~ tdp_for_carbon[i] = n->tdp*n->ncpu;
		//~ n = n->next;
	//~ }
	
	//~ /* Assigning an endpoint to each job depending on his user's behavior */
	//~ int selected_endpoint = 0;
	//~ i = 0;
	//~ int processed_jobs = 0;
	//~ int k = 0;
	
	//~ while (i < number_workload_repetition) /* To loop on the workload until one or more user exhaust is credit */
	//~ {
		//~ job_pointer = job_list->head;
		//~ while (job_pointer != NULL)
		//~ {
			//~ for (k = 0; k < job_pointer->nb_of_repetition; k++)
			//~ {
				//~ processed_jobs += 1;
				
				//~ selected_endpoint = endpoint_selection(job_pointer->unique_id, job_pointer->user_behavior, tab_function_machine_credit, total_number_nodes, tab_function_machine_energy, job_pointer->duration_on_machine, next_available_time_endpoint);
							
				//~ update_credit(job_pointer->unique_id, &credit_users[job_pointer->user_behavior], tab_function_machine_credit[job_pointer->unique_id][selected_endpoint]);
				
				//~ /* Adding result to the To_Print structure used later to print results into a file. I do that cause it's faster than opening/closing the file each time. */
				//~ struct To_Print* new = (struct To_Print*) malloc(sizeof(struct To_Print));
				//~ new->next = NULL;
				//~ new->job_unique_id = job_pointer->unique_id;				
				//~ new->user_behavior = job_pointer->user_behavior;
				//~ new->selected_endpoint = selected_endpoint;
				//~ new->removed_credit = tab_function_machine_credit[job_pointer->unique_id][selected_endpoint];
				//~ new->new_credit	= credit_users[job_pointer->user_behavior];		
				//~ new->job_end_time_double = next_available_time_endpoint[job_pointer->user_behavior][selected_endpoint] + job_pointer->duration_on_machine[selected_endpoint]; /* Considering the next available time of the machine, when will the job will end running it on this endpoint? We dissociate users here, consider that only one is using the system at a time. They are not competing. */
				//~ new->energy_used_watt_hours = tab_function_machine_energy[job_pointer->unique_id][selected_endpoint];
				//~ new->core_hours_used = job_pointer->cores*(job_pointer->duration_on_machine[selected_endpoint]/3600);
				//~ new->queue_time = next_available_time_endpoint[job_pointer->user_behavior][selected_endpoint] - job_pointer->subtime;
				//~ new->job_cores = job_pointer->cores;
				
				
				//~ new->carbon_used = carbon_intensity_per_wh[selected_endpoint]*tab_function_machine_energy[job_pointer->unique_id][selected_endpoint] + carbon_rate_per_wh[selected_endpoint]*(tdp_for_carbon[selected_endpoint]*job_pointer->number_of_nodes[selected_endpoint]*job_pointer->duration_on_machine[selected_endpoint])/3600; /* Carbon used in grams with tdp and energy used separated and using runtime */
								
				//~ for(j = 0; j < total_number_nodes; j++)
				//~ {
					//~ new->mean_duration_on_machine += job_pointer->duration_on_machine[j];
				//~ }
				//~ new->mean_duration_on_machine = new->mean_duration_on_machine/total_number_nodes;
				
				//~ if (tab_function_machine_energy[job_pointer->unique_id][selected_endpoint] < 0)
				//~ {
					//~ printf("WTF energy %f job %d endpoint %d\n", tab_function_machine_energy[job_pointer->unique_id][selected_endpoint], job_pointer->unique_id, selected_endpoint);
					//~ exit(1);
				//~ }
				
				//~ insert_tail_to_print_list(jobs_to_print_list, new);
				
				//~ /* Update the next available time of the machine (same way we assigned a value to new->job_end_time */
				//~ next_available_time_endpoint[job_pointer->user_behavior][selected_endpoint] += job_pointer->duration_on_machine[selected_endpoint];
			//~ }
			
			//~ job_pointer = job_pointer->next;
		//~ }
		//~ i++;
	//~ }
	//~ print_csv_energy_incentive(jobs_to_print_list->head, nusers);
	//~ printf("Nb jobs that Desktop could not compute: %d.\n", nb_job_forbidden_for_desktop);
	
	printf("Finished simulation.\n");
	return 1;
}
