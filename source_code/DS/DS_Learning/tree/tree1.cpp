//
// Created by ruixun on 2022/4/19.
//
#include "stdio.h"

#define MAXSIZE 10

typedef struct DNode {
    int data;
    struct DNode *next;
} DNode;

typedef struct LinkNode {
    DNode *front, *rear;
} LinkNode;

typedef struct {
    int data[MAXSIZE];
    int top;
} Stack;
/**
 * 二叉树的链式存储
 */
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * 访问节点操作
 * @param T
 */
void visit(BiTree T) {
    printf("lchild is %d", T->lchild->data);
    printf("rchild is %d", T->rchild->data);
}

/**
 * 先序遍历
 * @param T
 */
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/**
 * 中序遍历
 * @param T
 */
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

/**
 * 后序遍历
 * @param T
 */
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        PostOrder(T);
    }
}

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
bool Push(Stack &st, int x) {
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
bool Pop(Stack &st, int &x) {
    if (st.top == -1)
        return false;
    else {
        x = st.data[st.top--];
        return true;
    }
}

