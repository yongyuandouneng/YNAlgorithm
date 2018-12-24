//
//  InterviewAlgorithm.h
//  YNAlgorithm
//
//  Created by ZYN on 2018/8/27.
//  Copyright © 2018年 Yongneng Zheng. All rights reserved.
//

#import "Constant.h"

/// 算法奇数排在前面，偶数排在后面 - 遍历数组 判断 奇数 偶数 从头和尾部加入到新数组中
static void sortAjust (int arr[], int n) {
    
    int resultArray[n];
    int k = 0;
    int m = n - 1;
    
    for (int i = 0; i < n; i++) {
        int a = arr[i];
        if (a % 2 == 1) {
            resultArray[k] = a;
            k++;
        } else {
            resultArray[m] = a;
            m--;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", resultArray[i]);
    }
}

///判断一个字符串是否所有的大写字母都在小写字母前面
static bool judgeUpperAndLower(char a[]) {
    
    long n = strlen(a);
    
    int lower_index = -1;
    int upper_index = -1;
    
    for (int i = 0; i < n; i++) {
        char c = a[i];
        if (c >= 'a' && c <= 'z') { /// 小写
            lower_index = i;
        } else if (c > 'A' && c <= 'Z') { /// 大写
            upper_index = i;
        }
        if (lower_index != -1 && upper_index != -1) {
            if (lower_index < upper_index) {
                return NO;
            }
        }
    }
    return YES;
}


