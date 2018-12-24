//
//  DataStructureQueue.c
//  YNAlgorithm
//
//  Created by ZYN on 2018/4/15.
//  Copyright © 2018年 Yongneng Zheng. All rights reserved.
//

#include "DataStructureQueue.h"
#include <stdio.h>
#include <stdlib.h>

/// 初始化queue
void initQueue(struct queue *hq) {
    /// 把队首和队尾指针置空
    hq -> front = NULL;
    hq -> rear = NULL;
}

/// 向链表队列插入一个元素
void insertQueue(struct queue *hq, int x) {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    
    newNode -> data = x;
    newNode -> next = NULL;    /*把新结点的指针域置空*/
    
    if (hq -> rear == NULL) {
         /*若链队为空，则新结点即是队首结点又是队尾结点*/
        hq -> front = hq -> rear = newNode;
    } else {
        /*若链队非空，则依次修改队尾结点的指针域和队尾指针，使之指向新的队尾结点*/
        hq -> rear = hq -> rear -> next = newNode;
    }
    
}

/// 从队列中删除一个元素
int delQueue(struct queue *hq) {
    struct Node *p;
    int temp;
    if (hq -> front == NULL) {
        printf("队列为空，无法删除！");
        exit(0);
    }
    /*暂存队首元素以便返回*/
    temp = hq -> front -> data;
    p = hq -> front;
    
    /*暂存队首指针以便回收队尾结点*/
    hq -> front = p -> next;   /*使队首指针指向下一个结点*/
    
    /*若删除后链队为空，则需同时使队尾指针为空*/
    if(hq -> front == NULL) {
        hq -> rear = NULL;
    }
    free(p);      /*回收原队首结点*/
    return temp;    /*返回被删除的队首元素值*/
    
}

/// 读取队首元素
int peekQueue(struct queue *hq) {
    /*若链队为空则停止运行*/
    if(hq -> front == NULL) {
        printf("队列为空！ ");
        exit(0);
    }
    return hq -> front -> data;      /*返回队首元素*/
}

/// 检查链队是否为空，若为空则返回1,否则返回0
int emptyQueue(struct queue *hq) {
    /*判断队首或队尾任一个指针是否为空即可*/
    if(hq -> front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/// 清除链队中的所有元素
void clearQueue(struct queue *hq) {
    struct Node *p = hq -> front;    /*队首指针赋给p*/
    /*依次删除队列中的每一个结点，最后使队首指针为空*/
    while(p != NULL) {
        hq -> front = hq -> front -> next;
        free(p);
        p = hq -> front;
    }
    /*循环结束后队首指针已经为空*/
    hq -> rear = NULL;    /*置队尾指针为空*/
    return;
}








