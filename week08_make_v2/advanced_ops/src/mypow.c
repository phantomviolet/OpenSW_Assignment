#include "advanced_ops.h"

int mypow(int a, int b) {
    int res = a;
    for (int i  = 0; i < b - 1; i++) {
        res *= a;
    }

    return res;
}