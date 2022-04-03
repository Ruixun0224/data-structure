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


void InitSqList(SqList &L) {
    srand((unsigned int) time(0));
    printf("input your list length\n");
    scanf("%d", &L.length);
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = rand() % 100;
    }
}

/**
 * 顺序表逆置问题
 * @param L
 */
void Reverse1(SqList &L) {
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


/**
 * 数组倒置代码RCR用
 * @param R
 * @param l
 * @param r
 */
void Reverse(int R[], int l, int r) {
    int i, j;
    int temp;
    for (int i = l, j = r; i < j; ++i, --j) {
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
}

/**
 * 将数组循环左移p个单位后
 * 思想为前p个元素逆置，再将剩余元素逆置，最后将整张表逆置
 * @param R
 * @param n 数组长度
 * @param p 前p个元素
 */
void RCR(int R[], int n, int p) {
    if (p <= 0 || p >= n) {
        printf("error p\n");
        exit(0);
    } else {
        Reverse(R, 0, p - 1);
        Reverse(R, p, n - 1);
        Reverse(R, 0, n - 1);
    }
}

/**
 * 判断主元素题，若一个元素在数组中出现的次数>2/n 则称其为数组的主元素
 * @param A
 * @param n 长度
 * @return
 */
int majority(int A[], int n) {
    int c, count = 1;
    c = A[0];
    for (int i = 0; i < n; ++i) {
        if (A[i] == c)
            count++;
        else {
            if (count > 0) {
                count--;
            } else {
                c = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == c)
                count++;
        }
    }
    if (count > n / 2)
        return c;
    else
        return -1;
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
//    SqList L;
//    InitSqList(L);
//    showList(L);
//    move(L);
//    showList(L);
    int n;
    printf("input the count of array:\n");
    scanf("%d", &n);
    int R[n];
    srand(time(NULL));
    int a;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a);
        R[i] = a;
    }
    printf("before\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t", R[i]);
    }
    printf("\n");
//    RCR(R, n, 5);
//    printf("after\n");
//    for (int i = 0; i < n; ++i) {
//        printf("%d\t", R[i]);
//    }
//    printf("\n");
    int c = majority(R,n);
    printf("result is %d\n",c);
    return 0;
}

