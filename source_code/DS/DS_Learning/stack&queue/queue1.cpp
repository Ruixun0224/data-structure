//
// Created by yurui on 2022/4/10.
//
#define MAXSIZE 100

/**
 * 顺序队列
 */
typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

