#include"libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp) (void *,void *)) {
	t_list *swap = lst;
	int i = 0;
	while(swap -> next != NULL) {
		swap = swap -> next;
		i++;
	}
	i++;
	void *fapfap;
	t_list *swap1 = lst;
	while(i!= 0) {
		while(swap1->next->next != NULL) {
			if(cmp(swap1->data,swap1->next->data) == 1){
				fapfap = swap1->data;
				swap1->data = swap1->next->data;
				swap1->next->data = fapfap;
			}
			swap1 = swap1->next;			
		}
		swap1 = lst;		
		i--;
	}
	return lst;
}
