#include "libmx.h"
int mx_unique_len(char *stroka){
	int unique_cities_len = 0;
 	int razmer = 1;
	for (int i = 0; stroka[i + 1] != '\n'; ++i)
	{
		razmer = razmer * 10;
	}
	for (int i = 0; stroka[i] != '\n'; ++i)
	{
		unique_cities_len = unique_cities_len +(stroka[i] - 48) * razmer; //количество уникальных городов
		razmer = razmer / 10;
	}
	return unique_cities_len;
}
