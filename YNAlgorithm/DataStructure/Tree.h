//
//  Tree.h
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/7.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#import "DSGlobalHeader.h"
#import "LinearList.h"

#pragma mark - 树的双亲表示法
typedef struct PTNode {
    ElemType data;
    int paret; /// 双亲位置
} PTNode;

typedef struct {
    /// 结点数组
    PTNode nodes[MAXSIZE];
    /// 结点根位置、结点数
    int r, n;
} PTree;

#pragma mark - 树的孩子表示法
typedef struct CTNode {
    // 自身的位置
    int child;
    struct CTNode *next;
} *ChildPtr;

typedef struct {
    ElemType data;
    /// 头指针
    ChildPtr *firstChild;
} CTBox;

typedef struct {
    /// 结点数组
    CTBox nodes[MAXSIZE];
    /// 结点根位置、结点数
    int r, n;
} CTree;

#pragma mark - 树的兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstChild, *rightChild;
}CSNode, *CSTree;

#pragma mark - 二叉树二叉链表

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChildNode, *rChildNode;
    /// 三叉链表的话需要增加一个pNode;
} BiTNode, *BiTree;

#pragma mark - 二叉树的前序遍历
void PreOrderTraverse(BiTree T);

#pragma mark - 二叉树的中序遍历
void InOrderTraverse(BiTree T);

#pragma mark - 二叉树的后序遍历
void PostOrderTraverse(BiTree T);

// 已知一棵二叉树的前序遍历序列为ABCDEF，中序遍历序列为CBAEDF，请问这棵二叉树的后序遍历结果是多少？
// 二叉树的中序序列是ABCDEFG，后序序列是BDCAFGE，求前序序列。

#pragma mark - 层序遍历
/**
 创建队列 - push根节点 - while循环打印，然后push 左右子节点 然后pop当前打印的节点
 */
void LayerTraverseForQueue(BiTree T);

/**
 定义in , out变量，将根据点存入数组，in++，while(in > out)循环打印，如果lChild和rChild则放入数组
 */
void LayerTraverseForArray(BiTree T);

#pragma mark - 二叉树的创建 - 前序
void createBitTree(BiTree *T);

#pragma mark - 线索二叉树
typedef enum {
    Link,
    Thread,
} PointerTag;

typedef struct BiThrNode {
    ElemType data;
    struct BiThrNode *lChild, *rChild;
    PointerTag LTag, RTag;
} BiTHrNode, *BitThrTree;

/// 中序遍历进行中序线索化
void InitThreading(BitThrTree p);

#endif /* Tree_h */
