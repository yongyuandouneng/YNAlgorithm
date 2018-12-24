//
//  LeetCode_206_ReverseLinkedList.h
//  YNLeetCode
//
//  Created by ZYN on 2018/12/20.
//  Copyright © 2018 yongneng. All rights reserved.
//  206 反转链表

struct ListNode {
    int val;
    struct ListNode *next;
} ;

/// 临时链表反转 O(n) O(1)
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    struct ListNode *last = NULL, *temp = NULL;
    while (head) {
        temp = head -> next;
        head -> next = last;
        last = head;
        head = temp;
    }
    return last;
}

/// 递归翻转链表
struct ListNode* reverseListForRecursive(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    /// 取得下一个节点
    struct ListNode *p = head -> next;
    /// 递归去调转
    struct ListNode *pNewHead = reverseListForRecursive(p);
    /// 这里调转指针指向
    p -> next = head;
    head -> next = NULL;
    return pNewHead;
}
// 1 -> 2 / 1 -> 2 -> 3 / 1 -> 2 -> 3 -> 4 
struct ListNode *reverseListFor (struct ListNode *head) {
    /// 终止条件
    if (head == NULL || head -> next == NULL) return head;
    struct ListNode *p = head -> next;
    struct ListNode *pNewhead = reverseListForRecursive(p);
    p -> next = head;
    head -> next = NULL;
    return pNewhead;
}


struct ListNode* reverseList2(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    struct ListNode *array[5];
    struct ListNode *last = NULL;
    int i = -1;
    while (head) {
        i ++;
        array[i] = head;
        head = head -> next;
    }
    /// 末尾节点
    struct ListNode *node = array[i];
    for (int j = i - 1; j >= 0; j--) {
        node -> next = array[j];
        node = array[j - 1];
    }
    return node;
}


