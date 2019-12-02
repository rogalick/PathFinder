#include "libmx.h"

void mx_pop_back(t_list **head) {
	t_list *prelast = *head;
	while (prelast->next->next != NULL) {
		prelast = prelast->next;
	}
	t_list *node_to_delete = prelast->next;
	prelast->next = NULL;
	free(node_to_delete);
}
