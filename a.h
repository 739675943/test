
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
	SeqList vertices;  //��Ŷ����˳���
	int edge[MaxVertices][MaxVertices];//��űߵ��ڽӾ���
	int numOfEdges;  //�ߵ���Ŀ
}AdjMGraph;//ͼ�Ľṹ�嶨��

typedef struct
{
    int row;  //���±�
    int col;  //���±� 
    int weight;  //Ȩֵ
}RowColWeight;//����Ϣ�ṹ�嶨��
