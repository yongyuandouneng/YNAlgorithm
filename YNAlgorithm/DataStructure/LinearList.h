//
//  LinearList.h
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/5.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#ifndef LinearList_h
#define LinearList_h

#include <stdio.h>
//#include <stdbool.h>
#import "DSGlobalHeader.h"

#pragma mark - 线性表顺序存储方式
typedef struct {
    ElemType data[MAXSIZE];
    // 线性表长度
    int length;
} SqList;

Status GetElemForSQ(SqList L, int i, ElemType *e);
Status LinearDeleteForSQ(SqList *L, int i, ElemType *e);
int GetElemLengthForSQ(SqList L);

#pragma mark - 线性表链式存储方式
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

Status GetElemForC(Node *head, int i, ElemType *e);
Status InsertElemForC(Node *head, int i, ElemType e);
Status DeleteElemForC(Node *head, int i, ElemType *e);
Node * CreateListHead(int n);
Node * CreateListTail(int n);
Status clearListForC(Node *head);

#pragma mark - 静态链表

#define STATIC_MAXSIZE 10000

/* 线性表的静态链表存储结构 */
typedef struct staticLinear {
    ElemType data;
    int cur; // 游标，为0时表示无指向
}staticLinear, StaticLinkList[STATIC_MAXSIZE];

#pragma mark - 线性表的单向循环链表

#pragma mark - 单向循环链表合并操作

#pragma mark - 线性表的双向链表
/* 线性表的双向链表存储结构 */
typedef struct DulNode {
    ElemType data;
    struct DuLNode *prior;    /* 直接前驱指针 */
    struct DuLNode *next;     /* 直接后继指针 */
} DulNode, *DuLinkList;
/*
 插入操作 s
 s -> prior = p;
 s -> next = p -> next;
 p -> next -> prior = s;
 p -> next = s;
 */
/*
 删除操作 p
 p -> prior -> next = p -> next;
 p -> next -> prior = p -> prior;
 free(p);
 */
#pragma mark - 线性表的双向循环链表


#pragma mark - 特殊的线性表--栈顺序存储
typedef struct {
    ElemType data[MAXSIZE];
    int top;
} Stack;

void initStackForSQ(Stack *S);
Status PushForSQ(Stack *S, ElemType e);
Status PopForSQ(Stack *S, ElemType *e);
Status StackIsEmptyForSQ(Stack *S);
void ClearStackForSQ(Stack *S);

#pragma mark - 特殊的线性表栈--两栈共存栈
typedef struct {
    ElemType data[MAXSIZE];
    int top1;
    int top2;
} DoubleStack;

Status PushForDSQ(DoubleStack *S, ElemType e, int stackNumber);
Status PopForDSQ(DoubleStack *S, ElemType *e, int stackNumber);

#pragma mark - 特殊的线性表栈--栈链式存储
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
} LinkStack;

Status PushForC(LinkStack *S, ElemType e);
Status PopForC(LinkStack *S, ElemType *e);

#pragma mark - 栈的应用 - 递归 - 斐波那契数列实现 1、1、2、3、5、8、13、21、34···
int FBi(int i);

#pragma mark - 栈的应用 - 四则运算

#pragma mark - 特殊的线性表的队列--顺序存储

#pragma mark - 特殊的线性表的循环队列--顺序存储
typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} QueueSQ;

Status InitQueueForSQ(QueueSQ *Q);
int QueueLengthForSQ(QueueSQ *Q);
Status QueueIsEmptyForSQ(QueueSQ *Q);
Status EnQueueForSQ(QueueSQ *Q, ElemType e);
Status OutQueueForSQ(QueueSQ *Q, ElemType *e);

#pragma mark - 特殊的线性表的循环队列--链式存储
// 队列节点
typedef struct QNode {
    ElemType data;
    struct QNode *next;
}QNode;
// 队列
typedef struct {
    struct QNode *front, *rear;
}LinkQueue;

void InitQueueFroC(LinkQueue *LQ);
void ClearLinkQueue(LinkQueue *LQ);
Status LinkQueueIsEmpty(LinkQueue *LQ);
Status EnQueueForC(LinkQueue *LQ, ElemType e);
Status outQueueForC(LinkQueue *LQ, ElemType *e);

#endif /* LinearList_h */
