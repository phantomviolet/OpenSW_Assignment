#include "myops.h"

double mypow(double a, double b) {
    double res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }

    return res;
}