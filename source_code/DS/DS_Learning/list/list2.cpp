//
// Created by yurui on 2022/3/28.
//单链表
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

/**
 * 删除链表指定位置的值 e带出
 * @param L
 * @param i
 * @param e
 * @return
 */
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

/**
 * 按位查找
 * @param L
 * @param i
 * @return
 */
LNode *GetElem(LinkList L, int i) {
    if (i < 0)
        return NULL;
    LNode *p;
    p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查找
 * @param L
 * @param e
 * @return
 */
LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

/**
 * 尾插法实现单链表
 * @param L
 * @return
 */
LinkList TailInsert(LinkList &L) {
    int x;
    L = (LNode *) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 100) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

/**
 * 头插法实现单链表（逆置问题）
 * @param L
 * @return
 */
LinkList HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 100) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;

}
