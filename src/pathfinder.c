#include "pathfinder.h"
int mx_isalpha(char a);
int mx_atoi(const char *s);
int valid(int ar,char const *argv2[]);
int valid_2(char const *argv2[]);
int mx_unique_len(char *stroka);
int **mx_matrix(int unique_cities_len, int matrix[unique_cities_len][unique_cities_len], char *stroka2, char *unique_cities[unique_cities_len]);
char **mx_cities(char *stroka,int unique_cities_len, char *unique_cities[unique_cities_len]);
int output(int unique_cities_len,int matrix[unique_cities_len][unique_cities_len],int matrix_path[unique_cities_len][unique_cities_len], char **unique_cities);
	int main(int argc, char const *argv[]){
	if (valid(argc,argv) == 0)
	{
		exit(1);
	}
    char *stroka =mx_file_to_str(argv[1]);
    char *stroka2 =mx_file_to_str(argv[1]);
	if(valid_2(argv) == 0){
		exit(1);
	}
 	int unique_cities_len = mx_unique_len(stroka);
 	char *unique_cities[unique_cities_len];
 	mx_cities(stroka,unique_cities_len,unique_cities);
	int matrix[unique_cities_len][unique_cities_len];
	mx_matrix(unique_cities_len, matrix, stroka2, unique_cities);
	int matrix_path[unique_cities_len][unique_cities_len];
	 for (int i = 0; i < unique_cities_len ; ++i)
	{
		for (int p = 0; p < unique_cities_len ; ++p)
		{
			matrix_path[i][p] = 0;
		}
	}
	for (int k = 0; k < unique_cities_len; ++k)
	{
		for (int j = 0; j <unique_cities_len; ++j)
		{
			for (int i = 0; i < unique_cities_len; ++i)
			{
				if (matrix[i][j] >= matrix[i][k] + matrix[k][j] && matrix[i][j] != 0 && matrix[i][k]!= 0 && matrix[k][j] != 0 )
    			{ 
     				matrix[i][j] = matrix[i][k] + matrix[k][j];
     				matrix_path[i][j] = k;
    			}
			}
		}
	}
	output(unique_cities_len, matrix, matrix_path, unique_cities);
}
