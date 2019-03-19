//
//  Hash.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/17.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "Hash.h"

int m = 0; // 散列表表长度，全局变量

// 初始化散列表
Status InitHashTable(HashTable *H) {
    H -> count = m;
    H -> elem = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        H -> elem[i] = NULLKEY;
    }
    return OK;
}

// 散列函数(哈希函数)
int Hash(int key) {
    // 除留余数法
    return key % m;
}

/// 插入关键字到散列表
void InsertHash(HashTable *H, int key) {
    // 求散列地址
    int address = Hash(key);
    // 如果不为NULLKEY这表示有值了
    while (H -> elem[address] != NULLKEY) {
        // 开放定地址 - 线性探测
        address = (address + 1) % m;
    }
    // 有空位后则插入 key
    H -> elem[address] = key;
    H -> count++;
}

Status SearchHash(HashTable H, int key, int *address) {
    // 求散列地址
    *address = Hash(key);
    while (H.elem[*address] != key) {
        // 开放定地址 - 线性探测
        *address = (*address + 1) % m;
        if (H.elem[*address] == NULLKEY || *address == Hash(key)) {
            // 如果循环到原点，则说明关键字不存在
            return ERROR;
        }
    }
    return OK;
}
