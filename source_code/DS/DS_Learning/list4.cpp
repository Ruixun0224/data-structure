//
// Created by yurui on 2022/3/29.
//循环链表
//
#include "stdlib.h"

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 初始化循环单链表
 * @param L
 * @return
 */
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = L;
    return true;
}

/**
 * 循环链表判断空
 * @param L
 * @return
 */
bool Empty(LinkList L) {
    if (L->next = L)
        return true;
    else
        return false;
}

/**
 * 判断p节点是否为链表最后一个节点
 * @param L
 * @param p
 * @return
 */
bool isTail(LinkList L, LNode *p) {
    if (p->next == L)
        return true;
    else
        return false;
}

/**
 * 初始化循环双链表
 * @param L
 * @return
 */
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

/**
 * 双链表判空
 * @param L
 * @return
 */
bool EmptyDL(DLinkList L) {
    if (L->next == L)
        return true;
    else
        return false;
}