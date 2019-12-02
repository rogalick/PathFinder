#include"libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	if(str == NULL || sub == NULL) {
		return -1;
	}
	int j = 0;
	int count = 0;
	for(int i = 0; i < mx_strlen(str); i++) {
		if(str[i] == sub[j]) {
			if(j == mx_strlen(sub) - 1) {
				count++;
				j = 0;
			}
            else
			j++;
		}		
	}
	return count;
}
