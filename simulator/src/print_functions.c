#include <main.h>

/** 
 * This file contains various functions used to
 * print in terminal or output files.
 * The printed information in output files have 
 * been used to plot figures nad better understand 
 * the behavior of our schedulers.
**/

//~ void print_tab_of_int (int arr[], int n)
//~ {
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ printf("| %d", arr[i]); fflush(stdout);
	//~ }
	//~ printf("\n"); fflush(stdout);
//~ }

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

//~ void print_job_to_print(struct To_Print* tp)
//~ {
	//~ printf("Job to print %d, subtime %d, time %d, time used %d, transfer+waiting time %d, start/end %d/%d, empty cluster time %f will give a stretch of %f.\n", tp->job_unique_id, tp->job_subtime, tp->time, tp->time_used, tp->transfer_time + tp->waiting_for_a_load_time, tp->job_start_time, tp->job_end_time, tp->empty_cluster_time, (tp->job_end_time - tp->job_subtime)/tp->empty_cluster_time); fflush(stdout);
//~ }

//~ /** Print in a csv file information on a job that just finished. **/
//~ void to_print_job_csv(struct Job* job, int time)
//~ {
	//~ int time_used = job->end_time - job->start_time;
	
	//~ /* Plotting stats on choosen method. */
	//~ #ifdef PLOT_STATS
	//~ FILE* f_stats_choosen_method = fopen("outputs/choosen_methods.txt", "a");
	//~ if (!f_stats_choosen_method)
	//~ {
		//~ perror("Error opening file outputs/choosen_methods.txt.");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f_stats_choosen_method, "%d,%d\n", job->unique_id, job->last_choosen_method);
	//~ fclose(f_stats_choosen_method);
	//~ #endif
	
	//~ /* Only for evaluated jobs */
	//~ if (job->workload == 1)
	//~ {
		//~ struct To_Print* new = (struct To_Print*) malloc(sizeof(struct To_Print));
		//~ new->next = NULL;
		//~ new->job_unique_id = job->unique_id;
		//~ new->job_subtime = job->subtime;
		//~ new->time = time;
		//~ new->time_used = time_used;
		//~ new->transfer_time = job->transfer_time;
		//~ new->job_start_time = job->start_time;
		//~ new->job_end_time = job->end_time;
		//~ new->job_cores = job->cores;
		//~ new->waiting_for_a_load_time = job->waiting_for_a_load_time;
		//~ new->empty_cluster_time = job->delay + (job->data_size)/0.1;
		//~ new->data_type = job->index_node_list;
		//~ new->job_data_size = job->data_size;
		
		//~ new->user = job->user;
		//~ new->input_file = job->data;
		
		//~ if (job->node_used->index_node_list > job->index_node_list)
		//~ {
			//~ new->upgraded = 1;
		//~ }
		//~ else
		//~ {
			//~ new->upgraded = 0;
		//~ }
				
		//~ insert_tail_to_print_list(jobs_to_print_list, new);
	//~ }
		
	//~ #ifdef PRINT_GANTT_CHART
	//~ int i = 0;
	//~ char* file_to_open = malloc(100*sizeof(char));
	//~ strcpy(file_to_open, "outputs/Results_all_jobs_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".csv");
	//~ FILE* f = fopen(file_to_open, "a");
	//~ if (!f)
	//~ {
		//~ printf("Error opening file Results_all_jobs_scheduler.csv\n"); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ if (job->transfer_time > 0)
	//~ {
		//~ if (job->transfer_time > job->walltime) { job->transfer_time = job->walltime; }
		//~ fprintf(f, "I/O-%d,%d,delay,%f,%d,%d,1,COMPLETED_SUCCESSFULLY,%d,%d,%d,%d,%d,%d,", job->data, job->unique_id, 0.0, job->cores, job->walltime, job->start_time - first_subtime_day_0, job->transfer_time, job->start_time - first_subtime_day_0 + job->transfer_time, job->start_time - first_subtime_day_0, job->end_time - first_subtime_day_0, 1);
		//~ /* Printing the cores used. */
		//~ if (job->cores > 1)
		//~ {
			//~ for (i = 0; i < job->cores; i++)
			//~ {
				//~ if (i == job->cores - 1)
				//~ {
					//~ fprintf(f, "%d", job->node_used->unique_id*20 + job->cores_used[i]);
				//~ }
				//~ else
				//~ {
					//~ fprintf(f, "%d ", job->node_used->unique_id*20 + job->cores_used[i]);
				//~ }
			 //~ }
		//~ }
		//~ else
		//~ {
			//~ fprintf(f, "%d", job->node_used->unique_id*20 + job->cores_used[0]);
		//~ }
		//~ fprintf(f, ",-1,\"\"\n");
	//~ }
	
	//~ fprintf(f, "%d,%d,delay,%f,%d,%d,1,COMPLETED_SUCCESSFULLY,%d,%d,%d,%d,%d,%d,", job->unique_id, job->unique_id, 0.0, job->cores, job->walltime, job->start_time - first_subtime_day_0 + job->transfer_time, time_used - job->transfer_time, job->end_time - first_subtime_day_0, job->start_time - first_subtime_day_0, job->end_time - first_subtime_day_0, 1);
	//~ if (job->cores > 1)
	//~ {
		//~ for (i = 0; i < job->cores; i++)
		//~ {
			//~ if (i == job->cores - 1)
			//~ {
				//~ fprintf(f, "%d", job->node_used->unique_id*20 + job->cores_used[i]);
			//~ }
			//~ else
			//~ {
				//~ fprintf(f, "%d ", job->node_used->unique_id*20 + job->cores_used[i]);
			//~ }
		 //~ }
	//~ }
	//~ else
	//~ {
		//~ fprintf(f, "%d", job->node_used->unique_id*20 + job->cores_used[0]);
	//~ }
	//~ fprintf(f, ",-1,\"\"\n");
	
	//~ fclose(f);
	//~ free(file_to_open);
	//~ #endif
	
	//~ #ifdef PRINT_DISTRIBUTION_QUEUE_TIMES
	//~ char* file_to_open = malloc(100*sizeof(char));
	//~ strcpy(file_to_open, "outputs/Distribution_queue_times_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".txt");
	//~ FILE* f = fopen(file_to_open, "a");
	//~ if (!f)
	//~ {
		//~ perror("Error opening file.\n");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f, "%d\n", job->start_time - job->subtime);
	//~ fclose(f);
	//~ free(file_to_open);
	//~ #endif
//~ }

/** Print in a file the final results. Only called once at the end of the simulation. **/
void print_csv(struct To_Print* head_to_print)
{
	//~ printf("nb_call_finished_jobs: %d - nb_call_new_jobs: %d\n", nb_call_finished_jobs, nb_call_new_jobs); fflush(stdout);
	
	//~ int size_file_to_open = 300;

	//~ /* Stretch times for boxplots on all jobs */
	//~ char* file_to_open = malloc(size_file_to_open*sizeof(char));
	//~ char* day = malloc(22*sizeof(char));
	//~ int i = 0;
	//~ for (i = 0; i < 22; i++)
	//~ {
		//~ day[i] = input_job_file[i + 27];
	//~ }
	//~ file_to_open = malloc(size_file_to_open*sizeof(char));
	//~ strcpy(file_to_open, "data/Stretch_times_");
	//~ strcat(file_to_open, day);
	//~ strcat(file_to_open, "_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".csv");
	//~ FILE* f_stretch = fopen(file_to_open, "w");
	//~ if (!f_stretch)
	//~ {
		//~ perror("Error opening file.\n"); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }

	//~ if (strcmp(scheduler, "Fcfs") == 0)
	//~ {
		//~ scheduler = "FCFS";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_conservativebf") == 0)
	//~ {
		//~ if (backfill_mode == 0)
		//~ {
			//~ scheduler = "FCFS CONSERVATIVE BF MODE 0";
		//~ }
		//~ else if (backfill_mode == 1)
		//~ {
			//~ scheduler = "FCFS CONSERVATIVE BF MODE 1";
		//~ }
		//~ else  if (backfill_mode == 2)
		//~ {
			//~ scheduler = "FCFS CONSERVATIVE BF MODE 2";
		//~ }
		//~ else
		//~ {
			//~ printf("Error mauvais backfill mode dnas print.\n");
			//~ exit(1);
		//~ }
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_easybf") == 0)
	//~ {
		//~ scheduler = "FCFS EASY BF";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_conservativebf_x1_x0_x0_x0") == 0 || strcmp(scheduler, "Eft") == 0)
	//~ {
		//~ if (backfill_mode == 0)
		//~ {
			//~ scheduler = "EFT CONSERVATIVE BF MODE 0";
		//~ }
		//~ else if (backfill_mode == 1)
		//~ {
			//~ scheduler = "EFT CONSERVATIVE BF MODE 1";
		//~ }
		//~ else  if (backfill_mode == 2)
		//~ {
			//~ scheduler = "EFT CONSERVATIVE BF MODE 2";
		//~ }
		//~ else
		//~ {
			//~ printf("Error mauvais backfill mode dans print.\n");
			//~ exit(1);
		//~ }
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_x1_x0_x0_x0") == 0)
	//~ {
		//~ scheduler = "EFT";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_x500_x1_x0_x0") == 0)
	//~ {
		//~ scheduler = "SCORE";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_conservativebf_x500_x1_x0_x0") == 0)
	//~ {
		//~ if (backfill_mode == 0)
		//~ {
			//~ scheduler = "SCORE CONSERVATIVE BF MODE 0";
		//~ }
		//~ else if (backfill_mode == 1)
		//~ {
			//~ scheduler = "SCORE CONSERVATIVE BF MODE 1";
		//~ }
		//~ else  if (backfill_mode == 2)
		//~ {
			//~ scheduler = "SCORE CONSERVATIVE BF MODE 2";
		//~ }
		//~ else
		//~ {
			//~ printf("Error mauvais backfill mode dnas print.\n");
			//~ exit(1);
		//~ }
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_easybf_x500_x1_x0_x0") == 0)
	//~ {
		//~ scheduler = "SCORE EASY BF";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_adaptative_multiplier_if_EAT_is_t_x500_x1_x0_x0") == 0)
	//~ {
		//~ scheduler = "OPPORTUNISTIC-SCORE MIX";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_adaptative_multiplier_if_EAT_is_t_easybf_x500_x1_x0_x0") == 0)
	//~ {
		//~ scheduler = "OPPORTUNISTIC-SCORE MIX EASY BF";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_adaptative_multiplier_if_EAT_is_t_conservativebf_x500_x1_x0_x0") == 0)
	//~ {
		//~ if (backfill_mode == 0)
		//~ {
			//~ scheduler = "OPPORTUNISTIC-SCORE MIX CONSERVATIVE BF MODE 0";
		//~ }
		//~ else if (backfill_mode == 1)
		//~ {
			//~ scheduler = "OPPORTUNISTIC-SCORE MIX CONSERVATIVE BF MODE 1";
		//~ }
		//~ else  if (backfill_mode == 2)
		//~ {
			//~ scheduler = "OPPORTUNISTIC-SCORE MIX CONSERVATIVE BF MODE 2";
		//~ }
		//~ else
		//~ {
			//~ printf("Error mauvais backfill mode dnas print.\n");
			//~ exit(1);
		//~ }
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_mixed_strategy_x500_x1_x0_x0") == 0)
	//~ {
		//~ scheduler = "EFT-SCORE MIX";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_mixed_strategy_easybf_x500_x1_x0_x0") == 0)
	//~ {
		//~ scheduler = "EFT-SCORE MIX EASY BF";
	//~ }
	//~ else if (strcmp(scheduler, "Fcfs_with_a_score_mixed_strategy_conservativebf_x500_x1_x0_x0") == 0)
	//~ {
		//~ if (backfill_mode == 0)
		//~ {
			//~ scheduler = "EFT-SCORE MIX CONSERVATIVE BF MODE 0";
		//~ }
		//~ else if (backfill_mode == 1)
		//~ {
			//~ scheduler = "EFT-SCORE MIX CONSERVATIVE BF MODE 1";
		//~ }
		//~ else  if (backfill_mode == 2)
		//~ {
			//~ scheduler = "EFT-SCORE MIX CONSERVATIVE BF MODE 2";
		//~ }
		//~ else
		//~ {
			//~ printf("Error mauvais backfill mode dnas print.\n");
			//~ exit(1);
		//~ }
	//~ }
	
	//~ #ifdef PLOT_STATS
	//~ FILE* f_nb_backfilled_jobs = fopen("outputs/nb_backfilled_jobs.txt", "w");
	//~ if (!f_nb_backfilled_jobs)
	//~ {
		//~ perror("Error opening file outputs/nb_backfilled_jobs.txt.");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f_nb_backfilled_jobs, "%s: %d\n", scheduler, number_of_backfilled_jobs);
	//~ fclose(f_nb_backfilled_jobs);
	
	//~ FILE* tie_breaks_fcfs_score = fopen("outputs/tie_breaks_fcfs_score.txt", "w");
	//~ if (!tie_breaks_fcfs_score)
	//~ {
		//~ perror("Error opening file outputs/tie_breaks_fcfs_score.txt.");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(tie_breaks_fcfs_score, "%s: %d/%d\n", scheduler, number_of_tie_breaks_before_computing_evicted_files_fcfs_score, total_number_of_scores_computed);
	//~ fclose(tie_breaks_fcfs_score);
	
	//~ FILE* f_data_persistence_exploited = fopen("outputs/data_persistence_exploited.txt", "w");
	//~ if (!f_data_persistence_exploited)
	//~ {
		//~ perror("Error opening file outputs/data_persistence_exploited.txt.");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ fprintf(f_data_persistence_exploited, "%s: %d\n", scheduler, data_persistence_exploited);
	//~ fclose(f_data_persistence_exploited);
	//~ #endif
		
	//~ #ifdef PRINT_DISTRIBUTION_QUEUE_TIMES
	//~ /* For distribution of flow and queue times on each job. */
	//~ strcpy(file_to_open, "outputs/Queue_times_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".txt");
	//~ FILE* f_queue = fopen(file_to_open, "w");
	//~ if (!f_queue)
	//~ {
		//~ perror("Error opening file.\n");
		//~ exit(EXIT_FAILURE);
	//~ }
	
	
	
	//~ file_to_open = malloc(size_file_to_open*sizeof(char));
	//~ strcpy(file_to_open, "data/Flow_times_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".txt");
	//~ FILE* f_flow = fopen(file_to_open, "w");
	//~ if (!f_flow)
	//~ {
		//~ perror("Error opening file.\n");
		//~ exit(EXIT_FAILURE);
	//~ }
		
	//~ file_to_open = malloc(size_file_to_open*sizeof(char));
	//~ strcpy(file_to_open, "outputs/Stretch_times_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".txt");
	//~ FILE* f_stretch2 = fopen(file_to_open, "w");
	//~ if (!f_stretch2)
	//~ {
		//~ perror("Error opening file.\n");
		//~ exit(EXIT_FAILURE);
	//~ }
	
	//~ file_to_open = malloc(size_file_to_open*sizeof(char));
	//~ strcpy(file_to_open, "outputs/Bounded_Stretch_times_");
	//~ strcat(file_to_open, scheduler);
	//~ strcat(file_to_open, ".txt");
	//~ FILE* f_bounded_stretch = fopen(file_to_open, "w");
	//~ if (!f_bounded_stretch)
	//~ {
		//~ perror("Error opening file.\n");
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ #endif
		
	//~ /* Values evaluated. */
	//~ float max_queue_time = 0;
	//~ float mean_queue_time = 0;
	//~ float total_queue_time = 0;
	//~ float max_flow = 0;
	//~ float mean_flow = 0;
	//~ float total_flow = 0;
	//~ float total_transfer_time = 0;
	//~ float total_waiting_for_a_load_time = 0;
	//~ float total_waiting_for_a_load_time_and_transfer_time = 0;
	//~ float makespan = 0;
	//~ float total_flow_stretch = 0;
	//~ float total_flow_stretch_128 = 0;
	//~ float total_flow_stretch_256 = 0;
	//~ float total_flow_stretch_1024 = 0;
	//~ float max_flow_stretch = 0;
	//~ float total_flow_stretch_with_a_minimum = 0;
	//~ float total_flow_stretch_with_a_minimum_128 = 0;
	//~ float total_flow_stretch_with_a_minimum_256 = 0;
	//~ float total_flow_stretch_with_a_minimum_1024 = 0;
	//~ float max_flow_stretch_with_a_minimum = 0;
	//~ float mean_flow_stretch = 0;
	//~ float mean_flow_stretch_128 = 0;
	//~ float mean_flow_stretch_256 = 0;
	//~ float mean_flow_stretch_1024 = 0;
	//~ float mean_flow_stretch_with_a_minimum = 0;
	//~ float mean_flow_stretch_with_a_minimum_128 = 0;
	//~ float mean_flow_stretch_with_a_minimum_256 = 0;
	//~ float mean_flow_stretch_with_a_minimum_1024 = 0;
	//~ float core_time_used = 0;
	//~ float denominator_bounded_stretch = 0;
	//~ int nb_upgraded_jobs = 0;
	//~ int what_is_a_large_queue_time = 25000;
	//~ int nb_large_queue_times = 0;
		
	//~ int verify_nb_job_to_evaluate = 0;
	
	//~ while (head_to_print != NULL)
	//~ {
		//~ verify_nb_job_to_evaluate += 1;
		
		//~ nb_upgraded_jobs += head_to_print->upgraded;
				
		//~ /* Flow stretch */
		//~ total_flow_stretch += (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time;
		//~ if (head_to_print->job_data_size <= 128)
		//~ {
			//~ total_flow_stretch_128 += (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time;
		//~ }
		//~ else if (head_to_print->job_data_size <= 256)
		//~ {
			//~ total_flow_stretch_256 += (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time;
		//~ }
		//~ else if (head_to_print->job_data_size <= 1024)
		//~ {
			//~ total_flow_stretch_1024 += (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time;
		//~ }
		//~ else
		//~ {
			//~ printf("error print csv data type %f.\n", head_to_print->job_data_size); fflush(stdout);
			//~ exit(EXIT_FAILURE);
		//~ }

		//~ /* Bounded flow stretch */
		//~ if (head_to_print->empty_cluster_time > 300)
		//~ {
			//~ denominator_bounded_stretch = head_to_print->empty_cluster_time;
		//~ }
		//~ else
		//~ {
			//~ denominator_bounded_stretch = 300;
		//~ }
		
		//~ if (denominator_bounded_stretch == 0)
		//~ {
			//~ printf("error denomitaro == 0\n"); fflush(stdout);
			//~ exit(EXIT_FAILURE);
		//~ }
		
		//~ total_flow_stretch_with_a_minimum += (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch;
		//~ if (head_to_print->job_data_size <= 128)
		//~ {
			//~ total_flow_stretch_with_a_minimum_128 += (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch;
		//~ }
		//~ else if (head_to_print->job_data_size <= 256)
		//~ {
			//~ total_flow_stretch_with_a_minimum_256 += (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch;
		//~ }
		//~ else if (head_to_print->job_data_size <= 1024)
		//~ {
			//~ total_flow_stretch_with_a_minimum_1024 += (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch;
		//~ }
		//~ else
		//~ {
			//~ printf("error print csv data type %f.\n", head_to_print->job_data_size); fflush(stdout);
			//~ exit(EXIT_FAILURE);
		//~ }

		//~ /* Maximum flow stretch */
		//~ if (max_flow_stretch < (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time)
		//~ {
			//~ max_flow_stretch = (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time;
		//~ }
		//~ if (max_flow_stretch_with_a_minimum < (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch)
		//~ {
			//~ max_flow_stretch_with_a_minimum = (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch;
		//~ }
			
		//~ core_time_used += head_to_print->time_used*head_to_print->job_cores;

		//~ if (head_to_print->job_start_time - head_to_print->job_subtime < 0)
		//~ {
			//~ printf("Error queue time is %d for job %d.\n", head_to_print->job_start_time - head_to_print->job_subtime, head_to_print->job_unique_id); fflush(stdout);
			//~ exit(EXIT_FAILURE);
		//~ }
		
		//~ total_queue_time += head_to_print->job_start_time - head_to_print->job_subtime;
		
		//~ if (head_to_print->job_start_time - head_to_print->job_subtime > what_is_a_large_queue_time)
		//~ {
			//~ nb_large_queue_times += 1;
		//~ }
		
		//~ if (max_queue_time < head_to_print->job_start_time - head_to_print->job_subtime)
		//~ {
			//~ max_queue_time = head_to_print->job_start_time - head_to_print->job_subtime;
		//~ }
		//~ total_flow += head_to_print->job_end_time - head_to_print->job_subtime;
		//~ if (max_flow < head_to_print->job_end_time - head_to_print->job_subtime)
		//~ {
			//~ max_flow = head_to_print->job_end_time - head_to_print->job_subtime;
		//~ }
		//~ total_transfer_time += head_to_print->transfer_time;
		//~ total_waiting_for_a_load_time += head_to_print->waiting_for_a_load_time;
		//~ total_waiting_for_a_load_time_and_transfer_time += head_to_print->transfer_time + head_to_print->waiting_for_a_load_time;
		//~ if (makespan < head_to_print->job_end_time)
		//~ {
			//~ makespan = head_to_print->job_end_time;
		//~ }
		
		//~ #ifdef PRINT_DISTRIBUTION_QUEUE_TIMES
		//~ /* For distribution of flow and queue times on each job to show VS curves */
		//~ fprintf(f_queue, "%d %d %d %d %d\n", head_to_print->job_unique_id, head_to_print->job_start_time - head_to_print->job_subtime, head_to_print->data_type, head_to_print->job_end_time - head_to_print->job_start_time, head_to_print->job_subtime);
		//~ fprintf(f_flow, "%d %d %d %d %d\n", head_to_print->job_unique_id, head_to_print->job_end_time - head_to_print->job_subtime, head_to_print->data_type, head_to_print->job_end_time - head_to_print->job_start_time, head_to_print->job_subtime);
		//~ fprintf(f_stretch2, "%d %f %d %d %d\n", head_to_print->job_unique_id, (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time, head_to_print->data_type, head_to_print->job_end_time - head_to_print->job_start_time, head_to_print->job_subtime);
		//~ fprintf(f_bounded_stretch, "%d %f %d %d %d\n", head_to_print->job_unique_id, (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch, head_to_print->data_type, head_to_print->job_end_time - head_to_print->job_start_time, head_to_print->job_subtime);
		//~ #endif
		
		//~ /* Ce que j'utilise pour les boxplots */
		//~ /* Id Stretch Datatype Length Subtime, Ncores, TransferTime, user, input_file, core_time_used, bounded stretch 1min */
		//~ fprintf(f_stretch, "%d,%f,%d,%d,%d,%d,%d,%d,%d,%d,%f\n", head_to_print->job_unique_id, (head_to_print->job_end_time - head_to_print->job_subtime)/head_to_print->empty_cluster_time, head_to_print->data_type, head_to_print->job_end_time - head_to_print->job_start_time, head_to_print->job_subtime, head_to_print->job_cores, head_to_print->transfer_time + head_to_print->waiting_for_a_load_time, head_to_print->user, head_to_print->input_file, head_to_print->time_used*head_to_print->job_cores, (head_to_print->job_end_time - head_to_print->job_subtime)/denominator_bounded_stretch); fflush(stdout);
		
		
		//~ head_to_print = head_to_print->next;
	//~ }
	
	//~ if (verify_nb_job_to_evaluate != nb_job_to_evaluate)
	//~ {
		//~ printf("Error verify_nb_job_to_evaluate %d != nb_job_to_evaluate %d\n", verify_nb_job_to_evaluate, nb_job_to_evaluate); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ else
	//~ {
		//~ printf("verify_nb_job_to_evaluate %d == nb_job_to_evaluate %d\n", verify_nb_job_to_evaluate, nb_job_to_evaluate); fflush(stdout);
	//~ }
	
	//~ fclose(f_stretch);
	
	//~ #ifdef PRINT_DISTRIBUTION_QUEUE_TIMES
	//~ fclose(f_queue);
	//~ fclose(f_flow);
	//~ fclose(f_stretch2);
	//~ fclose(f_bounded_stretch);
	//~ #endif
	
	//~ /* Compute mean values */
	//~ mean_queue_time = total_queue_time/nb_job_to_evaluate;
	//~ mean_flow = total_flow/nb_job_to_evaluate;
	//~ mean_flow_stretch = total_flow_stretch/nb_job_to_evaluate;
	//~ mean_flow_stretch_128 = total_flow_stretch_128/nb_job_to_evaluate;
	//~ mean_flow_stretch_256 = total_flow_stretch_256/nb_job_to_evaluate;
	//~ mean_flow_stretch_1024 = total_flow_stretch_1024/nb_job_to_evaluate;
	//~ mean_flow_stretch_with_a_minimum = total_flow_stretch_with_a_minimum/nb_job_to_evaluate;
	//~ mean_flow_stretch_with_a_minimum_128 = total_flow_stretch_with_a_minimum_128/nb_job_to_evaluate;
	//~ mean_flow_stretch_with_a_minimum_256 = total_flow_stretch_with_a_minimum_256/nb_job_to_evaluate;
	//~ mean_flow_stretch_with_a_minimum_1024 = total_flow_stretch_with_a_minimum_1024/nb_job_to_evaluate;
	
	//~ /* Main file of results */
	//~ char* file_to_open_2 = malloc(size_file_to_open*sizeof(char));
	//~ strcpy(file_to_open_2, output_file);
	//~ FILE* f = fopen(file_to_open_2, "w");
	//~ if (!f)
	//~ {
		//~ perror("Error opening file.\n"); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }

	//~ printf("Scheduler: %s, Number of jobs evaluated: %d, Max queue time: %f, Mean queue time: %f, Total queue time: %f, Max flow: %f, Mean flow: %f, Total flow: %f, Transfer time: %f, Makespan: %f, Core time: %f, Waiting for a load time: %f, Transfer + waiting time: %f, Mean flow stretch: %f, Mean bounded flow stretch: %f, Max flow stretch: %f, Max bounded flow stretch: %f, Nb of upgraded jobs: %d, Nb large queue times (>%d): %d, Mean flow stretch 128 256 1024: %f %f %f, Mean flow stretch with a minimum 128 256 1024: %f %f %f, Number of data reuse: %d\n\n", scheduler, nb_job_to_evaluate, max_queue_time, mean_queue_time, total_queue_time, max_flow, mean_flow, total_flow, total_transfer_time, makespan, core_time_used, total_waiting_for_a_load_time, total_waiting_for_a_load_time_and_transfer_time, mean_flow_stretch, mean_flow_stretch_with_a_minimum, max_flow_stretch, max_flow_stretch_with_a_minimum, nb_upgraded_jobs, what_is_a_large_queue_time, nb_large_queue_times, mean_flow_stretch_128, mean_flow_stretch_256,mean_flow_stretch_1024, mean_flow_stretch_with_a_minimum_128, mean_flow_stretch_with_a_minimum_256, mean_flow_stretch_with_a_minimum_1024, nb_data_reuse);
	
	//~ fprintf(f, "%s,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%d,%f,%f,%f,%f,%f,%f,%d\n", scheduler, nb_job_to_evaluate, max_queue_time, mean_queue_time, total_queue_time, max_flow, mean_flow, total_flow, total_transfer_time, makespan, core_time_used, total_waiting_for_a_load_time, total_waiting_for_a_load_time_and_transfer_time, mean_flow_stretch, mean_flow_stretch_with_a_minimum, max_flow_stretch, max_flow_stretch_with_a_minimum, nb_upgraded_jobs, nb_large_queue_times, mean_flow_stretch_128, mean_flow_stretch_256,mean_flow_stretch_1024, mean_flow_stretch_with_a_minimum_128, mean_flow_stretch_with_a_minimum_256, mean_flow_stretch_with_a_minimum_1024, nb_data_reuse);
	//~ fclose(f);
	
	//~ free(file_to_open);
	//~ free(file_to_open_2);
}
