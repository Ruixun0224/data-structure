//
// Created by yurui on 2022/4/10.
//
#include "stdlib.h"

/**
 * 队结点定义
 */
typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

/**
 * 链队定义
 */
typedef struct {
    QNode *front;
    QNode *rear;
} LiQueue;

/**
 * 初始化链队
 * @param Q
 */
void InitQueue(LiQueue &Q) {
    Q.front = Q.rear = (QNode *) malloc(sizeof(QNode));
    Q.front->next = NULL;
}

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
bool QueueEmpty(LiQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

/**
 * 新元素入队操作
 * @param Q
 * @param x
 */
void EnQueue(LiQueue &Q, int x) {
    QNode *s = (QNode *) malloc(sizeof(QNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

/**
 * 出队操作
 * @param Q
 * @param x
 * @return
 */
bool DeQueue(LiQueue &Q, int &x) {
    if(Q.front == Q.rear)
        return false;
    QNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}