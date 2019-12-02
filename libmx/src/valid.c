#include "libmx.h"
int valid(int ar,char const *argv2[]){
	if (ar > 2 || ar == 1)
	{
		mx_printstr("usage: ./pathfinder [filename]\n");
		return 0;
	}
	if (!mx_file_to_str(argv2[1]))
	{
		mx_printstr("error: file ");
		mx_printstr(argv2[1]);
		mx_printstr(" doesn't exist\n");
		return 0;
	}
	return 1;
}
