//
//  LinearList.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/5.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "LinearList.h"

#pragma mark - 线性表顺序存储方式
Status GetElemForSQ(SqList L, int i, ElemType *e) {
    // 先前判断条件
    if (L.length == 0 || i < 1 || i > L.length) return ERROR;
    *e = L.data[i - 1];
    return OK;
};

/**
 *  如果插入位置不合理，抛出异常；
 如果线性表长度大于等于数组长度，则抛出异常或动态增加容量；
 从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置；
 将要插入元素填入位置i处；线性表长加1。
 */
Status LinearInsertForSQ(SqList *L, int i, ElemType e) {
    // 校验
    if (L -> length == MAXSIZE) return ERROR;
    if (i < 1 || i > L -> length + 1) return ERROR;
    if (i <= L -> length) {
        /// 位置向后移动
        for (int k = L -> length - 1; k >= i - 1; k--) {
            L -> data[k + 1] = L -> data[k];
        }
    }
    L -> data[i - 1] = e;
    L -> length ++;
    return OK;
}

/**
 *  如果删除位置不合理，抛出异常；
 取出删除元素；
 从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置；
 表长减1。
 */
Status LinearDeleteForSQ(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L -> length) return ERROR;
    if (L -> length == 0) return ERROR;
    /// 返回 e
    *e = L -> data[i - 1];
    
    if (i < L -> length) {
        /// 位置向前移动
        for (int k = i - 1; k < L -> length - 1; k++) {
            L -> data[i - i] = L -> data[i];
        }
    }
    L -> length --;
    return OK;
}

int GetElemLengthForSQ(SqList L) {
    return L.length;
}

#pragma mark - 线性表链式存储方式
/*
 1.声明一个指针p指向链表第一个结点，初始化k从1开始；
 2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一结点，k累加1；
 3.若到链表末尾p为空，则说明第i个结点不存在；
 4.否则查找成功，返回结点p的数据。
 */
Status GetElemForC(Node *head, int i, ElemType *e) {
    Node *p = head -> next;
    int k = 1;
    /// 循环找到第i个Node
    while (p && k < i) {
        p = p -> next;
    }
    /// p仍然是空 || k > i
    if (!p || k > i) {
        return ERROR;
    }
    *e = p -> data;
    return OK;
}

/*
 1.找到第i个Node，创建Node并赋值
 2.校验
 3.执行交换 s -> next = p -> next; p -> next = s;
 */
Status InsertElemForC(Node *head, int i, ElemType e) {
    Node *p = head;
    int k = 1;
    /// 找到第i个Node
    while (p && k < i) {
        p = p -> next;
        k++;
    }
    struct Node *newNode = malloc(sizeof(Node));
    newNode -> data = e;
    /// 第i个Node不存在
    if (!p || k > i)  {
        return ERROR;
    }
    newNode ->next = p -> next;
    p -> next = newNode;
    return OK;
}

/*
 1.找到第i个Node，创建Node并赋值
 2.校验
 3.执行交换     Node q = p -> next; p -> next = q -> next;
 */
Status DeleteElemForC(Node *head, int i, ElemType *e) {
    Node *p = head;
    int k = 1;
    /// 找到第i个Node
    while (p && k < i) {
        p = p -> next;
        k++;
    }
    /// 第i个Node不存在
    if (!p || k > i)  {
        return ERROR;
    }
    Node *q = p -> next;
    p -> next = q -> next;
    *e = q -> data;
    free(q);
    return OK;
}

/*
 头插法
 1.声明一指针p和计数器变量i；
 2.初始化一空链表L；
 3.让L的头结点的指针指向NULL，即建立一个带头结点的单链表；
 4.循环：生成新Node赋值给p,随机生成数据p -> data, 插入到头结点
 */
Node * CreateListHead(int n) {
    /// 先建立头结点
    Node *head = malloc(sizeof(Node));
    head -> next = NULL;
    
    for (int i = n - 1; i >= 0; i--) {
        /// 生成新Node
        Node *newNode = malloc(sizeof(Node));
        newNode -> data = i;
        newNode -> next = head -> next;
        // 插入到表头
        head -> next = newNode;
    }
    return head;
}

/// 尾插法
Node * CreateListTail(int n) {
    /// 先建立头结点
    Node *head = malloc(sizeof(Node));
    head -> next = NULL;
    /// 代表尾部节点
    Node *tail = head;
    for (int i = 0; i < n; i++) {
        /// 生成新Node
        Node *newNode = malloc(sizeof(Node));
        newNode -> data = i;
        tail -> next = newNode;
        /// 指向尾部Node
        tail = newNode;
    }
    tail -> next = NULL;
    return head;
}

/*
 1.声明一指针p和q；
 2.将第一个结点赋值给p；
 3.循环：将下一结点赋值给q；释放p；将q赋值给p。头节点Next = NULL;
 */
Status clearListForC(Node *head) {
    Node *p = head -> next;
    Node *q = NULL;
    while (p) {
        q = p -> next;
        free(p);
        p = q;
    }
    head -> next = NULL;
    return OK;
}

#pragma mark - 静态链表
Status InitList(StaticLinkList L) {
    for (int i = 0; i < STATIC_MAXSIZE; i++) {
        L[i].cur = i + 1;
    }
    // 目前静态链表为空，最后一个元素的cur为0.
    L[STATIC_MAXSIZE - 1].cur = 0;
    return OK;
}

//// 若备用的链表非空，则返回游标
int Malloc_SLL(StaticLinkList L) {
    int i = L[0].cur;
    if (i) {
        /// 更新备用链表的cur
        L[0].cur = L[i].cur;
    }
    return i;
}

/// 根据cur计算数据大小 - cur == 0 代表没有了存放的数据 最后一个存放的是头结点cur
int ListLength(StaticLinkList L) {
    int j = 0;
    int i = L[STATIC_MAXSIZE - 1].cur;
    while (i) {
        i = L[i].cur;
        j++;
    }
    return j;
}

/*
 静态链表的插入操作
 1.获得备用链表的下标并放入存储的数据
 2.寻找到i的下标位置
 3.更新游标指针
 */
Status ListInsert(StaticLinkList L, int i, ElemType e) {
    int j, k; // k 是最后一个元素的下标
    
    k = STATIC_MAXSIZE - 1;
    // 校验
    if (i < 1 || i > ListLength(L) + 1) {
        return ERROR;
    }
    // 获得备用链表的下标
    j = Malloc_SLL(L);
    if (j) {
        // 设置值data
        L[j].data = e;
    }
    /////// 更新游标
    // 找到元素i之前的下标
    for (int l = 1; l < i; l++) {
        k = L[k].cur;
    }
    // 把元素i之前的cur赋值给新元素的cur
    L[j].cur = L[k].cur;
    // 把新元素的下标赋值给i元素的cur
    L[k].cur = j;
    return OK;
}

/// 将备用的链表cur还给无数据链表，把被删除的cur更新给备用链表cur
void Free_SLL(StaticLinkList L, int k) {
    L[k].cur = L[0].cur;
    L[0].cur = k;
}

Status ListDelete(StaticLinkList L, int i) {
    if (i < 1 ||  i > ListLength(L)) {
        return ERROR;
    }
    int k = STATIC_MAXSIZE - 1;
    // 找到元素i之前的下标
    for (int j = 1; j < i; j++) {
        k = L[k].cur;
    }
    // 取得k下标的cur，L[k] 是要被删除的元素
    int j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SLL(L, j);
    return OK;
}

#pragma mark - 线性表的单向循环链表

#pragma mark - 单向循环链表合并操作

#pragma mark - 线性表的双向链表

#pragma mark - 线性表的双向循环链表

#pragma mark - 特殊的线性表--栈

void initStackForSQ(Stack *S) {
    S->top = -1;
}

Status PushForSQ(Stack *S, ElemType e) {
    // 校验栈满
    if (S -> top == MAXSIZE - 1) {
        return ERROR;
    }
    /// 放入stack 中
    S -> top++;
    S -> data[S->top] = e;
    return OK;
}

Status PopForSQ(Stack *S, ElemType *e) {
    if (S -> top == -1) {
        return ERROR;
    }
    *e = S -> data[S -> top];
    S -> top--;
    return OK;
}

Status StackIsEmptyForSQ(Stack *S) {
    if (S -> top != -1) {
        return ERROR;
    }
    return OK;
}

void ClearStackForSQ(Stack *S) {
    if (StackIsEmptyForSQ(S)) return;
    S -> top = -1;
}

#pragma mark - 特殊的线性表栈--两栈共存栈
Status PushForDSQ(DoubleStack *S, ElemType e, int stackNumber) {
    // 栈满
    if (S -> top1 + 1 == S -> top2) {
        return ERROR;
    }
    if (stackNumber == 1) {
        S -> data[++S -> top1] = e;
    } else if (stackNumber == 2) {
        S -> data[--S -> top2] = e;
    }
    
    return OK;
}

Status PopForDSQ(DoubleStack *S, ElemType *e, int stackNumber) {
    if (stackNumber == 1) {
        if (S -> top1 == -1) {
            return ERROR;
        }
        *e = S -> data[S -> top1--];
    } else if (stackNumber == 2) {
        if (S -> top2 == MAXSIZE) {
            return ERROR;
        }
        *e = S -> data[S -> top2++];
    }
    return OK;
}

#pragma mark - 特殊的线性表栈--栈链式存储

Status PushForC(LinkStack *S, ElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    // 赋值元素并更新next
    s -> data = e;
    s -> next = S -> top;
    // 设置新Node为节点
    S -> top = s;
    S -> count++;
    return OK;
}

Status PopForC(LinkStack *S, ElemType *e) {
    if (S -> count == 0) {
        return ERROR;
    }
    *e = S -> top -> data;
    LinkStackPtr tempNode = S -> top;
    S -> top = S -> top -> next;
    S -> count --;
    free(tempNode);
    return OK;
}

#pragma mark - 栈的应用 - 递归 - 斐波那契数列实现 1、1、2、3、5、8、13、21、34···
int FBi(int i) {
    if (i < 2) {
        return i == 0 ? 0 : 1;
    }
    return FBi(i - 1) + FBi(1 - 2);
}
#pragma mark - 特殊的线性表的队列--顺序存储

#pragma mark - 特殊的线性表的循环队列--顺序存储

Status InitQueueForSQ(QueueSQ *Q) {
    Q -> front = 0;
    Q -> rear = 0;
    return OK;
}

int QueueLengthForSQ(QueueSQ *Q) {
    return (Q -> rear - Q -> front + MAXSIZE) % MAXSIZE;
}

Status QueueIsEmptyForSQ(QueueSQ *Q) {
    if (Q -> rear != Q -> front) {
        return ERROR;
    }
    return OK;
}

Status EnQueueForSQ(QueueSQ *Q, ElemType e) {
    /// 队满
    if ((Q -> rear + 1) % MAXSIZE == Q -> front) {
        return ERROR;
    }
    /// 赋值给队尾 并且 向后移动一位，若到最后则放到头部
    Q -> data[Q -> rear] = e;
    Q -> rear = (Q -> rear + 1) % MAXSIZE;
    return OK;
}

Status OutQueueForSQ(QueueSQ *Q, ElemType *e) {
    if (QueueIsEmptyForSQ(Q)) {
        return ERROR;
    }
    *e = Q -> data[Q -> front];
    /// 向后移动一位，若到最后则放到头部
    Q -> front = (Q -> front + 1) % MAXSIZE;
    return OK;
}

#pragma mark - 特殊的线性表的循环队列--链式存储

void InitQueueFroC(LinkQueue *LQ) {
    LQ -> rear = NULL;
    LQ -> front = NULL;
}

Status LinkQueueIsEmpty(LinkQueue *LQ) {
    if (LQ -> front != NULL) {
        return ERROR;
    }
    return OK;
}

void ClearLinkQueue(LinkQueue *LQ) {
    while (LQ -> front != NULL) {
        QNode *node = LQ -> front;
        LQ -> front = LQ -> front -> next;
        free(node);
    }
    LQ -> rear = NULL;
}

Status EnQueueForC(LinkQueue *LQ, ElemType e) {
    QNode *node = malloc(sizeof(QNode));
    node -> data = e;
    node -> next = NULL;
    if (LQ -> rear == NULL) {
        LQ -> front = LQ -> rear = node;
    } else {
        // 指针next指向new node
        LQ -> rear -> next = node;
        // 更新rear指针
        LQ -> rear = node;
    }
    return OK;
}

Status outQueueForC(LinkQueue *LQ, ElemType *e) {
    if (LQ -> front == NULL) {
        return ERROR;
    }
    *e = LQ -> front -> data;
    QNode *node = LQ -> front;
    LQ -> front = LQ -> front -> next;
    // 出栈后如果front为空,则rear也应该为空
    if (LQ -> front == NULL) {
        LQ -> rear = NULL;
    }
    free(node);
    return OK;
}

