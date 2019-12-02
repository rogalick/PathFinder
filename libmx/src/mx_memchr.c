#include"libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	int n1 =(int)n;
	char *a = (char*) s;
	for(int i = 0; i < n1 && a[i]; i++) {
		if(a[i] == c) {
			return a + i;
		}
	}
	return NULL;
}
