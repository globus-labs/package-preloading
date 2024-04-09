#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <limits.h>

//~ /* Global variables */
//~ extern int first_node_size_to_choose_from;
//~ extern int last_node_size_to_choose_from;

extern char* input_job_file;

//~ extern int planned_or_ratio; /* O = planned, 1 = ratio */
//~ extern int constraint_on_sizes;
//~ extern int nb_cores;
//~ extern int nb_job_to_evaluate;
extern int finished_jobs;
extern int total_number_jobs;
//~ /** START ENERGY INCENTIVE **/
//~ #ifdef ENERGY_INCENTIVE
//~ extern int total_number_jobs_no_repetition;
//~ #endif
//~ /** END ENERGY INCENTIVE **/
//~ extern int total_number_nodes;
extern struct Job_List* job_list; /* All jobs not available yet */
//~ extern struct Job_List* new_job_list; /* New available jobs */
//~ extern struct Job_List* job_list_to_start_from_history; /* With -2 and before start */
//~ extern struct Job_List* scheduled_job_list; /* Scheduled or available */
//~ extern struct Job_List* running_jobs; /* Started */
//~ extern struct Node_List** node_list;
//~ extern struct To_Print_List* jobs_to_print_list;
//~ extern int running_cores;
//~ extern int running_nodes;
//~ extern int nb_job_to_schedule; /* Jobs ready but not running */
//~ extern int nb_cores_to_schedule; /* Cores ready but not running */
//~ #ifdef PRINT_CLUSTER_USAGE
//~ extern int running_nodes_workload_1;
//~ extern int mixed_mode;
//~ extern int running_cores_from_workload_1;
//~ #endif
//~ extern int total_queue_time;
//~ extern int first_subtime_day_0;
extern char* scheduler;
extern char* output_file;
//~ extern long long Planned_Area[3][3];
//~ extern int number_node_size[3];
//~ extern int busy_cluster; /* 0 = no, 1 = yes. Used for fcfs with a score adaptative multiplier that modify multiplier based on cluster contention. */
//~ extern int backfill_mode; /* 0 = no, 1 = yes. Used for fcfs with a score adaptative multiplier that modify multiplier based on cluster contention. */
//~ #ifdef PLOT_STATS
//~ extern int number_of_backfilled_jobs;
//~ extern int number_of_tie_breaks_before_computing_evicted_files_fcfs_score;
//~ extern int total_number_of_scores_computed;
//~ extern int data_persistence_exploited;
//~ #endif
//~ extern int biggest_hole;
//~ extern int biggest_hole_unique_id;
//~ extern int global_nb_non_available_cores_at_time_t;
//~ extern int nb_data_reuse;
//~ extern int busy_cluster_threshold;

//~ extern int nb_call_finished_jobs;
//~ extern int nb_call_new_jobs;

//~ /* For area_filling. This is the allocated area updated in start jobs. It corresponds to the area of jobs of size x that
 //~ * were started on nodes of size x+y, y>0. I use it as a global variable to update it in start_jobs. In the schedule of
 //~ * area flling I use a temp tab at the beggining of the schedule that copy the values of this global variable
 //~ * because the schedule can change later on with liberated cores.
 //~ */
//~ extern long long Allocated_Area[3][3];

//~ /* To only call these functions when I need it. */
//~ extern struct Next_Time_List* end_times;
//~ extern struct Next_Time_List* start_times; /* TODO try to do that with update at each new scheduled job and reset when reset jobs and reschedule */

//~ extern int nb_job_to_evaluate_started;

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

struct Job {
	struct Job* next;
	int unique_id;
    int subtime;
    int delay;
    int walltime;
    int cores;
    int data;
    float data_size;
    int index_node_list;
    int start_time;
    int end_time;
    bool end_before_walltime;
    int* cores_used;
    int transfer_time;
    int waiting_for_a_load_time;
    int workload;
    int start_time_from_history;
    int node_from_history;    
    int user;
};

//~ struct Core_in_a_hole_List {
	//~ struct Core_in_a_hole* head;
	//~ struct Core_in_a_hole* tail;
//~ };

//~ struct Core_in_a_hole {
	//~ struct Core_in_a_hole* next;
	//~ int unique_id;
	//~ int start_time_of_the_hole;
//~ };

//~ struct Data {
	//~ struct Data* next;
    //~ int unique_id;
    //~ int start_time;
    //~ int end_time;
    
    //~ #ifndef DATA_PERSISTENCE
    //~ int nb_task_using_it;
    //~ #endif
    
    //~ struct Interval_List* intervals;
    
    //~ float size;
//~ };

//~ struct Core {
    //~ int unique_id;
    //~ int available_time;
    //~ bool running_job;
    //~ int running_job_end;
    
    //~ #ifdef PRINT_CLUSTER_USAGE
    //~ int end_of_file_load; /* Used to then get the total number of cores running a load */
    //~ #endif
//~ };

struct To_Print_List {
	struct To_Print* head;
	struct To_Print* tail;
};

struct To_Print {
	struct To_Print* next;
	int job_unique_id;
    int job_subtime;
    int time;
    int time_used;
    int transfer_time;
    int job_start_time;
    int job_end_time;
    int job_cores;
    int waiting_for_a_load_time;
    float empty_cluster_time;
    int data_type;
    float job_data_size;
    int upgraded; /* Was it on bigger nodes ? 0 or 1 */
    int user;
    int input_file;
    
    /** START ENERGY INCENTIVE **/
    #ifdef ENERGY_INCENTIVE
	int user_behavior;
	int selected_endpoint;
	double removed_credit;
	double new_credit;
	double job_end_time_double;
	double energy_used_watt_hours;
	double core_hours_used;
	double queue_time;
	double mean_duration_on_machine;
	double carbon_used;
	#endif
	/** END ENERGY INCENTIVE **/
};


/* From read_input_files.c */
void read_workload(char* input_job_file);

/* From print_functions.c */
//~ void print_node_list(struct Node_List** list);
//~ void print_job_list(struct Job* list);
//~ void to_print_job_csv(struct Job* job, int time);
//~ void print_csv(struct To_Print* head_to_print);
//~ void print_data_intervals(struct Node_List** list, int t);
void print_tab_of_int (int arr[], int n);
//~ void print_holes(struct Node_List** head_node);
//~ void print_holes_specific_node(struct Node* n);
//~ void save_state(int t, int old_finished_jobs, int next_submit_time, char* input_job_file);
//~ void resume_state(int* t, int* old_finished_jobs, int* next_submit_time, char* input_job_file);
//~ void print_job_to_print(struct To_Print* tp);

/* From basic_functions.c */

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
//~ void insert_tail_to_print_list(struct To_Print_List* liste, struct To_Print* tp);
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
