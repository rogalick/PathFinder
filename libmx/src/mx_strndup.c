#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	if(s1) {
		char *a = (char*)s1;
		int len = 0;
		int n1 = (int)n;
		while(a[len] != '\0' && len != n1) {
			len++;
		}
		char *b = mx_strnew(len);
		for(int i = 0; i < len; i++) {
			b[i] = a[i];
		}
		return b;
	}
	return NULL;
}
