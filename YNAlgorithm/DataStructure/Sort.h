//
//  Sort.h
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/11.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#ifndef Sort_h
#define Sort_h
// TopK算法  - 查找最大的k个元素
#include <stdio.h>
#import "DSGlobalHeader.h"

typedef struct {
    // 用于存储要排序数组，r[0]用作哨兵或临时变量
    int r[MAXSIZE + 1];
    // 用于记录顺序表的长度
    int length;
} SortList;

#pragma mark - 冒泡排序
// 冒泡排序 - 简单版
void BubbleSort0(SortList *L);
// 冒泡排序 - 进阶版
void BubbleSort1(SortList *L);
// 冒泡排序 - 优化版
void BubbleSort2(SortList *L);

#pragma mark - 简单选择排序
void SimpleSelectSort(SortList *L);

#pragma mark - 插入排序


#endif /* Sort_h */
