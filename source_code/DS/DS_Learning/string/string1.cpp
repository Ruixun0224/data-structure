//
// Created by ruixun on 2022/4/16.
//

#include "stdlib.h"
#include "stdio.h"

#define MAXSIZE 100

typedef struct {
    char ch[MAXSIZE + 1];
    int length;
} Str1;

typedef struct {
    char *ch;
    int length;
} Str;

/**
 * 赋值操作，wrong test
 * @param str
 * @param ch
 * @return
 */
int strAssign(Str &str, char *ch) {
    if (str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while (*c) {
        ++len;
        ++c;
    }
    if (len == 0) {
        str.ch = NULL;
        str.length = 0;
        return 1;
    } else {
        str.ch = (char *) malloc(sizeof(char) * (len + 1));
        if (str.ch == nullptr)
            return 0;
        else {
            c = ch;
            for (int i = 0; i <= len; ++c, ++i) {
                str.ch[i] = *c;
                str.length = len;
                return 1;
            }
        }
    }
}

void test01() {
    Str str;
    int i = strAssign(str, "cur input");
    printf("%d\n", i);
}

/**
 * 返回串的长度
 * @param str
 * @return
 */
int strLength(Str str) {
    return str.length;
}

/**
 * 比较串的大小，ASCII码
 * @param s1
 * @param s2
 * @return
 */
int strCompare(Str s1, Str s2) {
    for (int i = 0; i < s1.length && i < s2.length; ++i) {
        if (s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    }
    return s1.length - s2.length;
}

/**
 * 将两个串首尾相接
 * @param str
 * @param str1
 * @param str2
 * @return
 */
int concat(Str &str, Str str1, Str str2) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *) malloc(sizeof(char) * (str1.length + str2.length + 1));
    if (str.ch == NULL)
        return 0;
    int i = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    int j = 0;
    while (j <= str2.length) {
        str.ch[j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return 1;
}

/**
 * 求子串
 * @param substr
 * @param str
 * @param pos 起始位置
 * @param len 长度
 * @return
 */
int substring(Str &substr, Str str, int pos, int len) {
    if (pos < 0 || pos > str.length || len < 0 || len > str.length - len)
        return 0;
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    if (len == 0) {
        substr.ch = NULL;
        substr.length = 0;
        return 1;
    } else {
        substr.ch = (char *) malloc(sizeof(char) * (len + 1));
        int i = pos;
        int j = 0;
        while (i < pos + len) {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}

/**
 * 串清空操作
 * @param str
 * @return
 */
int clearString(Str &str) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}

int main() {
    test01();
    return 0;
}

