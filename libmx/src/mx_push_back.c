#include "libmx.h"

void mx_push_back(t_list **list, void *data){
	t_list *node = malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	t_list *last_element = *list;
	while (last_element->next != NULL){
		last_element = last_element->next;
	}
	last_element->next = node;
}

