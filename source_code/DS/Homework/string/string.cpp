//
// Created by ruixun on 2022/4/17.
//
#include "stdlib.h"

#define MAXSIZE 10

typedef struct {
    char *ch;
    int length;
} Str;

typedef struct {
    char ch[MAXSIZE];
    int length;
} SqStr;

typedef struct SNode {
    char data;
    struct SNode *next;
} SNode;

/**
 * 将str中所有值为ch1的字符转换为ch2
 * @param str
 * @param ch1
 * @param ch2
 */
void trans(Str &str, char ch1, char ch2) {
    for (int i = 0; i < str.length; ++i) {
        if (str.ch[i] == ch1)
            str.ch[i] = ch2;
    }
}

/**
 * 交换两个字符
 * @param ch1
 * @param ch2
 */
void swap(char &ch1, char &ch2) {
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

/**
 * str逆转函数
 * @param str
 */
void invert(Str &str) {
    int i = 0;
    int j = str.length - 1;
    while (i < j) {
        swap(str.ch[i], str.ch[j]);
        ++i;
        --j;
    }
}

/**
 * 删除值为ch的字符
 * @param str
 * @param ch
 */
void deleteCh(Str &str, char ch) {
    int j = 0;
    if (str.length != 0) {
        int sum = 0;
        for (int i = 0; i < str.length; ++i) {
            if (str.ch[i] == ch)
                ++sum;
        }
        if (sum != 0) {
            char *temp_ch = (char *) malloc(sizeof(char) * (str.length - sum + 1));
            for (int i = 0; i < str.length; ++i) {
                if (str.ch[i] != ch) {
                    temp_ch[j++] = str.ch[i];
                }
                temp_ch[j] = '\0';
                str.length = str.length - sum;
                free(str.ch);
                str.ch = temp_ch;
            }
        }
    }
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
 * 从str第pos位置起匹配子串，修改KMP算法
 * @param str
 * @param substr
 * @param pos
 * @return
 */
int KMPpos(Str str, Str substr, int pos) {
    int next[substr.length];
    getNextval(substr, next);
    int i = pos;
    int j = 1;
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
        return -1;
}

/**
 * 删除串中下标为i的字符开始的j个字符
 * @param str
 * @param i
 * @param j
 */
void del(SqStr &str, int i, int j) {
    if (i < str.length && i >= 0 && j >= 0) {
        for (int k = i + j; k < str.length; ++k) {
            str.ch[k - j] = str.ch[k];
            str.length -= (str.length - i < j ? str.length - i : j);
            str.ch[str.length] = '\0';
        }
    }
}

/**
 * 串连接
 * @param str
 * @param str1
 * @param str2
 * @return
 */
bool concat(Str &str, Str str1, Str str2) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *) malloc(sizeof(char) * (str1.length + str2.length + 1));
    if (str.ch == NULL)
        return false;
    int i = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    int j = 0;
    while (j < str2.length) {
        str.ch[i + j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return true;
}

/**
 * 求子串
 * @param substr
 * @param str
 * @param pos
 * @param len
 * @return
 */
bool subString(Str &substr, Str str, int pos, int len) {
    if (pos < 0 || pos >= substr.length || len < 0 || len > str.length - 1)
        return false;
    if (substr.ch) {
        free(substr.ch);
        substr.ch = NULL;
    }
    if (len == 0) {
        substr.ch = NULL;
        substr.length = 0;
        return true;
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
        return true;
    }
}

/**
 * 子串替换
 * @param str1
 * @param srt2
 * @param i
 * @param j
 * @return
 */
int stuff(Str &str1, Str srt2, int i, int j) {
    Str str11;
    str11.length = 0;
    str11.ch = NULL;
    Str str12;
    str12.length = 0;
    str12.ch = NULL;
    Str temp_str;
    if (!subString(str11, str1, 0, i))
        return 0;
    if (!subString(str12, str1, j + 1, str1.length - j - 1))
        return 0;
    if (!concat(temp_str, str11, str12))
        return 0;
    if (!concat(str1, temp_str, str12))
        return 0;
    return 1;
}

/**
 * 计算一个子串在主串中出现的次数，不考虑重叠状况
 * @param str
 * @param substr
 * @return
 */
int index(Str str, Str substr) {
    int i = 1, j = 1, k = 1, sum = 0;
    while (i <= str.length) {
        if (str.ch[i] == str.ch[j]) {
            ++i;
            ++j;
        } else {
            j = 1;
            i = ++k;
        }
        if (j > substr.length) {
            j = 1;
            ++sum;
        }
    }
    return sum;
}

/**
 * 定义串的链表节点结构，找到str1中首次没有str2出现的位置
 * @param str1
 * @param str2
 * @return
 */
char findFirst(SNode *str1, SNode *str2) {
    for (SNode *p = str1; p != NULL; p = p->next) {
        bool flag = false;
        for (SNode *q = str2; q != NULL; q = q->next) {
            if (p->data == q->data) {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return p->data;
    }
    return '\0';
}

