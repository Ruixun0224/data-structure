//
// Created by ruixun on 2022/4/13.
//
#define MAXSIZE 10

/**
 * 共享栈定义
 */
typedef struct {
    int data[MAXSIZE];
    int top0;//栈0的栈顶
    int top1;//栈1的栈顶
} ShareStack;

/**
 * 共享栈进栈
 * @param shareStack
 * @param StNo 栈序号
 * @param x
 * @return true成功
 */
bool Push(ShareStack &shareStack, int StNo, int x) {
    if (shareStack.top0 < shareStack.top1) {//栈空的情况
        if (StNo == 0) {//如果0号栈
            ++shareStack.top0;
            shareStack.data[shareStack.top0] = x;
            return true;
        } else if (StNo == 1) {//如果1号栈
            --shareStack.top1;
            shareStack.data[shareStack.top1];
            return true;
        } else
            return false;
    } else
        return false;
}

/**
 * 共享栈出栈
 * @param shareStack
 * @param StNo 栈序号
 * @param x
 * @return true成功
 */
bool Pop(ShareStack &shareStack, int StNo, int &x) {
    if (StNo == 0) {
        if (shareStack.top0 == 0) {
            return false;
        } else {
            x = shareStack.data[shareStack.top0];
            --shareStack.top0;
            return true;
        }
    } else if (StNo == 1) {
        if (shareStack.top1 == MAXSIZE - 1) {
            return false;
        } else {
            x = shareStack.data[shareStack.top1];
            ++shareStack.top1;
            return true;
        }
    } else
        return false;
}



