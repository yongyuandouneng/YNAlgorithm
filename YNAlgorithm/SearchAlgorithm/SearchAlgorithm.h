//
//  SearchAlgorithm.h
//  YNAlgorithm
//
//  Created by ZYN on 2018/9/11.
//  Copyright © 2018年 Yongneng Zheng. All rights reserved.
//

/// 有序数组的折半查找 以 头下标
static int binarySearch(int *a, int n, int key) {
    int low, heigh, mid;
    low = 1,
    heigh = n;
    while (low <= heigh) {
        mid = (low + heigh) * 0.5;
        if (key < a[mid]) {
            height = mid - 1;
        } else if (key > a[mid]){
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}
