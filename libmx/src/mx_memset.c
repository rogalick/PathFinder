#include"libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	int n1 =(int)len;
	char *string = b;
	for(int i = 0; i < n1; i++) {
		string[i] = c;
	}
	return string;
}
