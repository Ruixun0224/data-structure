//
// Created by ruixun on 2022/4/24.
//

#ifndef C_PROJECT_COMMON_H
#define C_PROJECT_COMMON_H

#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 10
#define MAX_TREE_SIZE 100
#define SIZE 100

/**
 * 集合元素数组（双亲指针数组）
 */
int UFSets[SIZE];

/**
 * 二叉树的链式存储
 */
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * 栈定义
 */
typedef struct {
    BiTree data[MAXSIZE];
    int top;
} Stack;

/**
 * 队列结点
 */
typedef struct LinkNode {
    BiTree data;
    struct LinkNode *next;
} LinkNode;

/**
 * 链队定义
 */
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

/**
 * 线索二叉树结构
 */
typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

/**
 * 双亲表示法结构
 */
typedef struct {
    int data;
    int parent;
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
} PTree;

/**
 * 初始化栈
 * @param st
 */
void InitStack(Stack &st) {
    st.top = -1;
}

/**
 * 进栈操作
 * @param st
 * @param x
 * @return
 */
bool Push(Stack &st, BiTree x) {
    if (st.top == MAXSIZE - 1)
        return false;
    else {
        st.data[++st.top] = x;
        return true;
    }
}

/**
 * 出栈操作
 * @param st
 * @param x
 * @return
 */
bool Pop(Stack &st, BiTree &x) {
    if (st.top == -1)
        return false;
    else {
        x = st.data[st.top--];
        return true;
    }
}

/**
 * 判断栈是否为空
 * @param s
 * @return
 */
bool IsEmptyStack(Stack s) {
    if (s.top == -1)
        return true;
    else
        return false;
}

bool GetTop(Stack st, BiTree &x) {
    if (st.top == -1)
        return false;
    else {
        x = st.data[st.top--];
        return true;
    }
}

/**
 * 初始化队列
 * @param Q
 */
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
bool IsEmptyQueue(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

/**
 * 入队
 * @param Q
 * @param x
 */
void EnQueue(LinkQueue &Q, BiTree x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

/**
 * 出队
 * @param Q
 * @param x
 * @return
 */
bool DeQueue(LinkQueue &Q, BiTree &x) {
    if (Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

/**
 * 访问节点操作
 * @param T
 */
void visit(BiTree T) {
    printf("now is %d\n", T->data);
    printf("lchild is %d\n", T->lchild->data);
    printf("rchild is %d\n", T->rchild->data);
}


#endif //C_PROJECT_COMMON_H
