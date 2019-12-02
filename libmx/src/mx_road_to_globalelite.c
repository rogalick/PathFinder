#include "libmx.h"

int *mx_road_to_globalelite(int i, int j, int unique_cities_len, char *unique_cities[unique_cities_len], int matrix_path[unique_cities_len][unique_cities_len], int way[unique_cities_len], int matrix[unique_cities_len][unique_cities_len]) {
	int index = 0;
	int g = matrix_path[i][j];
	if(matrix_path[i][j] != 0 && matrix_path[i][g] != 0) {
		index++;
		mx_road_to_globalelite(i, g, unique_cities_len, unique_cities, matrix_path, way, matrix);
	}
	way[index] = g;
	return way;
}
