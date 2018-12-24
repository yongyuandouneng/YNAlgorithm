//
//  DataStructureQueue.h
//  YNAlgorithm
//
//  Created by ZYN on 2018/4/15.
//  Copyright © 2018年 Yongneng Zheng. All rights reserved.
//
#pragma mark - 链表队列
struct Node {
    int data;            /// 值域
    struct Node *next;   /// 链表指针
};

struct queue {
    struct Node *front;  /// 队首指针
    struct Node *rear;  /// 队尾指针
};

/// 初始化queue
void initQueue(struct queue *hq);

/// 向链表队列插入一个元素
void insertQueue(struct queue *hq, int x);

/// 从队列中删除一个元素
int delQueue(struct queue *hq);

/// 读取队首元素
int peekQueue(struct queue *hq);

/// 检查链队是否为空，若为空则返回1,否则返回0
int emptyQueue(struct queue *hq);
    
/// 清除链队中的所有元素
void clearQueue(struct queue *hq);






