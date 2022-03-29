//
// Created by yurui on 2022/3/29.
//双链表
//
#include "stdio.h"
#include "stdlib.h"

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 双链表初始化
 * @param L
 * @return
 */
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

/**
 * 判断是否为空
 * @param L
 * @return
 */
bool Empty(DLinkList L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}

/**
 * p节点后插入s节点
 * @param p
 * @param s
 * @return
 */
bool DLinkListInsert(DNode *p, DNode *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
}


/**
 * 删除p节点之后的节点
 * @param p
 * @return
 */
bool DLinkListDelete(DNode *p) {
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}