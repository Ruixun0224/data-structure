//
// Created by yurui on 2022/4/10.
//

/**
 * 队结点定义
 */
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

/**
 * 链队定义
 */
typedef struct {
    QNode *front;
    QNode *rear;
}LiQueue;

