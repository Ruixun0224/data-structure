//
// Created by ruixun on 2022/4/19.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 10


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

//声明全局变量
Stack s;

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

typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

/**
 * 访问节点操作
 * @param T
 */
void visit(BiTree T) {
    printf("now is %d\n", T->data);
    printf("lchild is %d\n", T->lchild->data);
    printf("rchild is %d\n", T->rchild->data);
}

/**
 * 先序遍历递归算法
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
 * 中序遍历递归算法
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
 * 后序遍历递归算法
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
 * 中序遍历的非递归算法
 * @param T
 */
void InOrder2(BiTree T) {
    InitStack(s);
    BiTree p = T;
    while (p || !IsEmptyStack(s)) {
        if (p) {
            Push(s, p);
            p = p->lchild;
        } else {
            Pop(s, p);
            visit(p);
            p = p->rchild;
        }
    }
}

/**
 * 先序遍历的非递归算法
 * @param T
 */
void PreOrder2(BiTree T) {
    InitStack(s);
    BiTree p = T;
    while (p || !IsEmptyStack(s)) {
        if (p) {
            visit(p);
            Push(s, p);
            p = p->lchild;
        } else {
            Pop(s, p);
            p = p->rchild;
        }
    }
}

/**
 * 后序遍历的非递归算法
 * @param T
 */
void PostOrder2(BiTree T) {
    InitStack(s);
    BiTree p = T, r = NULL;
    while (p || !IsEmptyStack(s)) {
        if (p) {
            Push(s, p);
            p = p->lchild;
        } else {
            GetTop(s, p);
            if (p->rchild && p->lchild != r)
                p = p->rchild;
            else {
                Pop(s, p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}

/**
 * 层次遍历
 * @param T
 */
void LevelOrder(BiTree T) {
    LinkQueue q;
    InitQueue(q);
    BiTree p;
    EnQueue(q, T);
    while (!IsEmptyQueue(q)) {
        DeQueue(q, p);
        visit(p);
        if (p->lchild != NULL)
            EnQueue(q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(q, p->rchild);
    }
}

/**
 * 中序遍历对二叉树的线索化递归算法
 * @param p
 * @param pre
 */
void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

/**
 * 中序遍历建立中序线索二叉树
 * @param T
 */
void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/**
 * 中序线索二叉树中序序列下第一个结点
 * @param p
 * @return
 */
ThreadNode *FirstNode(ThreadNode *p) {
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

/**
 * 中序线索二叉树中结点p在中序序列下的后继
 * @param p
 * @return
 */
ThreadNode *NextNode(ThreadNode *p) {
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}