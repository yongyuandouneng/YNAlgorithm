//
//  Graph.c
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/10.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#include "Graph.h"

#pragma mark - 邻接矩阵
// 建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph *G) {
    int i, j, k, w;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G -> numVertexes, &G -> numEdges);
    // 读入顶点信息，建立顶点表
    for (i = 0; i < G -> numVertexes; i++) {
        printf("输入第%d个顶点信息：\n", i + 1);
        scanf("%d",&G -> vexs[i]);
    }
    for (i = 0; i < G -> numVertexes; i++) {
        for (j = 0; j < G -> numVertexes; j++) {
            // 邻接矩阵初始化
            G -> arc[i][j] = INFINITY2;
        }
    }
    // 读入numEdges条边，建立邻接矩阵
    for (k = 0; k < G -> numEdges; k++) {
        printf("输入边(vi, vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d", &i, &j, &w);
        G -> arc[i][j] = w;
        // 无向图，矩阵对称
        G -> arc[j][i] = G -> arc[i][j];
    }
}

#pragma mark - 邻接表
void CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点和边数：\n");
    scanf("%d,%d", &G -> numVertextes, &G -> numEdges);
    for (i = 0; i < G -> numVertextes; i++) {
        printf("输入顶点信息：\n");
        scanf("%d", &G -> adjList[i].data);
        // 将边表置为空表
        G -> adjList[i].firstEdge = NULL;
    }
    // 建立边表
    for (k = 0; k < G -> numEdges; k++) {
        printf("输入边(vi,vj)上的顶点序号：\n");
        scanf("%d,%d", &i, &j);
        // 生成边表结点
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* 邻接序号为j */
        e->adjvex = j;
        /* 将e指针指向当前顶点指向的结点 */
        e->next = G->adjList[i].firstEdge;
        /* 将当前顶点的指针指向e */
        G->adjList[i].firstEdge = e;
        /* 向内存申请空间， */
        /* 生成边表结点 */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* 邻接序号为i */
        e->adjvex = i;
        /* 将e指针指向当前顶点指向的结点 */
        e->next = G->adjList[j].firstEdge;
        /* 将当前顶点的指针指向e */
        G->adjList[j].firstEdge = e;
    }
}
