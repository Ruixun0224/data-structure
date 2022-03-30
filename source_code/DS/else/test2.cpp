//
// Created by yurui on 2022/3/27.
//
#include <stdio.h>


int FindMax(int K,const int list[]){
    int thisSum = list[0];
    int maxSum = 0;
    for (int i = 0; i < K; ++i) {
        thisSum += list[i];
        if(thisSum > maxSum){
            maxSum = thisSum;
        }else if(thisSum < 0){
            thisSum = 0;
        }
    }
    return maxSum;
}

int main(){
    int K;
    scanf_s("%d",&K);
    int list[K];
    int a;
    for (int i = 0; i < K; ++i) {
        scanf_s("%d",&a);
        list[i] = a;
    }

    int result = FindMax(K,list);
    printf_s("%d",result);
    return 0;
}
