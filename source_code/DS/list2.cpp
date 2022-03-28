//
// Created by yurui on 2022/3/28.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 不带头节点
 * @param L
 * @return
 */
bool InitList1(LinkList &L) {
    L = NULL;
    return true;
}

/**
 * 判断是否为空
 * @param L
 * @return
 */
bool Empty1(LinkList L) {
    return (L == NULL);
}

/**
 * 带头结点单链表
 * @param L
 * @return
 */
bool InitList2(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

/**
 * 带头节点单链表
 * @param L
 * @return
 */
bool Empty2(LinkList L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}

/**
 * 单链表带头结点插入
 * @param L
 * @param i 指定位置
 * @param e 指定元素
 * @return
 */
bool InsertList1(LinkList &L, int i, int e) {
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 带头结点插入
 * @param L
 * @param i
 * @param e
 * @return
 */
bool InsertList2(LinkList &L, int i, int e) {
    if (i < 1)
        return false;
    if (i == 1) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }

    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 前插操作，在p结点之前插入e，因为链表中前面结点信息未知，所插入后面然后修改前一个值
 * @param p
 * @param e
 * @return
 */
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool DeleteList(LinkList &L, int i, int &e) {
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}