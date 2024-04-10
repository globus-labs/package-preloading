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
struct Valid_Build_List* valid_build_list; /* Give the last start of each type of job */
struct Job_List* job_list; /* All jobs not available yet */
//~ struct Job_List* new_job_list; /* New available jobs */
//~ struct Job_List* job_list_to_start_from_history; /* With -2 and before start */
//~ struct Job_List* scheduled_job_list; /* Scheduled or available */
//~ struct Job_List* running_jobs; /* Started */
//~ struct Node_List** node_list;
struct To_Print_List* jobs_to_print_list;
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
	
	valid_build_list = (struct Valid_Build_List*) malloc(sizeof(struct Valid_Build_List));
	valid_build_list->head = NULL;
	valid_build_list->tail = NULL;
		
	jobs_to_print_list = malloc(sizeof(*jobs_to_print_list));
	jobs_to_print_list->head = NULL;
	jobs_to_print_list->tail = NULL;
		
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
	print_job_list(job_list->head);
	
	int i = 0;
	int k = 0;
	
	/**
	 * Different modes evaluated.
	 * 0: always cold
	 * 1: always hot
	 * 2: warm for 5 minutes
	 * 3: warm for 10 minutes
	 **/
	int number_of_containers_mode = 4;
	
	/** START OF SIMULATION **/
	printf("\nStart simulation.\n");
									
	for (k = 0; k < number_of_containers_mode; k++)
	{
		printf("\nMode %d\n", k);
		job_pointer = job_list->head;
		for (i = 0; i < total_number_jobs; i++)
		{
			if (i%1 == 0)
			{
				printf("Mode %d: %d/%d\n", k, i+1, total_number_jobs);
			}
		
			/* Struct to print results later. */
			struct To_Print* new_to_print = (struct To_Print*) malloc(sizeof(struct To_Print));
			new_to_print->container_mode = k;
			new_to_print->next = NULL;
			new_to_print->unique_id = job_pointer->unique_id;
			
			/* Filling the start and build times depending on the mode. */
			switch (k)
			{
				case 0:
					cold_start(job_pointer, new_to_print);
					break;
				case 1:
					hot_start(job_pointer, new_to_print, 0);
					break;
				case 2:
					hot_start(job_pointer, new_to_print, 10*60);
					break;
				case 3:
					hot_start(job_pointer, new_to_print, 100*60);
					break;
			}
						
			insert_tail_to_print_list(jobs_to_print_list, new_to_print);
			job_pointer = job_pointer->next;
		}
		
		/* Reset list of valid times */
		free(valid_build_list);
		valid_build_list = (struct Valid_Build_List*) malloc(sizeof(struct Valid_Build_List));
		valid_build_list->head = NULL;
		valid_build_list->tail = NULL;
	}
	
	/* Printing results */
	print_csv(jobs_to_print_list->head);
	
	printf("Finished simulation!¡ \\o/ (°o°) !¡\n");
	return 1;
}
