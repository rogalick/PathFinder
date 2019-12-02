#include"libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if(str == NULL) return NULL;
	int len = mx_strlen(str);
	char *a = mx_strnew(len);
	int j = 0, i = 0;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32) {
		i++;
	}
	for(; i < len - 1; i++) {
		if(((str[i] >= 9 && str[i] <= 13) || str[i] == 32) ) {
		}
		else {
			a[j] = str[i];
			j++;
		}
	}
	int len1 = mx_strlen(mx_strtrim(a));
	char *result = mx_strnew(len1);
	result = a;
	return result;
}
