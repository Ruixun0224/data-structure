//
// Created by ruixun on 2022/4/15.
//
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define MAXSIZE 10


typedef struct {
    char data[MAXSIZE];
    int top;
} Stack;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct {
    int data[MAXSIZE];
    int front, rear;
} cycQueue;

typedef struct {
    int data[MAXSIZE];
    int front, rear;
    int tag;
} Queue;

/**
 * 判断序列是否合法
 * @param ch 
 * @return 合法返回1，否则返回0
 */
int Judge(char ch[]) {
    int i = 0;
    int countI, countO = 0;
    while (ch[i] != '\0') {
        if (ch[i] == 'I')
            ++countI;
        if (ch[i] == 'O')
            ++countO;
        if (countO > countI)
            return 0;
        ++i;
    }
    if (countI != countO)
        return 0;
    else
        return 1;
}

/**
 * 带头结点只有尾指针的队列 入队算法
 * @param rear 
 * @param x 
 * @return 
 */
bool enQueue(LNode *&rear, int x) {
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == nullptr)
        return false;
    s->data = x;
    s->next = rear->next;
    rear->next = s;
    rear = s;
    return true;
}

/**
 * 出队算法
 * @param rear 
 * @param x 
 * @return 
 */
bool deQueue(LNode *&rear, int &x) {
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == nullptr)
        return false;
    if (rear->next == rear)
        return false;
    else {
        s = rear->next->next;
        rear->next->next = s->next;
        x = s->data;
        if (s == rear)
            rear = rear->next;
        free(s);
        return true;
    }
}

/**
 * 队尾删除
 * @param cq 
 * @param x 
 * @return 
 */
bool deCycQueue(cycQueue &cq, int &x) {
    if (cq.front == cq.rear)
        return false;
    else {
        x = cq.data[cq.rear];
        cq.rear = (cq.rear - 1 + MAXSIZE) % MAXSIZE;
        return true;
    }
}

/**
 * 队头插入
 * @param cq 
 * @param x 
 * @return 
 */
bool enCycQueue(cycQueue &cq, int x) {
    if (cq.rear == (cq.front - 1 + MAXSIZE) % MAXSIZE)
        return false;
    else {
        cq.data[cq.front] = x;
        cq.front = (cq.front - 1 + MAXSIZE) % MAXSIZE;
        return true;
    }
}

/**
 * 初始化带tag的queue
 * @param queue 
 */
void InitQueue(Queue &queue) {
    queue.front = queue.rear = 0;
    queue.tag = 0;
}

/**
 * 判断是否为空
 * @param queue 
 * @return 
 */
bool isQueueEmpty(Queue queue) {
    if (queue.tag == 0 && queue.front == queue.rear)
        return true;
    else
        return false;
}

/**
 * 判断是否为满
 * @param queue 
 * @return 
 */
bool isQueueFull(Queue queue) {
    if (queue.tag == 1 && queue.front == queue.rear)
        return true;
    else
        return false;
}

/**
 * 入队
 * @param queue 
 * @param x 
 * @return 
 */
bool enQueue(Queue &queue, int x) {
    if (isQueueFull(queue))
        return false;
    else {
        queue.rear = (queue.rear + 1) % MAXSIZE;
        queue.data[queue.rear] = x;
        queue.tag = 1;
        return true;
    }
}

/**
 * 出队
 * @param queue 
 * @param x 
 * @return 
 */
bool deQueue(Queue &queue, int &x) {
    if (isQueueEmpty(queue))
        return false;
    else {
        queue.front = (queue.front + 1) % MAXSIZE;
        x = queue.data[queue.front];
        queue.tag = 0;
        return true;
    }
}

/**
 * 十进制转换二进制，利用栈转换
 * @param n
 * @return
 */
int BaseTrans(int n) {
    int i, result = 0;
    int stack[MAXSIZE];
    int top = -1;
    while (n != 0) {
        i = n % 2;
        n = n / 2;
        stack[++top] = i;
    }
    while (top != -1) {
        i = stack[top--];
        result = result * 10 + i;
    }
    return result;
}

void test01() {
    int i = BaseTrans(5);
    printf("result:%d\n", i);
}

/**
 * 栈空判断
 * @param st 
 * @return 
 */
bool isStackEmpty(Stack st) {
    if (st.top == -1)
        return true;
    else
        return false;
}

/**
 * 栈满判断
 * @param st 
 * @return 
 */
bool isStackFull(Stack st) {
    if (st.top == MAXSIZE - 1)
        return true;
    else
        return false;
}

/**
 * 进栈操作
 * @param st 
 * @param ch 
 * @return 
 */
bool push(Stack &st, char ch) {
    if (isStackFull(st))
        return false;
    else {
        st.data[++st.top] = ch;
        return true;
    }
}

/**
 * 出栈操作
 * @param st 
 * @param ch 
 * @return 
 */
bool pop(Stack &st, char &ch) {
    if (isStackEmpty(st))
        return false;
    else {
        ch = st.data[st.top--];
        return true;
    }
}

/**
 * 得到栈顶元素
 * @param st 
 * @param ch 
 */
void getTop(Stack st, char &ch) {
    if (isStackEmpty(st))
        return;
    else {
        ch = st.data[st.top--];
    }
}

/**
 * 括号检查
 * @param f 
 * @return 1匹配 0不匹配 
 */
int bracketCheck(char f[]) {
    Stack st;
    char ch;
    char *p = f;
    while (*p != '\0') {
        if (*p == 39) {
            ++p;
            while (*p != 39)
                ++p;
            ++p;
        } else if (*p == 34) {
            ++p;
            while (*p != 34)
                ++p;
            ++p;
        } else {
            switch (*p) {
                case '(':
                case '[':
                case '{':
                    push(st, *p);
                    break;
                case ')':
                    getTop(st, ch);
                    if (ch == '(')
                        pop(st, ch);
                    else
                        return 0;
                    break;
                case ']':
                    getTop(st, ch);
                    if (ch == '[')
                        pop(st, ch);
                    else
                        return 0;
                    break;
                case '}':
                    getTop(st, ch);
                    if (ch == '{')
                        pop(st, ch);
                    else
                        return 0;
                    break;
            }
        }
    }
    if (isStackEmpty(st))
        return 1;
    else
        return 0;
}

void test02(){
    char ch[]={"(1+a+u)+[I-}"};
    int i = bracketCheck(ch);
    printf("result:%d\n",i);
}

/**
 * 递归形式
 * @param A
 * @param p
 * @param e
 * @return
 */
float Sqrt_A1(float A, float p, float e) {
    if (fabs(pow(p, 2) - A) < e)
        return p;
    else
        return Sqrt_A1(A, (p + A / p) / 2, e);
}

/**
 * 非递归形式
 * @param A
 * @param p
 * @param e
 * @return
 */
float Sqrt_A2(float A, float p, float e) {
    while (fabs(pow(p, 2)) >= e)
        p = (p + A / p) / 2;
    return p;
}

/**
 * 求给定字符串的全排列
 * @param str
 * @param k
 * @param n
 */
void perm(char str[], int k, int n) {
    char temp;
    if (k == 0) {
        for (int i = 0; i < n - 1; ++i) {
            printf("%d", str[i]);
        }
    } else {
        for (int i = 0; i < k; ++i) {
            temp = str[k];
            str[k] = str[i];
            str[i] = temp;
            perm(str, k - 1, n);
            temp = str[i];
            str[i] = str[k];
            str[k] = temp;
        }
    }
}

int main() {
//    test01();
//    test02();
    return 0;
}