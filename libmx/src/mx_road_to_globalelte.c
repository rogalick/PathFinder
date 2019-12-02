#include "libmx.h"

int *mx_road_to_globalelite(int i, int j, int unique_cities_len, char *unique_cities[unique_cities_len], int matrix_path[unique_cities_len][unique_cities_len], int way[unique_cities_len], int matrix[unique_cities_len][unique_cities_len]);
void mx_road_to_globalelte(int i, int j, int unique_cities_len, char *unique_cities[unique_cities_len], int matrix_path[unique_cities_len][unique_cities_len], int way[unique_cities_len], int matrix[unique_cities_len][unique_cities_len]) {
	int way2[unique_cities_len];
	way[0] = 2;
	for (int i = 0; i < unique_cities_len; ++i)
	{
		way2[i] = 0;
	}
	int* way1 = mx_road_to_globalelite(i, j, unique_cities_len, unique_cities, matrix_path, way2, matrix);
	int chto = way1[0];
	int ind = 0;
	mx_printint(matrix[i][chto]);
	mx_printstr(" + ");
	for(; way1[ind + 1] != 0; ind++) {
		int past = way1[ind];
		int new = way1[ind + 1];
		mx_printint (matrix[past][new]);
		mx_printstr(" + ");
	}
	int index1 = way1[ind];
	chto = way1[ind];
	mx_printint(matrix[index1][j]);
}
