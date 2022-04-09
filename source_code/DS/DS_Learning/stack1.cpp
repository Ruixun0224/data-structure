//
// Created by yurui on 2022/4/9.
//
#include "stdio.h"

#define MAXSIZE 100

//顺序栈
typedef struct {
    int data[MAXSIZE];
    int top;
} SqStack;

//共享栈
typedef struct {
    int data[MAXSIZE];
    int top0;
    int top1;
} ShStack;

/**
 * 初始化顺序栈
 * @param S
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * 判断栈是否为空
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}

/**
 * 向顺序栈中添加一个元素
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S, int x) {
    if (S.top == MAXSIZE - 1)
        return false;
    S.top += 1;
    S.data[S.top] = x;
    //必须是++top
    //S.data[++S.top] = x;
    return true;
}

/**
 * 出栈操作
 * @param S
 * @param x
 * @return
 */
bool Pop(SqStack &S, int &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    S.top -= 1;
    //必须是top--
    //x = S.data[S.top--];
    return true;
}

/**
 * 读栈顶操作
 * @param S
 * @param x
 * @return
 */
bool GetTop(SqStack &S, int &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

/**
 * 初始化共享栈
 * @param S
 */
void InitShStack(ShStack &S) {
    S.top0 = -1;
    S.top1 = MAXSIZE;
}

/**
 * 判断共享栈是否存满
 * @param S
 * @return
 */
bool EmptyShStack(ShStack S){
    if(S.top0 + 1 == S.top1)
        return true;
    else
        return false;
}






