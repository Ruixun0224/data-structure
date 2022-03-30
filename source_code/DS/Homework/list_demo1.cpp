//
// Created by yurui on 2022/3/30.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;


void InitSqList(SqList &L){
    srand((unsigned int )time(0));
    printf("input your list length\n");
    scanf("%d",&L.length);
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = rand() % 100;
    }
}

/**
 * 顺序表逆置问题
 * @param L
 */
void Reserve(SqList &L) {
    int temp;
    for (int i = 0, j = L.length - 1; i < j; ++i, --j) {
        temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;
    }
}

/**
 * 删除下标为i~j的所有元素
 * @param L
 * @param i
 * @param j
 */
void Delete(SqList &L, int i, int j) {
    int delta = j - i + 1;
    for (int k = j + 1; k < L.length; ++k) {
        L.data[k - delta] = L.data[k];
    }
    L.length -= delta;
}

/**
 * 打印顺序表
 * @param L
 */
void showList(SqList L) {
    printf("\n");
    for (int i = 0; i < L.length; ++i) {
        printf("%d\t", L.data[i]);
    }
    printf("\n");

}

/**
 * 将顺序表中比第一个元素小的放左边，大的放右边
 * @param L
 */
void move(SqList &L) {
    int temp;
    int i = 0, j = L.length - 1;
    temp = L.data[i];

    while (i < j) {
        while (i < j && L.data[j] > temp)
            --j;
        if (i < j) {
            L.data[i] = L.data[j];
        }
        while (i < j && L.data[i] < temp)
            ++i;
        if (i < j) {
            L.data[j] = L.data[i];
        }
    }

    L.data[i] = temp;
}

int main() {
//    SqList L1;
//    L1.data[0] = 1;
//    L1.data[1] = 2;
//    L1.data[2] = 3;
//    L1.data[3] = 4;
//    L1.data[4] = 5;
//    L1.length = 5;
//    printf("before\n");
//    showList(L1);
//
//    printf("after\n");
//    Reserve(L1);
//    showList(L1);

//    Delete(L1, 1, 3);
//    printf("delete after:\n");
//    showList(L1);
    SqList L;
    InitSqList(L);
    showList(L);
    move(L);
    showList(L);


    return 0;
}

