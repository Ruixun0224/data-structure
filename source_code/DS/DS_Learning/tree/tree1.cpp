//
// Created by ruixun on 2022/4/19.
//
#include "stdio.h"

/**
 * 二叉树的链式存储
 */
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * 访问节点操作
 * @param T
 */
void visit(BiTree T){
    printf("lchild is %d",T->lchild->data);
    printf("rchild is %d",T->rchild->data);
}

/**
 * 先序遍历
 * @param T
 */
void PreOrder(BiTree T) {
    if (T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/**
 * 中序遍历
 * @param T
 */
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

/**
 * 后序遍历
 * @param T
 */
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        PostOrder(T);
    }
}
