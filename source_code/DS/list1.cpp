//
// Created by yurui on 2022/3/28.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 10
#define InitSize 10

typedef struct {
    int data[MAXSIZE];
    int length;
} Sqlist;

typedef struct {
    int *data;
    int MaxSize;
    int length;
} Seqlist;

/**
 * 第一种初始化顺序表的方式，直接令length=0
 * @param L
 */
void InitList1(Sqlist &L) {
    L.length = 0;
}

/**
 * 第二种动态实现顺序表的方式
 * @param L
 */
void InitList2(Seqlist &L) {
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.MaxSize = InitSize;
    L.length = 0;
}

/**
 * 动态增加表中元素数量
 * @param L 顺序表
 * @param len 增加长度
 */
void IncreaseSize(Seqlist &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

/**
 * 插入操作 注意插入时前一个值赋给后一个
 * @param L 插入的顺序表
 * @param i 插入的位序 注意与数组下标关系
 * @param e 插入的值
 * @return
 */
bool InsertList(Sqlist &L, int i, int e) {
    if (i < 1 || i > L.length - 1 || L.length >= MAXSIZE)
        return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/**
 * 删除操作 删除时后一个赋给前一个
 * @param L 顺序表
 * @param i 删除的位序
 * @param e 删除的值带出来
 * @return
 */
bool DeleteList(Sqlist &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

/**
 * 按位查找
 * @param L
 * @param i 位序
 * @return 查到的值
 */
int GetElem(Sqlist L, int i) {
    return L.data[i - 1];
}

/**
 * 按值查找
 * @param L
 * @param e 值
 * @return 查到的位序
 */
int LocateElem(Sqlist L, int e){
    for (int i = 0; i < L.length; ++i) {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}

int main() {
    Sqlist L;
    InitList1(L);
    for (int i = 0; i < 5; ++i) {
        L.data[i] = rand();
        L.length = 5;
    }
    printf("------------------\n");
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]:%d\n", i, L.data[i]);
    }
    printf("------------------\n");
    InsertList(L, 2, 10086);
    printf("------------------\n");
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]:%d\n", i, L.data[i]);
    }
    printf("------------------\n");
    int e = -1;
    if (DeleteList(L, 3, e))
        printf("delete:%d\n", e);
    else
        return -1;
    printf("------------------\n");
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]:%d\n", i, L.data[i]);
    }
    printf("------------------\n");


    return 0;

}