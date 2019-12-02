#include"libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if(!(str) || !(sub)) {
		return -2;
	}
	int lensub = mx_strlen(sub);
	int lenstr = mx_strlen(str);
	char *subcheck = mx_strnew(lensub);
	for(int i = 0; i < lenstr; i++) {
		if(str[i] == sub[0]) {
			for(int j = 0; j < lensub; j++) {
				subcheck[j] = str[i + j];
			}
			if(mx_strcmp(subcheck, sub) == 0) {
				return i;
			}
		}
	}
	return -1;
}
