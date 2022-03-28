//
// Created by yurui on 2022/3/28.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

/**
 * 不带头节点
 * @param L
 * @return
 */
bool InitList1(LinkList &L){
    L = NULL;
    return true;
}
/**
 * 判断是否为空
 * @param L
 * @return
 */
bool Empty1(LinkList L){
    return (L==NULL);
}
/**
 * 带头结点单链表
 * @param L
 * @return
 */
bool InitList2(LinkList &L){
    L=(LNode*) malloc(sizeof (LNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}
/**
 * 带头节点单链表
 * @param L
 * @return
 */
bool Empty2(LinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}