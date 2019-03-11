//
//  Tree.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/7.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "Tree.h"

#pragma mark - 二叉树的前序遍历
void PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%C", T -> data);
    // 遍历左子树
    PreOrderTraverse(T -> lChildNode);
    // 遍历右子树
    PreOrderTraverse(T -> rChildNode);
}

#pragma mark - 二叉树的中序遍历
void InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    // 遍历左子树
    PreOrderTraverse(T -> lChildNode);
    printf("%C", T -> data);
    // 遍历右子树
    PreOrderTraverse(T -> rChildNode);
}

#pragma mark - 二叉树的后序遍历
void PostOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    // 遍历左子树
    PreOrderTraverse(T -> lChildNode);
    // 遍历右子树
    PreOrderTraverse(T -> rChildNode);
    printf("%C", T -> data);
}

#pragma mark - 层序遍历
void LayerTraverseForQueue(BiTree T) {
    if (T == NULL) return;
    LinkQueue *q = malloc(sizeof(LinkQueue));
    InitQueueFroC(q);
    EnQueueForC(q, T);
    while (!LinkQueueIsEmpty(q)) {
        printf("%d ->", q -> front -> data);
        if (T -> lChildNode) {
            EnQueueForC(q, T -> lChildNode);
        }
        if (T -> rChildNode) {
            EnQueueForC(q, T -> rChildNode);
        }
        BiTNode *bitNode = NULL;
        outQueueForC(q, bitNode);
    }
}

void LayerTraverseForArray(BiTree T) {
    if (T == NULL) return;
    BiTree trees[100];
    int in = 0;
    int out = 0;
    trees[in++] = T; // 先保存二叉树根节点
    while (in > out) {
        if (trees[out] != NULL) {
            printf("%d ->", trees[out] -> data);
            if (trees[out] -> lChildNode) {
                trees[in++] = trees[out] -> lChildNode;
            }
            if (trees[out] -> rChildNode) {
                trees[in++] = trees[out] -> rChildNode;
            }
        }
        out++;
    }
}

#pragma mark - 二叉树的创建 - 前序
void createBitTree(BiTree *T) {
    ElemType ch;
    scanf("%C", &ch);
    if (ch == '#') {
        *T = NULL;
    } else {
        // 生成节点
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T) -> data = ch;
        // 构造左子树
        createBitTree(&(*T) -> lChildNode);
        // 构造右子树
        createBitTree(&(*T) -> rChildNode);
    }
}

#pragma mark - 线索二叉树
BitThrTree pre; // 全局遍历，始终指向刚刚访问的节点
/// 中序遍历进行中序线索化
void InitThreading(BitThrTree p) {
    if (p == NULL) return;
    // 递归初始化左子树线索化
    InitThreading(p -> lChild);
    // 没有左孩子
    if (!p -> lChild) {
        // 前驱线索
        p -> LTag = Thread;
        // 左孩子指针指向前驱
        p -> lChild = pre;
    }
    // 前驱没有右孩子
    if (!pre -> rChild) {
        // 后继线索
        pre -> RTag = Thread;
        // 后继线索指向后继
        pre -> rChild = p;
    }
    pre = p;
    InitThreading(p -> rChild);
}


/**
 T 指向头结点，头结点lChild指向根结点，
 rChild指向中序遍历的最后一个结点。
 */
Status InOrderTraverse_Thr(BitThrTree T) {
    if (T == NULL) return ERROR;
    BitThrTree p = T -> lChild;
    // 空树或者遍历结束时，p == T
    while (p != T) {
        // 当LTag==0时循环到中序序列第一个结点
        while (p -> LTag == Link) {
            p = p -> lChild;
        }
        // 打印数据也可以做其他操作
        printf("%c", p -> data);
        // 代表结束
        while (p -> RTag == Thread && p -> rChild != T) {
            p = p -> rChild;
            printf("%C", p -> data);
        }
        // p 进至其右子树根
        p = p -> rChild;
    }
    return OK;
}

