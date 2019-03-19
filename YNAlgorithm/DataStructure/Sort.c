//
//  Sort.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/11.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
// https://blog.csdn.net/mwj327720862/article/details/80498455

#include "Sort.h"

#pragma mark - swap方法
void swap(SortList *L, int i, int j) {
    int temp = L ->r[i];
    L -> r[i] = L -> r[j];
    L -> r[j] = temp;
}

void swap2(SortList *L, int i, int j) {
    L -> r[i] = L -> r[i] + L -> r[j];
    L -> r[j] = L -> r[i] - L -> r[j];
    L -> r[i] = L -> r[i] - L -> r[j];
}

void swap3(SortList *L, int i, int j) {
    L -> r[i] ^= L -> r[j];
    L -> r[j] ^= L -> r[i];
    L -> r[i] ^= L -> r[j];
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

#pragma mark - 冒泡排序进化版 - 快速排序
/*
 交换顺序表L中子表的记录，使参考数到位，并返回其所在的位置
 */
int Partition(SortList *L, int low, int high) {
    // 基准数
    int pivotKey = L -> r[low];
    // 从两端向中间开始扫描
    while (low < high) {
        while (low < high && L -> r[high] >= pivotKey) {
            high--;
        }
        // 将比基准数小的交换到低端
        swap(L, low, high);
        while (low < high && L -> r[low] <= pivotKey) {
            /// 将比基准数大的记录交换到高端
            low++;
        }
        swap(L, low, high);
    }
    return low;
}

void QSort(SortList *L, int low, int high) {
    if (low >= high) return;
    int refIndex = Partition(L, low, high);
    QSort(L, low, refIndex - 1);
    QSort(L, refIndex + 1, high);
}

void QuickSort(SortList *L) {
    QSort(L, 1, L -> length);
}

#pragma mark - 直接选择排序
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

#pragma mark - 直接选择排序进化版 - 堆排序
void HeapAdjust(SortList *L, int i, int m) {
    int temp, j;
    temp = L -> r[i];
    // 沿关键字较大的孩子结点向下筛选
    for (j = 2 * i; j <= m; j *= 2) {
        if (j < m && L -> r[j] < L -> r[j + 1]) {
            ++j;
        }
        if (temp >= L -> r[j]) {
            break;
        }
        // 交换
        L -> r[i] = L -> r[j];
        i = j;
    }
    // 插入
    L -> r[i] = temp;
}

void HeapSort(SortList *L) {
    for (int i = L -> length / 2; i > 0; i --) {
        HeapAdjust(L, i, L -> length);
    }
    
    for (int i = L -> length; i > 1; i--) {
        swap(L, 1, i);
        HeapAdjust(L, 1, i - 1);
    }
}

#pragma mark - 插入排序
void InsertSort(SortList *L) {
    int j = 0;
    int i = 1;
    /// 从i = 2 开始，把前面一个当初标志位，将后续的元素插入到这个位置的前面或者后面
    for (i = i + 1; i <= L -> length; i++) {
        // x需要L -> r[i]插入有序子表
        if (L -> r[i] < L -> r[i - 1]) {
            int temp = L -> r[i];
            // 遍历前面的小于哨兵的数据 往后移动
            for (j = i - 1; j > 0 && L -> r[j] > temp; j--) {
                L -> r[j + 1] = L -> r[j];
            }
            /// 将哨兵位置插入到移动后的j+1位置处
            L -> r[j + 1] = temp;
        }
    }
}

#pragma mark - 插入排序进化版 - 希尔排序 ~ 不稳定 O(n^3/2);
void ShellSort(SortList *L) {
    int i, j, increment;
    increment = L -> length;
    do {
        // 增量序列
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= L -> length; i++) {
            if (L -> r[i] < L -> r[i - increment]) {
                // 需要将L -> r[i] 插入有序增量子表
                int temp;
                temp = L -> r[i];
                for (j = i - increment; j > 0 &&  L -> r[j] > temp; j -= increment) {
                    // 记录后移，插入查找位置
                    L -> r[j + increment] = L -> r[j];
                }
                // 插入
                L -> r[j + increment] = temp;
            }
        }
    } while(increment > 1);
}

#pragma mark - 归并排序
void MergeFR(int SR[], int s, int m, int e) {
    // 创建临时数据存放合并的数据
    int *temp = malloc((e - s + 1) * sizeof(int));
    int i = s;
    int j = m + 1;
    int k = 0;
    while (i <= m && j <= e) {
        if (SR[i] <= SR[j]) {
            temp[k++] = SR[i++];
        } else {
            temp[k++] = SR[j++];
        }
    }
    
    while (i <= m) {
        temp[k++] = SR[i++];
    }
    
    while (j <= e) {
        temp[k++] = SR[j++];
    }
    // 把排序好的数据放入进去
    for (i = 0; i < k; i++) {
        SR[s + i] = temp[i];
    }
    
    free(temp);
}

void MsortFR(int SR[], int s, int e) {
    if (SR == NULL || s >= e) return;
    int m = (s + e) * 0.5;
    MsortFR(SR, s, m);
    MsortFR(SR, m + 1, e);
    MergeFR(SR, s, m, e);
}

#pragma mark - 计数排序
void CountSort(SortList *L) {
    // 通过max和min计算出临时数组所需要开辟的空间大小
    int max = L -> r[1];
    int min = L -> r[1];
    int i, j;
    for (i = 1; i <= L -> length; i++) {
        if (L -> r[i] > max) {
            max = L -> r[i];
        }
        if (L -> r[i] < min) {
            min = L -> r[i];
        }
    }
    int range = max - min + 1;
    // 使用calloc将数组都初始化为0
    int *tempR = calloc(range, sizeof(int));
    // 使用临时数组记录原始数组中每个数的个数
    for (i = 1; i <= L -> length; i++) {
        // 注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
        tempR[L -> r[i] - min]++;
    }
    j = 1;
    // 根据统计结果，重新对元素进行回收
    for (i = 0; i < range; i++) {
        while (tempR[i]--) {
            // 注意：要将i的值加上min才能还原到原始数据
            L -> r[j++] = i + min;
        }
    }
    // 释放临时数组
    free(tempR);
}

#pragma mark - 计数排序升级版 - 桶排序
typedef struct BucketE {
    ElemType *data;
    int length;
} BucketE;

void BucketSort(SortList *L) {
    int max = L -> r[1];
    int min = L -> r[1];
    int i, j;
    for (i = 1; i <= L -> length; i++) {
        if (L -> r[i] > max) {
            max = L -> r[i];
        }
        if (L -> r[i] < min) {
            min = L -> r[i];
        }
    }
    int d = max - min;
    int bucketNum = L -> length;
    // 创建桶
    BucketE **bucketA = malloc(sizeof(BucketE) * bucketNum);
    for (i = 0; i < bucketNum; i++) {
        BucketE *bucketSub = malloc(sizeof(BucketE));
        bucketSub -> data = malloc(sizeof(ElemType) * bucketNum);
        bucketSub -> length = 0;
        bucketA[i] = bucketSub;
    }
    // 放入桶
    for (i = 1; i <= L -> length; i++) {
         // (当前值-最小值) / (最大值-最小值) * (桶个数 - 1 ) 按比例分配
        int num = (int)((L -> r[i] - min) * (bucketNum - 1) / d);
        BucketE *bucketSub = bucketA[num];
        bucketSub -> data[bucketSub -> length++] = L -> r[i];
    }
    // 内部排序 & 合并
    int index = 1;
    for (i = 0; i < bucketNum; i++) {
        BucketE *bucketSub = bucketA[i];
        // 归并
        MsortFR(bucketSub -> data, 0, bucketSub -> length - 1);
        for (j = 0; j < bucketSub -> length; j++) {
            int x = bucketSub -> data[j];
            L -> r[index++] = x;
        }
    }
    // 释放
    for (i = 0; i < bucketNum; i++) {
        BucketE *bucketSub = bucketA[i];
        free(bucketSub -> data);
        free(bucketSub);
    }
    free(bucketA);
}

void BucketSort2(SortList *L) {
    int max = L -> r[1];
    int min = L -> r[1];
    int i, j;
    for (i = 1; i <= L -> length; i++) {
        if (L -> r[i] > max) {
            max = L -> r[i];
        }
        if (L -> r[i] < min) {
            min = L -> r[i];
        }
    }
    int d = max - min;
    int bucketNum = L -> length;
    int *buckets[bucketNum]; // 桶空间
    for (int i = 0; i < bucketNum; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * (L -> length + 1));
        buckets[i][0] = 0; // index 为0处记录这组数据的个数
    }
    // 放入桶
    for (i = 1; i <= L -> length; i++) {
        // (当前值-最小值) / (最大值-最小值) * (桶个数 - 1 ) 按比例分配
        int num = (int)((L -> r[i] - min) * (bucketNum - 1) / d);
        int index = ++buckets[num][0];
        buckets[num][index] = L -> r[i];
    }
    // 内部排序 & 合并
    int index = 1;
    for (i = 0; i < bucketNum; i++) {
        // 归并
        MsortFR(buckets[i], 1, buckets[i][0] - 1);
        for (j = 1; j <= buckets[i][0]; j++) {
            L -> r[index++] = buckets[i][j];
        }
        buckets[i][0] = 0;
    }
    for (int i = 0; i < bucketNum; i++) {
        free(buckets[i]);
    }
}

#pragma mark - 桶排序的拓展 - 基数序
int GetNumInPos(int num, int pos) {
    int temp = 1;
    for (int i = 0; i < pos - 1; i++) {
        temp *= 10;
    }
    return (num / temp) % 10;
}

int GetMaxLen(SortList *L) {
    int max = L -> r[1];
    for (int i = 2; i <= L -> length ; i++) {
        if (L -> r[i] > max) {
            max = L -> r[i];
        }
    }
    int count = 0;
    while(max != 0) {
        max /= 10;
        count++;
    }
    return count;
}

void RadixSort(SortList *L) {
    int numSpace = 10;
    int *radixArrays[numSpace]; // 0 ~ 9 的序列空间
    for (int i = 0; i < numSpace; i++) {
        radixArrays[i] = (int *)malloc(sizeof(int) * (L -> length + 1));
        radixArrays[i][0] = 0; // index 为0处记录这组数据的个数
    }
    int count = GetMaxLen(L);
    for (int pos = 1; pos <= count; pos++) {
        for (int i = 1; i <= L -> length; i++) {
            // 按位数存入
            int num = GetNumInPos(L -> r[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = L -> r[i];

        }
        int j = 1;
        for (int i = 0; i < numSpace; i++) { // 收集
            for (int k = 1; k <= radixArrays[i][0]; k++) {
                int result = radixArrays[i][k];
                L -> r[j++] = result;
            }
            radixArrays[i][0] = 0; // 复位
        }
    }
    for (int i = 0; i < numSpace; i++) {
        free(radixArrays[i]);
    }
}
