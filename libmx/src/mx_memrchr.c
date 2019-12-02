#include"libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	char *a = (char*)s;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] == c) {
			return a + i;
		}
	}
	return NULL;
}
