//
//  Search.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/14.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "Search.h"
#import "Tree.h"

#pragma mark - 顺序查找
int Sequential_Search(int a[], int n, int key) {
    for (int i = 1; i <= n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

// 顺序查找优化 - 带有哨兵查找 没有了 i <= n 的判断
int Sequential_Search2(int a[], int n, int key) {
    int i;
    a[0] = key;
    i = n;
    while (a[i] != key) {
        i--;
    }
    return i;
}

#pragma mark - 折半查找
int Binary_Search(int a[], int n, int key) {
    if (a == NULL) return 0;
    int low, high, mid;
    low = 1;
    high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

#pragma mark - 插值拆入法 - 适合关键字分布均匀的查找表
int InsertValue_Search(int a[], int n, int key) {
    if (a == NULL) return 0;
    int low, high, mid;
    low = 1;
    high = n;
    while (low <= high) {
        mid = low + (high - low) *(a[key] - a[low])/(a[high] - a[low]);
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

#pragma mark - 斐波那契查找
int Fibonacci_Search(int a[], int n, int key) {
    int F[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 555};
    int low, high, mid, i, k;
    low = 1;
    high = n;
    k = 0;
    // 计算n位移斐波那契数列的位置
    while (n > F[k] - 1) {
        k++;
    }
    // 将不满的数值补全
    for (i = n; i < F[k] - 1; i++) {
        a[i] = a[n];
    }
    while (low <= high) {
        mid = low + F[k - 1] - 1;
        // 若查找记录小于当前分割的记录
        if (key < a[mid]) {
            high = mid - 1;
            k -= 1;
        }
        // 若查找记录大于当前分割的记录
        else if (key > a[mid]) {
            low = mid + 1;
            k -= 2;
        } else {
            if (mid <= n) {
                // 相等说明查找到位置
                return mid;
            } else {
                // 说明是补全的数值
                return n;
            }
        }
    }
    
    return 0;
}
#pragma mark - 索引
// https://blog.csdn.net/qq_22238021/article/details/78261630
/*
 - 索引是把一个数据文件的关键码和它对应的数据记录相关联的过程。
 - 每一个关联构成一个索引项，每个索引项至少应包含关键字和其对应的记录在存储器中的位置等信息。
 - 所有索引项的集合构成该文件的索引表。保存在磁盘上的索引表又称索引文件。
 - 索引技术是组织大型数据库以及磁盘文件的一种重要技术。
 - 索引按照结构可以分为线性索引，树形索引和多级索引。
 - 所谓线性索引就是将索引项集合组织为线性结构，也称为索引表。
 */
#pragma mark - 线性索引 - 稠密索引
/*
 稠密索引是指在线性索引的过程中将数据集中的每个记录对应一个索引项。索引项按关键码有序，索引表是有序表。
 当索引文件可以在内存中容纳时，将索引文件驻留内存，可用高效查找方法如二分查找实现索引表上的查找，
 在找到索引项后，可根据其中存放的指向记录的位置信息，可快速找到要找的记录。但若主文件记录数较大，由于是稠密索引，故索引表也会很大，
 甚至无法存储在内存中，可能就需要反复去访问磁盘，查找性能大大下降。
 
 稠密索引不适合在主文件中进行插入或删除一条记录的运算，因为一旦在文件中插入或删除一条记录，
 就必然要引起记录的移动。为了使稠密索引文件按关键码有序而且是顺序存储的，索引就必须更新。
 */

#pragma mark - 线性索引 - 分块索引
/*
 对数据集进行分块，使其分块有序，然后再对每一块建立一个索引项（类似于图书馆的分块）。
 如何减少索引项的个数呢？
 我们可以对数据集进行分块，使其分块有序，然后再对每一块建立一个索引项（类似于图书馆的分块）。
 分块有序是把数据集的记录分成了若干块，并且这些块需要满足两个条件：
 （1）块内无序
    每一块内的记录不要求有序
 （2）块间有序
    比如要求第二块记录的关键字均要大于第一块中所有记录的关键字，第三块要大于第二块。
    只有块间有序才有可能在查找时带来效率。
    对于分块有序的数据集，将每块对应一个索引项，这种索引方法叫做分块索引。
    分块索引的索引项结构分为三个数据项：
    a: 最大关键码--存储每一块中的最大关键字。
    b: 块长--存储每一块中记录的个数以便于循环时使用。
    c: 块首地址--用于指向块首数据元素的指针，便于开始对这一块中记录进行遍历。
 
    在分块索引表中查找，可以分为两步：
    a: 在分块索引表中查找要查的关键字所在块。
    由于分块索引表是块间有序的，因此很容易利用折半插值等算法得到结果。
    b:根据块首指针找到相应的块，并在块中顺序查找关键码。
    因为块中可以是无序的，因此只能顺序查找。
 */
#pragma mark - 线性索引 - 多重索引
/*
 若不仅要按主关键码进行查找，还要按次关键码按给定码值或给定取值范围进行查找，则需在建立主索引的同时，也建立次关键码索引。
 */
#pragma mark - 线性索引 - 倒排索引
/*
 索引项包括次关键码的值和具有该值的各记录的地址，或包括次关键码的一个取值范围和取值在该范围内的所有记录的地址。
 */

#pragma mark - 二叉查找树
/*
 递归查找d二叉树T中是否存在Key
 指针f指向T的双亲，初始值为null
 若查找成功，p指向该结点，返回TRUE
 反之返回p指向最后访问的一个结点，FALSE
 */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    if (!T) {
        *p = f;
        return FALSE;
    } else if (key == T -> data) {
        *p = T;
        return TRUE;
    } else if (key < T -> data) {
        return SearchBST(T -> lChildNode, key, T, p);
    } else {
        return SearchBST(T -> rChildNode, key, T, p);
    }
}

/**
 在二叉查找树中找不到值时，再进行插入操作
 */
Status InsertBST(BiTree *T, int key) {
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p)) {
        s = (BiTree)malloc(sizeof(BiTNode));
        s -> data = key;
        s -> lChildNode = s -> rChildNode = NULL;
        if (!p) {
            // 作为根节点
            *T = s;
        } else if (key < p -> data) {
            p -> lChildNode = s;
        } else {
            p -> rChildNode = s;
        }
        return TRUE;
    } else {
        // 找到了不再插入
        return FALSE;
    }
}

BiTree CreateBST() {
    int i;
    int a[10] = {52, 88, 33, 44, 55, 66, 11, 22 ,33, 1};
    BiTree t = NULL;
    for (i = 0; i < 10; i++) {
        InsertBST(&t, a[i]);
    }
    return t;
}

// 从二叉树中删除结点p，并重接它的左右子树
Status Delete(BiTree *p) {
    BiTree q, s;
    // 右子树为空，则重建它的左子树
    if ((*p) -> rChildNode == NULL) {
        q = *p;
        *p = (*p) -> lChildNode;
        free(q);
    }
    // 左子树为空
    else if ((*p) -> lChildNode == NULL) {
        q = *p;
        *p = (*p) -> rChildNode;
        free(q);
    } else {
        q = *p; s = (*p) -> lChildNode;
        while (s -> rChildNode) {
            q = s; s = s -> rChildNode;
        }
        // 将数据给p
        (*p) ->data  = s -> data;
        if (q != *p) {
            // 重建q的右子树
            q -> rChildNode = s -> lChildNode;
        } else {
            // 重建左的右子树
            q -> lChildNode = s -> lChildNode;
        }
        // 删除 结点 s
        free(s);
    }
    return OK;
}

/*
 删除有三种情况
 - 叶子结点
 - 仅有左或右子树结点
 - 左右子树都有的结点
 */
Status DeleteBST(BiTree *T, int key) {
    if (!*T) return FALSE;
    if (key == (*T) -> data) {
        return Delete(T);
    } else if (key < (*T) -> data) {
        return DeleteBST(&(*T) -> lChildNode, key);
    } else {
        return DeleteBST(&(*T) -> rChildNode, key);
    }
    return OK;
}
