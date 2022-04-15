//
// Created by yurui on 2022/3/30.
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct LNode1 {
    char data;
    struct LNode1 *next;
} LNode1, *LinkList1;

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
 * 显示链表
 * @param L
 */
void showList1(LinkList1 L) {
    LNode1 *p;
    p = L->next;
    printf("\n");
    while (p != NULL) {
        printf("%c\t", p->data);
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

/**
 * 头插法实现单链表逆置
 * @param L
 */
void reserveL(LinkList &L) {
    LNode *p = L->next, *q;
    L->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

/**
 * 使得链表A中数据域奇数停留在A中，偶数停留在B中
 * @param A
 * @param B
 */
void spilt(LinkList &A, LinkList &B) {
    LNode *p, *q, *r;
    B = (LNode *) malloc(sizeof(LNode));
    B->next = NULL;
    r = B;
    p = A;
    while (p->next != NULL) {
        if (p->next->data % 2 == 0) {
            q = p->next;
            p->next = q->next;
            q->next = NULL;
            r->next = q;
            r = q;
        } else
            p = p->next;
    }
}

/**
 * 逆序打印单链表中数据元素
 * @param L
 */
void reprint(LinkList L) {
    if (L != NULL) {
        reprint(L->next);
        printf("%d\t", L->data);
    }
}

/**
 * 判断两个集合是否相等，相等返回1，不等返回0
 * @param A
 * @param B
 * @return
 */
int isEqual(LinkList A, LinkList B) {
    LNode *p = A->next;
    LNode *q = B->next;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else
            return 0;
    }
    if (p != NULL || q != NULL)
        return 0;
    else
        return 1;
}

/**
 * 键盘读入一个数，在单链表中创建n个单词不重复的录入单链表中
 * 有bug，不能完整输出，不知道原因
 * @param L
 */
void createLinkNoSameElem(LinkList1 &L) {
    L = (LNode1 *) malloc(sizeof(LNode1));
    L->next = NULL;
    LNode1 *p;
    int n;
    printf("input the count of your char\n");
    scanf("%d", &n);
    char ch;
    printf("input your char\n");
    for (int i = 0; i < n; ++i) {
        ch = getchar();
        p = L->next;
        while (p != NULL) {
            if (p->data == ch)
                break;
            p = p->next;
        }
        if (p == NULL) {
            p = (LNode1 *) malloc(sizeof(LNode1));
            p->data = ch;
            p->next = L->next;
            L->next = p;
        }
    }
}

/**
 * 找到单链表中倒数第k个节点，若有，返回k值return1，若没有，return0
 * @param L
 * @param k
 * @return
 */
int findElem(LinkList L, int k) {
    LNode *p1, *p;
    p1 = L->next;
    p = L;
    int i = 1;
    while (p1 != NULL) {
        p1 = p1->next;
        i++;
        if (i > k)
            p = p->next;
    }
    if (p == L)
        return 0;
    else {
        printf("%d\n", p->data);
        return 1;
    }

}



int main() {
//    LinkList1 L1;
    LinkList L;
    InitLinkList(L);
    TailInsert(L);
//    TailInsert(L1);
//    spilt(L, L1);
//    showList(L);
//    showList(L1);
//    showList(L);
//    showList(L1);
//    printf("%d", isEqual(L,L1));
//    createLinkNoSameElem(L1);
//    showList1(L1);
    findElem(L, 1);

    return 0;
}