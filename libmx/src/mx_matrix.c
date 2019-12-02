#include "libmx.h"
int mx_atoi(const char *s);
int **mx_matrix(int unique_cities_len, int matrix[unique_cities_len][unique_cities_len], char *stroka2, char *unique_cities[unique_cities_len]){
	for (int i = 0; i < unique_cities_len ; ++i)
	{
		for (int p = 0; p < unique_cities_len ; ++p)
		{
			matrix[i][p] = 1000000;
			if (i == p)
			{
				matrix[i][p] = 0;
			}
			
		}
		
	}

	
	int road = 0;
	char charm[50];
	int g = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; stroka2[i] != '\0'; ++i)
	{
		if( i > 4 && stroka2[i] > 47 && stroka2[i] <58){

			int razmer2 = 0;
			for ( g = i; stroka2[g] > 47 && stroka2[g] < 58; ++g)
			{
				charm[razmer2] = stroka2[g];
				razmer2++;
			}
			if(razmer2 == 1){
				road = stroka2[i] - 48;
			}
			else{
				road =mx_atoi(charm);

			}
			i = i + razmer2;
		}
		//===============================нахождение пути================================
		if ((stroka2[i] > 64 && stroka2[i] < 91) || (stroka2[i] > 97 && stroka2[i] < 123))
		{
			int j = 0;
			int lenght1 = 0;
			for (j = i;stroka2[j] != '-' && stroka2[j] != ','; ++j)
			{
				lenght1++;
			}
			char *str1 = mx_strnew(lenght1);
			int x1 = 0;
			for (j = i;stroka2[j] != '-' && stroka2[j] != ','; ++j)
			{
				str1[x1] = stroka2[j];
				x1++;
			}
			int j2 = j + 1;
			int lenght2 = 0;
			for (; stroka2[j2]!= ','; ++j2)
			{
				lenght2++;
			}
			char *str2 = mx_strnew(lenght2);
			int x2 = 0;
			for (j2 = j + 1;stroka2[j2] != ','; ++j2)
			{
				str2[x2] = stroka2[j2];
				++x2;
			}
			//========================================нахождение двух слов================================
			
			for (int h = 0; h < unique_cities_len; ++h)
			{
				if (mx_strcmp(unique_cities[h],str1) == 0)
				{
					x = h;
				}
			}
			for (int h = 0; h < unique_cities_len; ++h)
			{
				if (mx_strcmp(unique_cities[h],str2) == 0)
				{
					y = h;
				}
				
			}
			i = i + lenght2 + lenght1;


		}
		matrix[x][y] = road;
		matrix[y][x] = road;

		
	}
	return (int**)matrix;
}
