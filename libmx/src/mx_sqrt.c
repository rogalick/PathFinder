#include"libmx.h"

int mx_sqrt(int x) {
    double result = 0;
    double x1 = x;
    while(result * result != x1) {
        if(result * result > x1) {
            return 0;
        }
        result++;
    }
    int result1 = (int) result;
    return result1;
}
