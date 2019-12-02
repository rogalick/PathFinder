#include"libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if(!(str) || !(sub) || !(replace)) return NULL;
	int len = mx_strlen(str);
	int len1 = mx_strlen(sub);
	char *result = mx_strnew(len);
	for(int i = 0;  i < len; i++) {
		if((str[i] == sub[0]) && ((i + len1) <= len)) {
			char *test = malloc(len1);
			for(int j = 0; j < len1; j++) {
				test[j] = str[i + j];
			}
			if(mx_strcmp(test, sub) == 0) {
				for(int g = 0; g < mx_strlen(replace); g++) {
					result[g + i] = replace[g];
				}
			}
			i += len1 - 1;
		}
		else {
			result[i] = str[i];
		}
	}
	return result;
}
