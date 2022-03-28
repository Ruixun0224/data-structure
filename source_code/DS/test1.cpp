//
// Created by yurui on 2022/3/27.
//

#include "stdio.h"
#include "time.h"
#include "math.h"

clock_t start, end;
double duration;
#define MAXK 10000
#define MAXN 10



double f1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = 0; i <= n; i++) {
        p += (a[i] * pow(x, i));
    }
    return p;
}

double f2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for (i = n; i > 0; i--) {
        p = a[i - 1] + x * p;
    }
    return p;
}

int main() {
    int i;
    double a[MAXN];
    for (i = 0; i < MAXN; i++) {
        a[i] = (double) i;
    }

    start = clock();
    for (i = 0; i < 10000; i++) {
        f1(MAXN - 1, a, 1.1);
    }
    end = clock();
    duration = ((double) (end - start)) / CLK_TCK / MAXK;
    printf("duration1 = %6.2e\n", duration);
    printf("ticks1=%f\n", (double) (end - start));

    start = clock();
    for (i = 0; i < 10000; i++) {
        f2(MAXN - 1, a, 1.1);
    }
    end = clock();
    duration = ((double) (end - start)) / CLK_TCK / MAXK;
    printf("duration2 = %6.2e\n", duration);
    printf("ticks2=%f\n", (double) (end - start));

}
