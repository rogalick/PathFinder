#include "libmx.h"

int mx_strlen(const char *s);

int mx_quicksort(char **arr, int left, int right) {
	if(!arr) {
		return -1;
	}
	int count = 0;
    if (left < right) {
        int l = left, r = right;
		char *middle = arr[left / 2 + right / 2];
        while(l < r) {
            while (mx_strlen(arr[l]) < mx_strlen(middle)) l++;
            while (mx_strlen(arr[r]) > mx_strlen(middle)) r--;
            if (l < r) {
				count++;
                char *tmp = arr[l];
                arr[l] = arr[r];
                arr[r] = tmp;
                l++;
                r--;
            }
        }
        count += mx_quicksort(arr, left, r);
        count += mx_quicksort(arr, right, l);
    }
	return count;
}
