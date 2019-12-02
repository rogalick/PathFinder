#include"libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	if(s1 == NULL && s2 != NULL) {
		int len = mx_strlen(s2);
		char *result = mx_strnew(len);
		result = mx_strcpy(result ,s2);
		return result;
	}
	if(s1 != NULL && s2 == NULL) {
		int len = mx_strlen(s1);
		char *result = mx_strnew(len);
		result = mx_strcpy(result, s1);
		return result;
	}
	if(s1 == NULL && s2 == NULL) return NULL;
	else {
		int len1 = mx_strlen(s1);
		int len2 = mx_strlen(s2);
		char *a = mx_strnew(len1 + len2);

		for(int i = 0; i < len1; i++) {
			a[i] = s1[i];
		}
		for(int i = len1; i < len1 + len2; i++) {
			a[i] = s2[i - len1];
		}
		return a;
	}
}
