#include <main.h>

void insert_head_job_list(struct Job_List* liste, struct Job* j)
{
	if (liste->head == NULL)
	{
		liste->head = j;
		liste->tail = j;
	}
	else
	{
		j->next = liste->head;
		liste->head = j;
	}
}

void insert_tail_job_list(struct Job_List* liste, struct Job* j)
{
    //if head is NULL, it is an empty list
    if(liste->head == NULL)
    {
         liste->head = j;
	 }
    //Otherwise, find the last node and add the newNode
    else
    {
        struct Job *lastNode = liste->head;
        

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = j;
    }
}

//~ void insert_tail_to_print_list(struct To_Print_List* liste, struct To_Print* tp)
//~ {
	//~ if (liste->head == NULL)
	//~ {
		//~ liste->head = tp;
		//~ liste->tail = tp;
	//~ }
	//~ else
	//~ {
		//~ liste->tail->next = tp;
		//~ liste->tail = tp;
	//~ }
//~ }

//~ void insert_tail_data_list(struct Data_List* liste, struct Data* d)
//~ {
	//~ if (liste->head == NULL)
	//~ {
		//~ liste->head = d;
		//~ liste->tail = d;
	//~ }
	//~ else
	//~ {
		//~ liste->tail->next = d;
		//~ liste->tail = d;
	//~ }
//~ }

//~ /* Insert so it's sorted by start times from history. */
//~ void insert_job_in_sorted_list(struct Job_List* liste, struct Job* j)
//~ {
    //~ struct Job* current;
    //~ /* Special case for the head end */
    //~ if (liste->head == NULL || liste->head->start_time_from_history >= j->start_time_from_history) {	
		//~ j->next = liste->head;
        //~ liste->head = j;
    //~ }
    //~ else {
        //~ /* Locate the node before
//~ the point of insertion */
        //~ current = liste->head;
        //~ while (current->next != NULL && current->next->start_time_from_history <= j->start_time_from_history) {
            //~ current = current->next;
        //~ }
        
        //~ j->next = current->next;
        //~ current->next = j;
    //~ }
//~ }

//~ /* Delete all time corresponding to this time. The list is sorted so it should be easy. */
//~ void delete_next_time_linked_list(struct Next_Time_List* liste, int time_to_delete)
//~ {
    //~ if (liste == NULL)
    //~ {
		//~ printf("Error list empty.\n");
        //~ exit(EXIT_FAILURE);
    //~ }

	//~ struct Next_Time* temp = liste->head;
	//~ struct Next_Time* prev = liste->head;
	
	 //~ // If head node itself holds the key to be deleted
    //~ if (temp != NULL && temp->time == time_to_delete) {
        //~ liste->head = temp->next; // Changed head
        //~ free(temp); // free old head
        //~ return;
    //~ }
	
	//~ while (temp->time != time_to_delete && temp != NULL)
	//~ {
		//~ prev = temp;
		//~ temp = temp->next;
	//~ }
	//~ if (temp == NULL)
	//~ {
		//~ printf("Error, deletion of time %d failed.\n", time_to_delete);
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ prev->next = temp->next;
	//~ free(temp);
//~ }

//~ void delete_job_linked_list(struct Job_List* liste, int unique_id_to_delete)
//~ {
    //~ if (liste == NULL)
    //~ {
		//~ printf("Error list empty.\n"); fflush(stdout);
        //~ exit(EXIT_FAILURE);
    //~ }

	//~ struct Job* temp = liste->head;
	//~ struct Job* prev = liste->head;
	
	//~ // If head node itself holds the key to be deleted
    //~ if (temp != NULL && temp->unique_id == unique_id_to_delete)
    //~ {
        //~ liste->head = temp->next; // Changed head
        
			//~ if (temp->cores_used != NULL)
			//~ {
				//~ free(temp->cores_used);
			//~ }
			//~ free(temp);
        
        //~ return;
    //~ }
	
	//~ while (temp->unique_id != unique_id_to_delete && temp != NULL)
	//~ {
		//~ prev = temp;
		//~ temp = temp->next;
	//~ }
	//~ if (temp == NULL)
	//~ {
		//~ printf("Error, deletion of job %d failed.\n", unique_id_to_delete); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ prev->next = temp->next;
	
	//~ if (unique_id_to_delete != temp->unique_id)
	//~ {
		//~ printf("ERROR!\n"); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }
	
				//~ if (temp->cores_used != NULL)
			//~ {
				//~ free(temp->cores_used);
			//~ }
			//~ free(temp);

//~ }

//~ void delete_specific_data_from_node(struct Data_List* liste, int unique_id_to_delete)
//~ {
    //~ if (liste == NULL)
    //~ {
		//~ printf("Error list empty.\n"); fflush(stdout);
        //~ exit(EXIT_FAILURE);
    //~ }

	//~ struct Data* temp = liste->head;
	//~ struct Data* prev = liste->head;
	
	//~ // If head node itself holds the key to be deleted
    //~ if (temp != NULL && temp->unique_id == unique_id_to_delete) {
        //~ liste->head = temp->next; // Changed head
        //~ free(temp); // free old head
        //~ return;
    //~ }
	
	//~ while (temp->unique_id != unique_id_to_delete && temp != NULL)
	//~ {
		//~ prev = temp;
		//~ temp = temp->next;
	//~ }
	//~ if (temp == NULL)
	//~ {
		//~ printf("Error, deletion of data %d failed.\n", unique_id_to_delete); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ prev->next = temp->next;
	
	//~ if (unique_id_to_delete != temp->unique_id)
	//~ {
		//~ printf("ERROR!\n"); fflush(stdout);
		//~ exit(EXIT_FAILURE);
	//~ }
	
	//~ // free(temp->node_used);
	//~ free(temp);
	
//~ }

//~ /* Copy a job, delete it from list 1 and add it in tail of list 2. */
//~ void copy_delete_insert_job_list(struct Job_List* to_delete_from, struct Job_List* to_append_to, struct Job* j)
//~ {
	//~ /* If empty can't delete. */
	//~ if (to_delete_from == NULL)
    //~ {
		//~ printf("Error list empty.\n");
        //~ exit(EXIT_FAILURE);
    //~ }
    
    
    //~ /* New copy from j */
	//~ struct Job* new = (struct Job*) malloc(sizeof(struct Job));
	//~ new->next = NULL;
	//~ new->unique_id = j->unique_id;
	//~ new->subtime = j->subtime;
	//~ new->delay = j->delay;
	//~ new->walltime = j->walltime;
	//~ new->cores = j->cores;
	//~ new->data = j->data;
	//~ new->data_size = j->data_size;
	//~ new->index_node_list = j->index_node_list;
	//~ new->start_time = j->start_time;
	//~ new->end_time = j->end_time;
	//~ new->end_before_walltime = j->end_before_walltime;
	//~ new->transfer_time = j->transfer_time;
	//~ new->waiting_for_a_load_time = j->waiting_for_a_load_time;
	//~ new->workload = j->workload;
	//~ new->start_time_from_history = j->start_time_from_history;
	//~ new->node_from_history = j->node_from_history;

	//~ new->node_used = (struct Node*) malloc(sizeof(struct Node));
	//~ new->node_used = j->node_used;
	
	//~ new->user = j->user;
	
	//~ /* OLD */
	//~ /* NEW */
	//~ new->cores_used = (int*) malloc(new->cores*sizeof(int));
	//~ for (int i = 0; i < new->cores; i++)
	//~ {
		//~ new->cores_used[i] = j->cores_used[i];
	//~ }

	//~ /* Delete */
	//~ delete_job_linked_list(to_delete_from, j->unique_id);
	
	//~ /* Add in new list */
	//~ insert_tail_job_list(to_append_to, new);
//~ }

//~ /* Copy a job, delete it from list 1 and add it in tail of list 2 in sorted by decreasing file size order. */
//~ void copy_delete_insert_job_list_sorted_by_file_size(struct Job_List* to_delete_from, struct Job_List* to_append_to, struct Job* j)
//~ {
	//~ /* If empty can't delete. */
	//~ if (to_delete_from == NULL)
    //~ {
		//~ printf("Error list empty.\n");
        //~ exit(EXIT_FAILURE);
    //~ }
    
    //~ /* New copy from j */
	//~ struct Job* new = (struct Job*) malloc(sizeof(struct Job));
	//~ new->next = NULL;
	//~ new->unique_id = j->unique_id;
	//~ new->subtime = j->subtime;
	//~ new->delay = j->delay;
	//~ new->walltime = j->walltime;
	//~ new->cores = j->cores;
	//~ new->data = j->data;
	//~ new->data_size = j->data_size;
	//~ new->index_node_list = j->index_node_list;
	//~ new->start_time = j->start_time;
	//~ new->end_time = j->end_time;
	//~ new->end_before_walltime = j->end_before_walltime;
	//~ new->transfer_time = j->transfer_time;
	//~ new->waiting_for_a_load_time = j->waiting_for_a_load_time;
	//~ new->workload = j->workload;
	//~ new->start_time_from_history = j->start_time_from_history;
	//~ new->node_from_history = j->node_from_history;

	//~ new->node_used = (struct Node*) malloc(sizeof(struct Node));
	//~ new->node_used = j->node_used;
	
	//~ new->cores_used = malloc(new->cores*sizeof(int));
	//~ new->cores_used = j->cores_used;
//~ new->user = j->user;
	//~ /* Delete */
	//~ delete_job_linked_list(to_delete_from, j->unique_id);
	
	//~ /* Add in new list */
	//~ insert_job_sorted_by_decreasing_file_size(&to_append_to->head, new);
//~ }

//~ void get_length_job_list(struct Job* head, int* nb_jobs_in_queue, int* nb_cores_in_queue, int* nb_cores_from_workload_1_in_queue)
//~ {
	//~ *nb_jobs_in_queue = 0;
	//~ *nb_cores_in_queue = 0;
	//~ *nb_cores_from_workload_1_in_queue = 0;
	//~ struct Job* j = head;
	//~ while (j != NULL)
	//~ {
		//~ *nb_jobs_in_queue += 1;
		//~ *nb_cores_in_queue += j->cores;
		//~ if (j->workload == 1)
		//~ {
			//~ *nb_cores_from_workload_1_in_queue += j->cores;
		//~ }
		//~ j = j->next;
	//~ }
//~ }

//~ void free_next_time_linked_list(struct Next_Time** head_ref)
//~ {
	//~ /* deref head_ref to get the real head */
	//~ struct Next_Time* current = *head_ref;
	//~ struct Next_Time* next;
 
   //~ while (current != NULL)
   //~ {
       //~ next = current->next;
       //~ free(current);
       //~ current = next;
   //~ }
   
   //~ /* deref head_ref to affect the real head back
      //~ in the caller. */
   //~ *head_ref = NULL;
//~ }

//~ void free_cores_in_a_hole(struct Core_in_a_hole** head_ref)
//~ {
	//~ /* deref head_ref to get the real head */
	//~ struct Core_in_a_hole* current = *head_ref;
	//~ struct Core_in_a_hole* next;
 
   //~ while (current != NULL)
   //~ {
       //~ next = current->next;
       //~ free(current);
       //~ current = next;
   //~ }
   
   //~ /* deref head_ref to affect the real head back
      //~ in the caller. */
   //~ *head_ref = NULL;
//~ }

//~ void freelist(struct Interval* headNode){
    //~ struct Interval* currentNode;
    //~ while (headNode != NULL){
        //~ currentNode = headNode;
        //~ headNode = headNode->next;
        //~ free(currentNode);
    //~ }
//~ }

//~ void free_interval_linked_list(struct Interval** head_ref, struct Interval** tail_ref)
//~ {
 //~ /* deref head_ref to get the real head */
   //~ struct Interval* current = *head_ref;
   //~ struct Interval* next;
 
   //~ while (current != NULL)
   //~ {
       //~ next = current->next;
       //~ free(current);
       //~ current = next;
   //~ }
   
   //~ /* deref head_ref to affect the real head back
      //~ in the caller. */
   //~ *head_ref = NULL;
   //~ *tail_ref = NULL;
//~ }

//~ // Function to insert a given node at its correct sorted position into a given
//~ // list sorted in decreasing order
//~ void insert_job_sorted_by_decreasing_file_size(struct Job** head, struct Job* newNode)
//~ {
    //~ struct Job dummy;
    //~ struct Job* current = &dummy;
    //~ dummy.next = *head;
 
    //~ while (current->next != NULL && current->next->data_size >= newNode->data_size) {
        //~ current = current->next;
    //~ }
    //~ newNode->next = current->next;
    //~ current->next = newNode;
    //~ *head = dummy.next;
//~ }
 
//~ // Given a list, change it to be in decreasing sorted order (using `insert_job_sorted_by_decreasing_file_size()`).
//~ void sort_job_list_by_file_size(struct Job** head)
//~ {
    //~ struct Job* result = NULL;     // build the answer here
    //~ struct Job* current = *head;   // iterate over the original list
    //~ struct Job* next;
 
    //~ while (current != NULL)
    //~ {
        //~ // tricky: note the next pointer before we change it
        //~ next = current->next;
 
        //~ insert_job_sorted_by_decreasing_file_size(&result, current);
        //~ current = next;
    //~ }
	//~ *head = result;
//~ }
