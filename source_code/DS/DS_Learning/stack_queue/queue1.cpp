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
} SqQueue;

/**
 * 初始化队列，头尾指向第一个位置
 * @param Sq
 */
void InitSqQueue(SqQueue &Sq) {
    Sq.front = Sq.rear = 0;
}

/**
 * 判断队列是否为空
 * @param Sq
 * @return
 */
bool QueueEmpty(SqQueue Sq) {
    if (Sq.rear == Sq.front)
        return true;
    else
        return false;
}

/**
 * 入队操作
 * @param Sq
 * @param x
 * @return
 */
bool EnQueue(SqQueue &Sq, int x) {
    //判断队列中的元素是否已满
    //浪费一个数据元素
    if ((Sq.rear + 1) % MAXSIZE == Sq.front)
        return false;
    Sq.data[Sq.rear] = x;
    Sq.rear = (Sq.rear + 1) % MAXSIZE;
    return true;
}

/**
 * 出队操作
 * @param Sq
 * @param x
 * @return
 */
bool DeQueue(SqQueue &Sq, int &x) {
    if (Sq.rear == Sq.front)
        return false;
    x = Sq.data[Sq.front];
    Sq.front = (Sq.front + 1) % MAXSIZE;
    return true;
}

/**
 * 取出队头的元素
 * @param Sq
 * @param x
 * @return
 */
bool GetHead(SqQueue Sq, int &x) {
    if (Sq.rear == Sq.front)
        return false;
    x = Sq.data[Sq.front];
    return true;
}