
#include <stdlib.h>
#include <malloc.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef int DataType;
#define MaxSize 10
#define MaxVertices 10
#define MaxWeight 10000
typedef struct
{
	DataType list[MaxSize] ;
	int size ;
}SeqList;
typedef struct
{
	SeqList vertices;  //存放顶点的顺序表
	int edge[MaxVertices][MaxVertices];//存放边的邻接矩阵
	int numOfEdges;  //边的数目
}AdjMGraph;//图的结构体定义

typedef struct
{
    int row;  //行下标
    int col;  //列下标 
    int weight;  //权值
}RowColWeight;//边信息结构体定义
