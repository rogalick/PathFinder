#include "libmx.h"
char **mx_cities(char *stroka,int unique_cities_len, char *unique_cities[unique_cities_len]){
	int len = 0;
	for(int i = 0;stroka[i + 1] != '\0';i++){
		if(stroka[i] == '-' || stroka[i] == ','){
			len++;
		}
	}
	
	char *cities[len - 1];
	for (int i = 0; stroka[i] != '\0'; i++)
	{
		if(stroka[i] == '-' || stroka[i] == ',' || (stroka[i] > 47 && stroka[i] <58) || stroka[i] == '\n'){
			stroka[i] = ' ';
		}
	}

	int r = 0;
	for (int t = 0;stroka[t] != '\0'; t++)
	{
		if ((stroka[t] > 64 && stroka[t] < 91) || (stroka[t] > 97 && stroka[t] < 123))
		{
			int y = 0;
			int j = 0;
			for (j = t; stroka[j] != ' '; ++j,y++){
			}
			cities[r] =mx_strnew(y);
			y = 0;
			for (j = t; stroka[j] != ' '; ++j,y++){
				cities[r][y] = stroka[j];

			}
			r++;
			t = t + y;	
		}
		
	}
	
	 int counter = 0;
     int access = (len-1) * (len-1);

     while(access){
         for (int i = 0; i < len - 1; ++i){
	    if (mx_strcmp(cities[i],cities[i+1]) > 0)
		{
		    char *tmp = cities[i];
		    cities[i] = cities[i+1];
		    cities[i+1] = tmp;
	            counter++;
		}
	}
	access--;
	}
	for (int i = 0; i < len - 1; ++i)
	{
			if(mx_strcmp(cities[i],cities[i+1]) == 0){
				cities[i] = "del";
			}
	}
	//char *unique_cities[unique_cities_len - 1];
	int tt = 0;
	for (int i = 0; i < len; ++i)
	{
		if (mx_strcmp(cities[i],"del") !=0)
		{
			unique_cities[tt] = mx_strnew(mx_strlen(cities[i]));
			mx_strcpy(unique_cities[tt],cities[i]);
			tt++;
		}
	}
	return unique_cities;
	if(tt != unique_cities_len){
		mx_printstr("error: invalid number of islands\n");
		exit(1);
	}
}
