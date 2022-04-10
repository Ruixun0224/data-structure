//
// Created by yurui on 2022/4/10.
//
#include "stdio.h"
#include "stdlib.h"

/**
 * 链栈定义
 */
typedef struct LinkStack {
    int data;
    struct LinkStack *next;
} LinkStack;

/**
 * 初始化链栈
 * @param lst
 */
void InitStack(LinkStack *&lst) {
    lst = (LinkStack *) malloc(sizeof(LinkStack));
    lst->next = NULL;
}

/**
 * 判断栈是否为空
 * @param lst
 * @return
 */
int isEmpty(LinkStack *lst) {
    if (lst->next == NULL)
        return 1;
    else
        return 0;
}

/**
 * 进栈操作
 * @param lst
 * @param x
 */
void push(LinkStack *lst, int x) {
    LinkStack *p;
    p = (LinkStack *) malloc(sizeof(LinkStack));
    p->next = NULL;
    /**
     * 链表头插法代码
     */
    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

/**
 * 出栈操作
 * @param lst
 * @param x
 * @return
 */
int pop(LinkStack *lst, int &x) {
    LinkStack *p;
    if (lst->next == NULL)
        return 0;
    /**
     * 单链表删除操作
     */
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    return 1;
}

