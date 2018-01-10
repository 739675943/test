#include "a.h"

void ListInitiate(SeqList *L); 
int ListLength(SeqList L) ; 
int ListInsert(SeqList *L, int i, DataType x);
int ListDelete(SeqList *L, int i, DataType *x);
int ListGet(SeqList L, int i, DataType *x);

void GraphInitiate(AdjMGraph *G);
void InsertVertex(AdjMGraph *G,DataType vertex);
void InsertEdge(AdjMGraph *G,int v1,int v2,int weight);
void DeleteEdge(AdjMGraph *G,int v1,int v2);
void DeleteVertex(AdjMGraph *G,int v);
int GetFirstVex(AdjMGraph G,int v);
int GetNextVex(AdjMGraph G,int v1,int v2);
void CreatGraph(AdjMGraph *G,DataType v[],int n,RowColWeight W[],int e);
void Dijkstra(AdjMGraph *G, int v0, int distance[], int path[ ]);
