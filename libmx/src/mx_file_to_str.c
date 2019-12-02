#include "libmx.h"

char *mx_file_to_str(const char *file) {

	
	char bufffer[1];
	int count = 0;
	int test = open(file, O_RDONLY);
	if(test < 0) return NULL;
	for(int c = read(test, bufffer, 1); c > 0; count++) {
		c = read(test, bufffer, 1);
	}
	close(test);
	char *result = mx_strnew(count);
	test = open(file, O_RDONLY);
	read(test, result, count);
	close(test);
	return result;
}
