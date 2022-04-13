//
// Created by yurui on 2022/4/13.
//

#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef struct LNode{
    int data;
    struct LNode*next;
}LNode;

/**
 * 判断左右括号是否匹配
 * @param exp 
 * @param n 
 * @return 1匹配 0不匹配
 */
int match(char exp[], int n) {
    char stack[MAXSIZE];
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (exp[i] == '(')
            stack[++top] = '(';
        if (exp[i] == ')') {
            if (top == -1)
                return 0;
            else
                top--;
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}

void test1() {
    char exp[6] = {'(', 'a', 'b', ')', '(', ')'};
    int n = 6;
    int i = match(exp, n);
    printf("result:%d", i);
}

/**
 * 运算函数
 * @param a
 * @param op
 * @param b
 * @return 运算结果
 */
int Op(int a, char op, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return b == 0 ? printf("error\n") : a / b;
        default:
            return 0;
    }
}

/**
 * 求后缀表达式的值
 * @param exp
 * @return 运算结果
 */
int com(char exp[]) {
    int a, b, c;
    int stack[MAXSIZE];
    int top = -1;
    char op;
    for (int i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] >= '0' && exp[i] <= '9')
            stack[++top] = exp[i] - '0';
        else {
            op = exp[i];
            b = stack[top--];
            a = stack[top--];
            c = Op(a, op, b);
            stack[++top] = c;
        }
    }
    return stack[top];
}

void test2() {
    char exp[] = {'3', '3', '/', '1', '+', '2', '1', '*', '-'};
    int i = com(exp);
    printf("result=%d\n", i);
}

/**
 * 不带头结点的链栈
 * @param lst
 */
void InitStackL(LNode*&lst){
    lst = nullptr;
}

/**
 * 判断为空
 * @param lst
 * @return
 */
int isEmptyL(LNode *lst){
    if(lst == nullptr)
        return 1;
    else
        return 0;
}

/**
 * 入栈
 * @param lst
 * @param x
 */
void pushL(LNode *&lst,int x){
    LNode *p;
    p=(LNode*) malloc(sizeof (LNode));
    p->next == nullptr;
    p->data = x;
    p->next = lst;
    lst = p;
}

/**
 * 出栈
 * @param lst
 * @param x
 * @return
 */
int popL(LNode*&lst,int &x){
    LNode *p;
    if(lst == nullptr)
        return 0;
    p = lst;
    x = p->data;
    lst = p->next;
    free(p);
    return 1;
}

int main() {
//    test1();
    test2();
    return 0;
}