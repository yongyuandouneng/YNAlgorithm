//
//  Graph.h
//  YNAlgorithm
//
//  Created by ZYN on 2019/3/10.
//  Copyright © 2019 Yongneng Zheng. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#import "DSGlobalHeader.h"

// 顶点类型
typedef int VertexType;
// 边的权值类型
typedef int EdgeType;
// 最大顶点数
#define MAXVEX 100
// 代表 无穷大
#define INFINITY2 65535

typedef struct {
    // 顶点表
    VertexType vexs[MAXVEX];
    // 邻接矩阵 | 边表
    EdgeType arc[MAXVEX][MAXVEX];
    // 顶点数 和 边数
    int numVertexes, numEdges;
} MGraph;


// 建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph *G);

#pragma mark - 邻接表
// 边表结点
typedef struct EdgeNode {
    // 邻接点域，存储该顶点对应的下标
    int adjvex;
    // 权值
    EdgeType weight;
    // 节点，指向下一个邻接点
    struct EdgeNode *next;
} EdgeNode;

// 顶点表结构
typedef struct VertextNode {
    // 存储的信息
    VertexType data;
    EdgeNode *firstEdge;
} vertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    // 顶点数和边数
    int numVertextes, numEdges;
} GraphAdjList;



#endif /* Graph_h */
