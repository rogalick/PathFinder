#include"libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	int n1 =(int)len;
	char *a = (char*) dst;
	char *b = (char*) src;
	for(int i = 0; i < n1; i++) {
		a[i] = b[i];
	}
	return a;
}
