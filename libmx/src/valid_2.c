#include "libmx.h"
int mx_atoi(const char *s);
int valid_2(char *argv2[]){
	char bufffer[1];
	int count = 0;
	int test = open(argv2[1], O_RDONLY);
	for(int c = read(test, bufffer, 1); c > 0; count++) {
		c = read(test, bufffer, 1);
	}
	close(test);
	char *stroka = mx_strnew(count);
	test = open(argv2[1], O_RDONLY);
	read(test,stroka, count);
	close(test);
	int str_number = 1;
	int i = 0;

	if (stroka[0] == '0')
	{
		mx_printstr("error: invalid number of islands\n" );
		exit(1);
	}

	for (i = 0; stroka[i] != '\n'; ++i)
	{
		if(stroka[i] < 48 || stroka[i] > 57){
			mx_printstr("error: line 1 isn't valid\n" );
			return 0;
		}


	}
	int symbol1 = 0;
	int symbol2 = 0;
	for (;stroka[i] != '\0'; ++i)
	{
		if (stroka[i] == '-')
		{
			symbol1++;
		}
		if (stroka[i] =='-')
		{
			symbol2++;
		}
		if (stroka[i] == '\n')
		{
			if (symbol2 > 1 || symbol1 > 1)
			{
			mx_printstr("error: line ");
			mx_printint(str_number);
			mx_printstr(" isn't valid\n");
			return 0;
			}
			symbol1 = 0;
			symbol2 = 0;
			str_number++;
		}
	if (stroka[i + 1] == '-' &&
	 (!((stroka[i] > 64 && stroka[i] < 91) || (stroka[i] > 96 && stroka[i] < 123))
	  && ((stroka[i + 2] > 96 && stroka[i + 2] < 123) || (stroka[i + 2] > 64 && stroka[i +2] < 91)))){
		mx_printstr("error: line ");
		mx_printint(str_number);
		mx_printstr(" isn't valid\n");
		return 0;
	}
	
	if(stroka[i] == ','){
		int j = i + 1;
		while(stroka[j] != '\n'){
			if((stroka[j] < 47 || stroka[j] > 58)){
				mx_printstr("error: line ");
				mx_printint(str_number);
				mx_printstr(" isn't valid\n");
				return 0;
			}
			j++;
		}
	}
	
	if (stroka[i + 1] == ',' &&
	 (!((stroka[i] > 64 && stroka[i] < 91) || (stroka[i] > 96 && stroka[i] < 123))
	  && (stroka[i + 2] > 47 && stroka[i + 2] < 58))) {
		mx_printstr("error: line ");
		mx_printint(str_number);
		mx_printstr(" isn't valid\n");
		return 0;
	}
}
		return 1;
}

