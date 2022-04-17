//
// Created by ruixun on 2022/4/17.
//
#include "stdio.h"
#include "string.h"

#define MAXSIZE 100

typedef struct {
    char ch[MAXSIZE];
    int length;
} Str;

/**
 * 串的简单模式匹配
 * @param str
 * @param substr
 * @return 成功返回位置，失败返回0
 */
int index(Str str, Str substr) {
    int i = 1, j = 1, k = i;
    while (i <= str.length && j <= substr.length) {
        if (str.ch[i] == substr.ch[i]) {
            ++i;
            ++j;
        } else {
            j = 1;
            i = ++k;
        }
    }
    if (j > substr.length)
        return k;
    else
        return 0;
}

/**
 * 获得next数组
 * @param substr 
 * @param next 
 */
void getNext(Str substr, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < substr.length) {
        if (j == 0 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j];
    }
}

/**
 * KMP匹配算法
 * @param str 
 * @param substr 
 * @param next 
 * @return 
 */
int KMP(Str str, Str substr, int next[]) {
    int i = 1, j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else
            j = next[j];
    }
    if (j > substr.length)
        return i - substr.length;
    else
        return 0;
}

/**
 * 获得nextval数组
 * @param substr 
 * @param nextval 
 */
void getNextval(Str substr, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < substr.length) {
        if (j == 0 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            if (substr.ch[i] != substr.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}

/**
 * KMP算法优化
 * @param str 
 * @param substr 
 * @param nextval 
 * @return 
 */
int KMPpro(Str str, Str substr, int nextval[]) {
    int i = 1, j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else
            j = nextval[j];
    }
    if (j > substr.length)
        return i - substr.length;
    else
        return 0;
}

void test01() {
    Str s1, s2;
    strcpy(s1.ch,"abcde");
    strcpy(s2.ch,"bcd");
    s1.length = 5;
    s2.length = 3;
    int next[s2.length];
    memcmp(next,0,0);
    getNext(s2, next);
    for (int i = 0; i < s2.length; ++i) {
        printf("%d\t",next[i]);
    }
    printf("\n");
    int i = KMPpro(s1, s2, next);
    printf("%d\n", i);
}

int main() {
    test01();
    return 0;
}