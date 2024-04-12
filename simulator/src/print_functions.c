#include <main.h>

/** 
 * This file contains various functions used to
 * print in terminal or output files.
 * The printed information in output files have 
 * been used to plot figures nad better understand 
 * the behavior of our schedulers.
**/

void print_job_list(struct Job* list)
{
	printf("\nJob list:\n");
	struct Job* j = list;
	while (j != NULL)
	{
		printf("Id: %d Function_name: %s Subtime %f Build_time %f Start_time_cold %f Start_time_hot %f Runtime %f\n", j->unique_id, j->function_name, j->subtime, j->build_time, j->start_time_cold, j->start_time_hot, j->runtime);
		j = j->next;
	}
}

void print_valid_build_times(struct Valid_Build* list)
{
	printf("\nValid times:\n");
	struct Valid_Build* j = list;
	while (j != NULL)
	{
		printf("job_name: %s earliest_valid_build_complete: %f latest_valid_finish_time %f\n", j->job_name, j->earliest_valid_build_complete, j->latest_valid_finish_time);
		j = j->next;
	}
}

void print_csv_container(struct To_Print* head_to_print)
{
	FILE *f;
	int unique_id = 0;
    
	f = fopen(output_file, "w");
	if (!f)
	{
		perror("Error opening file in print_csv_energy_incentive.\n"); fflush(stdout);
		exit(EXIT_FAILURE);
	}
	printf("Writing outputs in %s\n", output_file);

	fprintf(f, "Job_unique_id, Job_shared_id, Container_mode, Runtime, Start_time, Build_time\n");
	while (head_to_print != NULL)
	{
		fprintf(f, "%d, %d, %d, %f, %f, %f\n", unique_id, head_to_print->unique_id, head_to_print->container_mode, head_to_print->runtime, head_to_print->start_time, head_to_print->build_time);
		head_to_print = head_to_print->next;
		unique_id++;
	}
	fclose(f);
}
