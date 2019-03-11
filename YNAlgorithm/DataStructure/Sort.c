//
//  Sort.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/11.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "Sort.h"

#pragma mark - swap方法
void swap(SortList *L, int i, int j) {
    int temp = L ->r[i];
    L -> r[i] = L -> r[j];
    L -> r[j] = temp;
}

#pragma mark - 冒泡排序
// 冒泡排序 - 简单版
void BubbleSort0(SortList *L) {
    int i, j;
    for (i = 1; i < L -> length; i++) {
        for (j = i + 1; j <= L -> length; j++) {
            if (L -> r[i] > L -> r[j]) {
                swap(L, i, j);
            }
        }
    }
}

// 冒泡排序 - 进阶版
void BubbleSort1(SortList *L) {
    int i, j;
    for (i = 1; i < L -> length; i++) {
        /// 从后面开始往上比较
        for (j = L -> length - 1; j >= i; j--) {
            /// 前者比后者大
            if (L -> r[j] > L -> r[j + 1]) {
                swap(L, j, j + 1);
            }
        }
    }
}

// 冒泡排序 - 优化版
void BubbleSort2(SortList *L) {
    int i, j;
    Status flag = TRUE;
    for (i = 1; i < L -> length && flag; i++) {
        flag = FALSE;
        for (j = L -> length - 1; j >= i; j--) {
            if (L -> r[j] > L -> r[j + 1]) {
                swap(L, j, j + 1);
                flag = TRUE;
            }
        }
        if (!flag) {
            break;
        }
    }
}

#pragma mark - 简单选择排序
void SimpleSelectSort(SortList *L) {
    int i, j, min;
    for (i = 1; i < L -> length; i++) {
        // 将当前下标定义为最小值的下标
        min = i;
        // 循环之后的数据
        for (j = i + 1; j <= L -> length; j++) {
            // 如果有小于当前最小值的关键字，则赋值下标
            if (L -> r[min] > L -> r[j]) {
                min = j;
            }
        }
        /// i != min 说明找到最小值的index
        if (i != min) {
            swap(L, i, min);
        }
    }
}


#pragma mark - 插入排序
