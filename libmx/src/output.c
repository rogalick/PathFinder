 #include "libmx.h"
void mx_road_to_globalelte(int i, int j, int unique_cities_len, char *unique_cities[unique_cities_len], int matrix_path[unique_cities_len][unique_cities_len], int way[unique_cities_len], int matrix[unique_cities_len][unique_cities_len]);
int *mx_road_to_globalelite(int i, int j, int unique_cities_len, char *unique_cities[unique_cities_len], int matrix_path[unique_cities_len][unique_cities_len], int way[unique_cities_len], int matrix[unique_cities_len][unique_cities_len]);
void output(int unique_cities_len,int matrix[unique_cities_len][unique_cities_len],int matrix_path[unique_cities_len][unique_cities_len],char **unique_cities){
	for (int i = 0; i < unique_cities_len; ++i)
	{
		for (int j = i + 1; j < unique_cities_len; ++j)
		{
			mx_printstr("========================================$\nPath : ");
			mx_printstr(unique_cities[i]);
			mx_printstr(" -> ");
			mx_printstr(unique_cities[j]);
			mx_printstr("\nRoute : ");
			if (matrix_path[i][j] != 0)
			{
				mx_printstr(unique_cities[i]);
				mx_printstr(" -> ");
				int buf = 1;
				int jj = j;
				int buff = 0;
				int matrix_distance[unique_cities_len];
				int matrix_way[unique_cities_len];
				for (int i = 0; i < unique_cities_len; ++i)
				{
					matrix_distance[i] = 0;
				}
				while(matrix_path[i][jj] > 0){
						buf = matrix_path[i][jj];
						matrix_distance[buff] = matrix[jj][buf];
						matrix_way[buff] =buf;
						jj = buf;
						buff++;
				}
				buff--;
				for (;buff > -1; --buff)
				{
					int qq = matrix_way[buff];
				
					mx_printstr(unique_cities[qq]);
					mx_printstr(" -> ");
				}
				mx_printstr(unique_cities[j]);
				mx_printstr("\nDistance: ");
				int way[unique_cities_len];
				for(int i = 0; i < unique_cities_len; i++){
					way[i] = 0;
				}
				mx_road_to_globalelte(i, j, unique_cities_len, unique_cities, matrix_path, way, matrix);
				mx_printstr(" = ");
				mx_printint(matrix[i][j]);
				mx_printchar('\n');
				mx_printstr("========================================$\n");
			}
			else{
				mx_printstr(unique_cities[i]);
				mx_printstr(" -> ");
				mx_printstr(unique_cities[j]);
				mx_printstr("\nDistance: ");
				mx_printint(matrix[i][j]);
				mx_printchar('\n');
				mx_printstr("========================================$\n");
			}
			
		}
	}

	
}
