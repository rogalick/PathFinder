#include"libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    int n1 =(int)n;
	char *a = (char*)s1;
	char *b = (char*)s2;
	int i = 0;
    while(a[i] == b[i] && i < n1) {
        if(a[i] == '\0') {
            return 0;
        }
        i++;
    }
    if(a[i] != b[i]) {
        return a[i] - b[i];
    }
    return 0;
}
