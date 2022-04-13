//
// Created by ruixun on 2022/4/13.
//

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int top;
} SqStack;

bool isEmpty(SqStack &s2);

bool pop(SqStack &st, int &x);

bool push(SqStack &st, int x);

/**
 * 入队操作
 * @param s1
 * @param s2
 * @param x
 * @return
 */
bool enQueue(SqStack &s1, SqStack &s2, int x) {
    int y;
    if (s1.top == MAXSIZE - 1) {
        if (!isEmpty(s2))
            return false;
        else if (isEmpty(s2)) {
            pop(s1, y);
            push(s2, y);
        }
        push(s1, x);
        return true;
    } else {
        push(s1, x);
        return true;
    }
}

/**
 * 出队操作
 * @param s1
 * @param s2
 * @param x
 * @return
 */
bool deQueue(SqStack &s1, SqStack &s2, int &x) {
    int y;
    if (!isEmpty(s2)) {
        pop(s2, x);
        return true;
    } else {
        if (isEmpty(s1))
            return false;
        else {
            while (!isEmpty(s1)) {
                pop(s1, y);
                push(s2, y);
            }
            pop(s2, x);
            return true;
        }
    }
}

/**
 * 判断队列是否为空
 * @param s1
 * @param s2
 * @return
 */
bool isEmptyQueue(SqStack s1, SqStack s2) {
    if (isEmpty(s1) && isEmpty(s2))
        return true;
    else
        return false;
}

/**
 * 入栈
 * @param st
 * @param x
 * @return
 */
bool push(SqStack &st, int x) {
    if (st.top == MAXSIZE - 1)
        return false;
    else {
        ++st.top;
        st.data[st.top] = x;
        return true;
    }
}

/**
 * 出栈
 * @param st
 * @param x
 * @return
 */
bool pop(SqStack &st, int &x) {
    if (st.top == -1)
        return false;
    else {
        x = st.data[st.top];
        --st.top;
        return true;
    }
}

/**
 * 栈空
 * @param stack
 * @return
 */
bool isEmpty(SqStack &stack) {
    if (stack.top == -1)
        return true;
    else
        return false;
}
