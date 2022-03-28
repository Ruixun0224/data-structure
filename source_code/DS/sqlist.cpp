//
// Created by yurui on 2022/3/27.
//
#include "iostream"

#define maxSize 100
using namespace std;

typedef struct {
    int data[maxSize];
    int length;
} Sqlist;

int findElem(Sqlist L, int x) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (x < L.data[i]) {
            return i;
        }
    }
    return i;
}

int main() {
    Sqlist L;
    L.length = 3;
    L.data[0] = 0;
    L.data[1] = 9;
    L.data[2] = 8;
    int i = findElem(L, 10);
    cout << i;
    return 0;
}
