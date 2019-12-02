#include "libmx.h"

int mx_list_size(t_list *list) {
	if(list == NULL){
		return 0;
	}
	int size = 0;
	t_list *kk = list;
	while (list->next != NULL) {
		list = list->next;
		size++;
	}
	size++;
	list = kk;
	return size;
}
