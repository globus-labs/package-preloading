#include <main.h>

char* input_job_file;

int finished_jobs;
int total_number_jobs;
struct Valid_Build_List* valid_build_list; /* Give the last start of each type of job */
struct Job_List* job_list; /* All jobs not available yet */
struct To_Print_List* jobs_to_print_list;
char* scheduler;
char* output_file;

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
	 * 1: warm for 5 minutes # default mean
	 * 2: warm for 10 minutes
	 * 3: warm for 15 minutes # default higher values
	 * 4: always hot
	 **/
	int number_of_containers_mode = 5;
	
	/** START OF SIMULATION **/
	printf("\nStart simulation.\n");
									
	for (k = 0; k < number_of_containers_mode; k++)
	{
		printf("\nMode %d\n", k);
		job_pointer = job_list->head;
		for (i = 0; i < total_number_jobs; i++)
		{
			if (i%50000 == 0)
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
					hot_start(job_pointer, new_to_print, 5*60);
					break;
				case 2:
					hot_start(job_pointer, new_to_print, 10*60);
					break;
				case 3:
					hot_start(job_pointer, new_to_print, 15*60);
					break;
				case 4:
					hot_start(job_pointer, new_to_print, -1);
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
	print_csv_container(jobs_to_print_list->head);
	
	printf("Finished simulation!¡ \\o/ (°o°) !¡\n");
	return 1;
}
