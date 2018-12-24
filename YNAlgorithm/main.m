//
//  main.m
//  YNAlgorithm
//
//  Created by ZYN on 16/12/29.
//  Copyright © 2016年 Yongneng Zheng. All rights reserved.
//

#import <Foundation/Foundation.h>
/// LeetCode
#import "LeetCode_206_ReverseLinkedList.h"
/// Search Algorithm
#import "Algorithm.h"
#import "Constant.h"
#import "DataStructureQueue.h"
#import "InterviewAlgorithm.h"
#import "YNAlgorithm-Swift.h"

struct ListNode *getHead () {
    struct ListNode *head = NULL;
    for (int i = 3; i > 0; i--) {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p -> val = i;
        p -> next = head;
        head = p;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        reverseListForRecursive(getHead());
    }
    return 0;
}
