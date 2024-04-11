#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <limits.h>

extern char* input_job_file;
extern int finished_jobs;
extern int total_number_jobs;
extern struct Job_List* job_list; /* All jobs not available yet */
extern struct To_Print_List* jobs_to_print_list;
extern struct Valid_Build_List* valid_build_list;
extern char* scheduler;
extern char* output_file;

//~ /* For fcfs with a score. Allow me to not compute multiple time the same amount of copy of a file at a certain time when computing the amount of copy. I also use it to see if a data was already checked in the reduced complexity version. */
//~ struct Time_or_Data_Already_Checked_Nb_of_Copy_List {
	//~ struct Time_or_Data_Already_Checked_Nb_of_Copy* head;
//~ };
//~ struct Time_or_Data_Already_Checked_Nb_of_Copy {
	//~ struct Time_or_Data_Already_Checked_Nb_of_Copy* next;
	//~ int time_or_data;
	//~ int nb_of_copy;
//~ };

//~ struct Next_Time_List {
	//~ struct Next_Time* head;
//~ };

//~ struct Next_Time {
	//~ struct Next_Time* next;
	//~ int time;
//~ };

struct Job_List {
	struct Job* head;
	struct Job* tail;
};

//~ struct Node_List {
	//~ struct Node* head;
	//~ struct Node* tail;
//~ };

//~ struct Data_List {
	//~ struct Data* head;
	//~ struct Data* tail;
//~ };

struct Valid_Build_List {
	struct Valid_Build* head;
	struct Valid_Build* tail;
};

/**
 * Contains the job name in char.
 * Used to update the earliest build complete that is 
 * still valid, meaning the container is still hot, and 
 * latest finish of this type of function.
 * When a new job is from this type we update
 * last buld complete time and last finish time if it
 * is larger.
 **/
struct Valid_Build {
	struct Valid_Build* next;
	char* job_name;
	double earliest_valid_build_complete; /* Earliest build completion time still valid. */
	double latest_valid_finish_time; /* Latest termination time still valid. */
};

struct Job {
	struct Job* next;
	double runtime;
	double start_time_cold;
	double start_time_hot;
	double build_time;
	int unique_id;
	char* function_name;
    double subtime;
};

struct To_Print_List {
	struct To_Print* head;
	struct To_Print* tail;
};

struct To_Print {
	struct To_Print* next;
	int container_mode;
	int unique_id;
	double runtime;
	double start_time;
	double build_time;
};

/* From read_input_files.c */
void read_workload(char* input_job_file);

/* From print_functions.c */
void print_job_list(struct Job* list);
void print_csv_container(struct To_Print* head_to_print);
void print_valid_build_times(struct Valid_Build* list);

/* From container_functions.c */
void cold_start(struct Job* j, struct To_Print* new_to_print);
void hot_start(struct Job* j, struct To_Print* new_to_print, int max_time_between_hot_start);
void new_valid_build_times(char* job_name, double build_complete_time, double finish_time);
void update_valid_build_times(struct Valid_Build* vb, double build_complete_time, double finish_time);

/* From linked_list_functions.c */
void insert_head_job_list(struct Job_List* liste, struct Job* j);
void insert_tail_job_list(struct Job_List* liste, struct Job* j);
//~ void insert_tail_data_list(struct Data_List* liste, struct Data* d);
//~ void delete_job_linked_list(struct Job_List* liste, int unique_id_to_delete);
//~ void copy_delete_insert_job_list(struct Job_List* to_delete_from, struct Job_List* to_append_to, struct Job* j);
//~ void copy_delete_insert_job_list_sorted_by_file_size(struct Job_List* to_delete_from, struct Job_List* to_append_to, struct Job* j);
//~ void get_length_job_list(struct Job* head, int* nb_jobs_in_queue, int* nb_cores_in_queue, int* nb_cores_from_workload_1_in_queue);
//~ void insert_next_time_in_sorted_list(struct Next_Time_List* liste, int time_to_insert);
//~ void delete_next_time_linked_list(struct Next_Time_List* liste, int time_to_delete);
//~ void free_next_time_linked_list(struct Next_Time** head_ref);
void insert_tail_to_print_list(struct To_Print_List* liste, struct To_Print* tp);
void insert_tail_valid_build_list(struct Valid_Build_List* liste, struct Valid_Build* tp);
//~ void insert_job_in_sorted_list(struct Job_List* liste, struct Job* j);
//~ void create_and_insert_tail_interval_list(struct Interval_List* liste, int time_to_insert);
//~ void free_interval_linked_list(struct Interval** head_ref, struct Interval** tail_ref);
//~ void create_and_insert_head_time_or_data_already_checked_nb_of_copy_list(struct Time_or_Data_Already_Checked_Nb_of_Copy_List* liste, int time_or_data_to_insert, int nb_of_copy_to_insert);
//~ void free_time_or_data_already_checked_nb_of_copy_linked_list(struct Time_or_Data_Already_Checked_Nb_of_Copy** head_ref);
//~ void increment_time_or_data_nb_of_copy_specific_time_or_data(struct Time_or_Data_Already_Checked_Nb_of_Copy_List* liste, int time_or_data_to_increment);
//~ void sort_cores_by_available_time_in_specific_node(struct Node* n);
//~ void insert_job_sorted_by_decreasing_file_size(struct Job** head, struct Job* newNode);
//~ void sort_job_list_by_file_size(struct Job** head);
//~ void initialize_cores_in_a_hole(struct Core_in_a_hole_List* liste, struct Core_in_a_hole* c);
//~ void insert_cores_in_a_hole_list_sorted_decreasing_order(struct Core_in_a_hole_List* liste, struct Core_in_a_hole* c);
//~ void delete_core_in_hole_from_head(struct Core_in_a_hole_List* liste, int nb_cores_to_delete);
//~ void free_cores_in_a_hole(struct Core_in_a_hole** head_ref);
//~ void delete_core_in_hole_specific_core(struct Core_in_a_hole_List* liste, int unique_id_to_delete);
//~ void delete_specific_data_from_node(struct Data_List* liste, int unique_id_to_delete);
//~ void free_and_copy_data_and_intervals_in_temp_data(struct Node_List** head_node, int t);
//~ void sort_cores_by_unique_id_in_specific_node(struct Node* n);
//~ void insert_cores_in_a_hole_list_sorted_increasing_order(struct Core_in_a_hole_List* liste, struct Core_in_a_hole* c);
