//
// Created by yurui on 2022/3/30.
//
#include "stdio.h"
#include "stdlib.h"

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 显示链表
 * @param L
 */
void showList(LinkList L) {
    LNode *p;
    p = L->next;
    printf("\n");
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 初始化链表
 * @param L
 */
void InitLinkList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
}

/**
 * 删除递增且非空链表中的重复元素
 * 如{1,1,2,3,4,5,5,6,7,7,8}->{1,2,3,4,5,6,7,8}
 * 第一种做法
 * @param L
 */
void deleteRepeat1(LinkList &L) {
    LNode *p = L->next, *q;
    while (p->next != NULL) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else
            p = p->next;
    }
}

/**
 * 第二种做法
 * @param L
 */
void deleteRepeat2(LinkList &L) {
    LNode *p, *q, *r;
    p = L->next;
    q = L->next->next;
    while (q != NULL) {
        while (q != NULL && q->data == p->data) {
            q = q->next;
        }
        if (q != NULL) {
            p = p->next;
            p->data = q->data;
        }
    }
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q;
        q = q->next;
        free(r);
    }

}


/**
 * 尾插法实现链表
 * @param L
 * @return
 */
LinkList TailInsert(LinkList &L) {
    int x;
    L = (LNode *) malloc(sizeof(LNode));
    LNode *s, *r = L;
    printf("input numbers you want to insert 100 end\n");
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
 * 删除单链表中最小的节点
 * @param L
 */
void deleteMinNode(LinkList &L) {
    LNode *pre = L, *p = pre->next;
    LNode *minp = p, *minpre = pre;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}


int main() {
    LinkList L;
    InitLinkList(L);
    TailInsert(L);
    showList(L);
    deleteMinNode(L);
    showList(L);
}