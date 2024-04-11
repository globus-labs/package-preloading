#include <main.h>

void cold_start(struct Job* j, struct To_Print* new_to_print)
{
	new_to_print->runtime = j->runtime;
	new_to_print->start_time = j->start_time_cold;
	new_to_print->build_time = j->build_time;
}

/**
 * max_time_between_hot_start is in seconds
 **/
void hot_start(struct Job* j, struct To_Print* new_to_print, int max_time_between_hot_start)
{
	printf("Début de hot_start\n");
	print_valid_build_times(valid_build_list->head);
	bool hot_start_available = false;
	bool function_available = false;
	struct Valid_Build* valid_build = (struct Valid_Build*) malloc(sizeof(struct Valid_Build));
	
	for (valid_build = valid_build_list->head; valid_build != NULL; valid_build = valid_build->next)
	{
		if (strcmp(valid_build->job_name, j->function_name) == 0)
		{
			function_available = true;
			printf("Same function %s\n", j->function_name);
			printf("valid_build->earliest_valid_build_complete <= j->subtime?: %f %f\n", valid_build->earliest_valid_build_complete, j->subtime);
			if (valid_build->earliest_valid_build_complete <= j->subtime && valid_build->latest_valid_finish_time >= j->subtime)
			{
				printf("hot_start_available\n");
				hot_start_available = true;
			}
			break;
		}
	}
		
	if (hot_start_available == false)
	{
		/* Update values */
		new_to_print->runtime = j->runtime;
		new_to_print->start_time = j->start_time_cold;
		new_to_print->build_time = j->build_time;
		
		if (function_available == false)
		{
			/* Need to create a new link in the list */
			new_valid_build_times(j->function_name, j->subtime + j->build_time, j-> subtime + j->build_time + j->start_time_cold + j->runtime + max_time_between_hot_start);
		}
		else /* Update only */
		{
			update_valid_build_times(valid_build, j->subtime + j->build_time, j-> subtime + j->build_time + j->start_time_cold + j->runtime + max_time_between_hot_start);
		}
	}
	else if (hot_start_available == true) /* Update times of existing link */
	{
		/* Update values */
		new_to_print->runtime = j->runtime;
		new_to_print->start_time = j->start_time_hot;
		new_to_print->build_time = 0;

		/* Update valid times */
		update_valid_build_times(valid_build, j->subtime + j->build_time, j-> subtime + j->build_time + j->start_time_cold + j->runtime + max_time_between_hot_start);
	}

}

void new_valid_build_times(char* job_name, double build_complete_time, double finish_time)
{
	struct Valid_Build* new_valid_build = (struct Valid_Build*) malloc(sizeof(struct Valid_Build));
	
	new_valid_build->next = NULL;
	new_valid_build->job_name = job_name;
	new_valid_build->earliest_valid_build_complete = build_complete_time;
	new_valid_build->latest_valid_finish_time = finish_time;

	insert_tail_valid_build_list(valid_build_list, new_valid_build);
}

void update_valid_build_times(struct Valid_Build* vb, double build_complete_time, double finish_time)
{
	if (build_complete_time < vb->earliest_valid_build_complete)
	{
		vb->earliest_valid_build_complete = build_complete_time;
	}
	if (finish_time > vb->latest_valid_finish_time)
	{
		vb->latest_valid_finish_time = finish_time;
	}
	
	printf("Print after update of times\n");
	print_valid_build_times(valid_build_list->head);
}
