#include "libmx.h"

void mx_push_front(t_list **list, void *data){
	t_list *node = malloc(sizeof(t_list));
	node->data = data;
	node->next = (*list);
	(*list ) = node;
}
