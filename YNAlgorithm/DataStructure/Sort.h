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
// 最长上升子序列
// 最长连续上升子序列
// 如何实现大整数相加

#include <stdio.h>
#import "DSGlobalHeader.h"

/*
插入排序
 1.直接插入排序 O(n^2) O(1) 稳定
 2.希尔排序  O(n^3/2) O(1) 不稳定

选择排序
 1.直接选择排序 O(n^2) O(1) 不稳定
 2.堆排序 O(n * logn) O(1) 不稳定
 
交换排序
 1.冒泡排序 O(n^2) O(1) 稳定
 2.快速排序 O(n * logn) O(logn) ~ O(n) 不稳定
 
归并排序 O(n * logn) O(n) 稳定
 
基数排序 O(d(r + n)) O(rd + n) 稳定
 
桶排序 O(n) O(n)

计数排序 O(n + k) O(n) 稳定
 
*/
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

#pragma mark - 冒泡排序进化版 - 快速排序
void QuickSort(SortList *L);

#pragma mark - 直接选择排序
void SimpleSelectSort(SortList *L);

#pragma mark - 直接选择排序进化版 - 堆排序
void HeapSort(SortList *L);

#pragma mark - 插入排序
void InsertSort(SortList *L);

#pragma mark - 插入排序进化版 - 希尔排序 ~ 不稳定 O(n^3/2);
void ShellSort(SortList *L);

#pragma mark - 归并排序
void MergeSortFR(SortList *L);

#pragma mark - 计数排序
void CountSort(SortList *L);

#pragma mark - 计数排序升级版 - 桶排序
void BucketSort(SortList *L);
void BucketSort2(SortList *L);

#pragma mark - 桶排序的拓展 - 基数序
void RadixSort(SortList *L);

#endif /* Sort_h */
