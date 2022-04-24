//
// Created by ruixun on 2022/4/24.
//
#include "common.h"

/**
 * 自下向上，自右向左遍历
 * @param bt
 */
void InvertLevel(BiTree bt) {
    Stack s;
    LinkQueue q;
    BiTree p;
    if (bt != NULL) {
        InitStack(s);
        InitQueue(q);
        EnQueue(q, bt);
        while (!IsEmptyQueue(q)) {
            DeQueue(q, p);
            Push(s, p);
            if (p->lchild)
                EnQueue(q, p->lchild);
            if (p->rchild)
                EnQueue(q, p->rchild);
        }
        while (!IsEmptyStack(s)) {
            Pop(s, p);
            visit(p);
        }
    }
}

/**
 * 用二叉链表实现树的深度的求解
 * @param T
 * @return
 */
int BtDepth(BiTree T){
    if(!T)
        return 0;
    int front = -1,rear = -1;
    int last = 0,level = 0;
    BiTree Q[MAXSIZE];
    Q[++rear] = T;
    BiTree p;
    while (front<rear){
        p = Q[++front];
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        if(front == last){
            level++;
            last = rear;
        }
    }
    return level;
}
