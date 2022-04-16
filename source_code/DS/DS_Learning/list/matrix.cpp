//
// Created by ruixun on 2022/4/16.
//


#include "stdio.h"

#define MAXSIZE 10

typedef struct {
    int val;
    int i, j;
} TriMat;

/**
 * 三元组稀疏矩阵，wrong test
 * @param A
 * @param m
 * @param n
 * @param B
 */
void createTriMat(int A[][MAXSIZE], int m, int n, int B[][MAXSIZE]) {
    int k = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                B[k][0] = A[i][j];
                B[k][1] = i;
                B[k][2] = j;
                ++k;
            }
        }
    }
    B[0][0] = k - 1;
    B[0][1] = m;
    B[0][2] = n;
}

/**
 * 打印 wrong test
 * @param B
 */
void print(int B[][MAXSIZE]){
    int k = 1;
    for (int i = 0; i < B[0][1]; ++i) {
        for (int j = 0; j < B[0][2]; ++j) {
            if(i == B[k][1] && j==B[k][2]){
                printf("%d",B[k][0]);
                ++k;
            } else
                printf("%d",0);
        }
        printf("\n");
    }
}

void test01(){
    int A[10][10];
    int B[10][10];
    createTriMat(A, 5, 4, B);
    print(B);
}

int main(){
    test01();
    return 0;
}