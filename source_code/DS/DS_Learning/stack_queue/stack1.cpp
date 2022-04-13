#include "stdio.h"


#define MAXSIZE 100

/**
 * 顺序栈定义
 */
typedef struct {
    int data[MAXSIZE];
    int top;
} SqStack;

/**
 * 初始化顺序栈
 * @param st
 */
void InitStack(SqStack &st) {
    st.top = -1;
}

/**
 * 判断栈空代码
 * @param st
 * @return
 */
int isEmpty(SqStack st) {
    if (st.top == -1)
        return 1;
    else
        return 0;
}

/**
 * 进栈
 * 先移动栈指针，再进栈
 * @param st
 * @param x
 * @return
 */
int push(SqStack &st, int x) {
    if (st.top == MAXSIZE - 1)
        return 0;
    ++st.top;
    st.data[st.top] = x;
    //必须是++top
    //st.data[++st.top] = x;
    return 1;
}

/**
 * 出栈
 * 先取出元素，再移动指针
 * @param st
 * @param x
 * @return
 */
int pop(SqStack &st, int &x) {
    if (st.top == -1)
        return 0;
    //必须是top--
    //x = st.data[st.top--];
    x = st.data[st.top];
    --st.top;
    return 1;
}