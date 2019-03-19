//
//  Hash.h
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/17.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#ifndef Hash_h
#define Hash_h

#import "DSGlobalHeader.h"

#define NULLKEY -32768

typedef struct {
    ElemType *elem; // 动态数组
    int count; // 当前数据个数
} HashTable;


#endif /* Hash_h */
