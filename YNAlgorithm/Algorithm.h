//
//  Algorithm.h
//  YNAlgorithm
//
//  Created by ZYN on 2018/4/3.
//  Copyright © 2018年 Yongneng Zheng. All rights reserved.
//

#import "Constant.h"

#pragma mark - 二分法查找
/*
 
 二分法查找
 算法如下：
 1.确定查找范围front=0，end=N-1，计算中项mid=（front+end）/2。
 2.若a[mid]=x或front>=end,则结束查找；否则，向下继续。
 3.若a[mid]<x,说明待查找的元素值只可能在比中项元素大的范围内，则把mid+1的值赋给front，并重新计算mid，转去执行步骤2；若a[mid]>x，说明待查找的元素值只可能在比中项元素小的范围内，则把mid-1的值赋给end，并重新计算mid，转去执行步骤2。
 时间复杂度: O(logN)

 */
static int bisectionMethodRecursion(int a[], int key, int low, int high) {
    
    if (low > high) return -1;
    int mid = (low + high) * 0.5;
    if (a[mid] == key) {
        return a[mid];
    } else if (a[mid] > key) {
        return bisectionMethodRecursion(a, key, low, mid - 1);
    } else {
        return bisectionMethodRecursion(a, key, mid + 1, high);
    }
}

static int bisectionMethod(int a[], int key, int len) {

    int left = 0;
    int right = len - 1;
    int mid = (left + right) * 0.5;
    while (left < right && a[mid] != key) {
        if (a[mid] < key) {
            left = mid + 1;
        } else if(a[mid] > key) {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    if (a[mid] == key) {
        return a[mid];
    }
    return -1;
}

#pragma mark - 快速排序

/**
 快速排序
 基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 https://baike.baidu.com/item/快速排序算法/369842?fr=aladdin&fromid=2084344&fromtitle=快速排序
 */
static void quickSort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
         序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }
        
        a[i] = a[j];
        
//        printArray();
        
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
         a[left]，那么就是给key）*/
        
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
         因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
        
        a[j] = a[i];

    }
    
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    
    printArray();
    quickSort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    quickSort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}

#pragma mark - 归并排序
/**
 * 归并过程为：比较a[i]和b[j]的大小，若a[i]≤b[j]，则将第一个有序表中的元素a[i]复制到r[k]中，并令i和k分别加上1；否则将第二个有序表中的元素b[j]复制到r[k]中，并令j和k分别加上1，如此循环下去，直到其中一个有序表取完，然后再将另一个有序表中剩余的元素复制到r中从下标k到下标t的单元。归并排序的算法我们通常用递归实现，先把待排序区间[s,t]以中点二分，接着把左边子区间排序，再把右边子区间排序，最后把左区间和右区间用一次归并操作合并成有序的区间[s,t]。
    大O表示法中的常量有时候事关重大， 这就是快速排序比合并排序
    快的原因所在。
    时间复杂度 仅次于快速排序、比较稳定
    https://baike.baidu.com/item/归并排序/1639015?fr=aladdin
 */
void merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    /// 折中 比较 取值 赋值
    int i = startIndex, j = midIndex + 1, k = startIndex;
    while(i != midIndex + 1 && j != endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1) {
        tempArr[k++] = sourceArr[i++];
    }
    while(j != endIndex+1) {
        tempArr[k++] = sourceArr[j++];
    }
    /// 赋值数组
    for(i = startIndex; i <= endIndex; i++) {
        sourceArr[i] = tempArr[i];
        printf("%zd、",sourceArr[i]);
    }
    printf("\n");
}

// 内部使用递归
void mergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        /// 递归 折中
        mergeSort(sourceArr, tempArr, startIndex, midIndex);
        mergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}


#pragma mark - 堆排序
/// 调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上） - 升序
void adjustHead (int *a, int i, int length) {
    int temp = a[i];
    for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {
        if (k + 1 < length && a[k] < a[k + 1]) {
            k ++;
        }
        if (a[k] > temp) {
            a[i] = a[k];
            i = k;
        } else {
            break;
        }
        
    }
    a[i] = temp;
    
}

void swap(int *a, int b, int c) {
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}

/**
 * 堆排序的基本思想是：将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。
   将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，
   这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了.
   时间复杂度 O(nlogn)
 */
 
static void heapSort(int *a, int length) {
    
    /// 1.构造大顶堆
    for (int i = length / 2 - 1; i >= 0; i--) {
        adjustHead(a, i, length);
    }
    
    /// 2.调整堆结构+交换堆顶元素与末尾元素
    for (int j = length - 1; j > 0; j--) {
        swap(a, 0, j);
        adjustHead(a, 0, j);
    }
    
}















