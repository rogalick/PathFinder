#include"libmx.h"
 static int compare(const char *a, const char *b) {
	while(*a && *b) {
		if(*a != *b) {
			return 0;
		}
		a++;
		b++;
		}
	return (*b == '\0');
}

char *mx_strstr( char *haystack, const char *needle) {
	while(*haystack != '\0') {
		if((*haystack == *needle) && compare(haystack, needle)) {
			return haystack;
		}
		haystack++;
	}
	return NULL;
}
