//
//  main.m
//  YNAlgorithm
//
//  Created by ZYN on 16/12/29.
//  Copyright © 2016年 Yongneng Zheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinearList.h"
#import "Tree.h"
#import "Graph.h"
#import "Sort.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Node *head = CreateListHead(5);
        InsertElemForC(head, 1, 10);
//        int a;
//        DeleteElemForC(head, 2, &a);
        while (head) {
            head = head -> next;
            if (head) {
                NSLog(@"%d", head -> data);
            }
        }
        NSLog(@"finished");
    }
    return 0;
}
