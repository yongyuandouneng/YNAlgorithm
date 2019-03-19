//
//  InterviewAlgorithm.h
//  YNAlgorithm
//
//  Created by ZYN on 2018/8/27.
//  Copyright © 2018年 Yongneng Zheng. All rights reserved.
//

#pragma mark - 算法奇数排在前面，偶数排在后面 - 遍历数组 判断 奇数 偶数 从头和尾部加入到新数组中
void sortAjust (int arr[], int n) {
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

#pragma mark - 判断一个字符串是否所有的大写字母都在小写字母前面
bool judgeUpperAndLower(char a[]) {
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

#pragma mark - 求无序数组中的中位数
int quickSort(int a[], int star, int end) {
    if (star >= end) return 0;
    int low = star;
    int high = end;
    int key = a[end];
    
    while (low < high) {
        /// 左边比key大的值
        while (low < high && a[low] <= key) {
            ++low;
        }
        /// 右边比key小的值
        while (low < high && a[high] >= key) {
            --high;
        }
        
        if (low < high) {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
    int temp = a[high];
    a[high] = a[end];
    a[end] = temp;
    return low;
}

/*
 * 求无序数组的中位数
 * 利用快排思想对数组进行排序，如果low大于中间数则在左边区间寻找，反之，在右边寻找。
 */
int findMedian(int a[], int aLen) {
    int star = 0;
    int end = aLen - 1;
    int mid = (aLen - 1) / 2;
    int div = quickSort(a, star, end);
    while (mid != div) {
        if (div > mid) {
            div = quickSort(a, star, div - 1);
        } else {
            div = quickSort(a, div + 1, end);
        }
    }
    if (aLen % 2 == 1) {
        return a[mid];
    } else {
        return (a[end / 2] + a[(end/2 + 1)]) / 2;
    }
}

#pragma mark - 查找两个子视图的共同父视图
//+ (NSArray <UIView *> *)findCommonSuperView:(UIView *)firstView secondView:(UIView *)secondView {
//    NSArray <UIView *>* firstSuperViews = [self findSuperView:firstView];
//    NSArray <UIView *>* secondSuperViews = [self findSuperView:secondView];
//    NSMutableArray *arrayM = @[].mutableCopy;
//    int i = 0;
//    /// 小于最小值
//    while (i < MIN(firstSuperViews.count, secondSuperViews.count)) {
//        /// 倒序遍历判断
//        UIView *firstSuperView = firstSuperViews[firstSuperViews.count - i - 1];
//        UIView *secondSuperView = secondSuperViews[secondSuperViews.count - i - 1];
//        i++;
//        if (firstSuperView == secondSuperView) {
//            [arrayM addObject:firstSuperView];
//        } else {
//            break;
//        }
//    }
//    return arrayM;
//}
//
//+ (NSArray <UIView *> *)findSuperView:(UIView *)view {
//    NSMutableArray *arrayM = @[].mutableCopy;
//    UIView *temp = view;
//    while (temp) {
//        UIView *superView = temp.superview;
//        if (superView) {
//            [arrayM addObject:superView];
//        }
//        temp = superView;
//    }
//    return arrayM;
//}

#pragma mark - 在一个字符中找到第一个只出现一次的字符
char lookChar(char cha[]) {
    int maxLen = 256;
    int arr[maxLen];
    
    for (int i = 0; i < maxLen; i++) {
        arr[i] = 0;
    }
    
    for (int i = 0; i < strlen(cha); i++) {
        char c = cha[i];
        arr[c]++;
    }
    
    int i = 0;
    char result = '\0';
    while (i < maxLen) {
        if (arr[i] == 1) {
            result = i;
            break;
        }
        i++;
    }
    return result;
}

#pragma mark - 有序数组合并
/// 先依次比较取小的数据往结果数组里面存，最后放剩下的数据
void comebineOrderArray(int a[], int aLen, int b[], int bLen, int r[]) {
    int p = 0;
    int q = 0;
    int i = 0;
    while (p < aLen && q < bLen) {
        int aa = a[p];
        int bb = b[q];
        if (aa <= bb) {
            p++;
            r[i++] = aa;
        } else {
            q++;
            r[i++] = bb;
        }
    }
    while (q < bLen) {
        r[i++] = b[q++];
    }
    while (p < aLen) {
        r[i++] = b[p++];
    }
}

//int a[5] = {1, 3, 6, 7, 9};
//int b[8] = {2, 3, 5, 6, 8, 10, 11, 12};
//int result[13];
//comebineOrderArray(a, 5, b, 8, result);
//printf("result is ");
//for (int i = 0; i < 13; i++) {
//    printf("%d ", result[i]);
//}

#pragma mark - 单链表反转
struct RNode {
    int data;
    struct RNode *next;
};

struct RNode* reverseList(struct RNode *head) {
    struct RNode *p = head;
    struct RNode *newH = NULL;
    while (p != NULL) {
        // 记录下一个结点
        struct RNode *temp = p -> next;
        // 当前结点next指向新头结点
        p -> next = newH;
        // 更新头结点
        newH = p;
        // 移动p指针到下一个结点位置
        p = temp;
    }
    return newH;
}

struct RNode* constructList(void) {
    struct RNode *head = NULL;
    struct RNode *cur = NULL;
    for (int i = 1; i < 5; i++) {
        struct RNode *node=  malloc(sizeof(struct RNode));
        node -> data = i;
        if (head == NULL) {
            head = node;
        } else {
            cur -> next = node;
        }
        cur = node;
    }
    return head;
}

void printList(struct RNode *head) {
    struct RNode *temp = head;
    while (temp != NULL) {
        printf("node is %d \n", temp -> data);
        temp = temp -> next;
    }
}

#pragma mark - 大整数相加 - 转整型数组 倒序相加 大于>10进位+1
char * maxPlus(char *arr1, char *arr2) {
    if (!arr1 && !arr2) {
        return "";
    }
    if (!arr1) {
        return arr2;
    }
    if (!arr2) {
        return arr1;
    }
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    int i, f = 0;
    int a[201] = {0};
    int b[201] = {0};
    int sum[202] = {0};
    int j = 0;
    for(i = len1 - 1;i >= 0;i--) {
        a[j++] = arr1[i] - '0';
    }
    j = 0;
    for(i = len2 - 1; i >= 0; i--) {
        b[j++] = arr2[i] - '0';
    }
    int max = (len1 > len2) ? len1 : len2;
    for(i = 0;i < max; i++) {
        sum[i] = a[i] + b[i];
    }
    for(i = 0;i < max; i++) {
        if(sum[i] >= 10 && i < max - 1) {
            sum[i + 1]++;
            sum[i] -= 10;
        }
        if(sum[i] >= 10 && i == max-1) {
            f = 1;
            sum[i + 1]++;
            sum[i]-=10;
        }
    }
    
    printf("计算结果为：");
    max = f == 1 ? (max + 1) : max;
    char *resultChar = malloc(sizeof(char) * (max));
    j = 0;
    for(i = max - 1;i >= 0; i--) {
        char temp = sum[i] + '0';
        resultChar[j++] = temp;
    }
    printf("%s", resultChar);
    return resultChar;
}
