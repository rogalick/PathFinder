#include"libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	int n1 =(int)n;
    char *csrc = (char *)src; 
    char *cdst = (char *)dst; 
    for (int i = 0; i < n1; i++) 
        cdst[i] = csrc[i]; 
	return dst;
}
