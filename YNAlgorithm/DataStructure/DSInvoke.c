//
//  DSInvoke.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/14.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "DSInvoke.h"

void DS_LinearList() {
    Node *head = CreateListHead(5);
    InsertElemForC(head, 1, 10);
    int a;
    DeleteElemForC(head, 2, &a);
    printf("\n");
    while (head) {
        head = head -> next;
        if (head) {
            printf("%d ", head -> data);
        }
    }
    printf("\n");
}

void DS_Tree() {

}

void DS_Graph() {
    MGraph G;
    CreateMGraph(&G);
    printf("1");
}

void DS_Search() {

}

void DS_Hash() {

}

void DS_Sort() {
    SortList L = {{0, 80, 25, 123, 40, 20, 10, 50, 7011}, 8};

    for (int i = 0; i <= L.length; i++) {
        printf(" %d ", L.r[i]);
    }
    printf("\n");
    //            BubbleSort0(&L);
    //            BubbleSort1(&L);
    //            BubbleSort2(&L);
    //            SimpleSelectSort(&L);
    //            HeapSort(&L);
    //            InsertSort(&L);
    //            ShellSort(&L);
    //            MergeSort(&L);
    //            QuickSort(&L);
    //            CountSort(&L);
    //            BucketSort(&L);
    //            BucketSort2(&L);
    RadixSort(&L);
    for (int i = 0; i <= L.length; i++) {
        printf(" %d ", L.r[i]);
    }
    printf("\n");
}
