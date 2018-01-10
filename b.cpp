#include "b.h"
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



//置带权有向图G为空图
void GraphInitiate(AdjMGraph *G)
{
	int i,j;
	
	for(i=0;i<MaxVertices;i++)
		for(j=0;j<MaxVertices;j++)
		{
			if(i==j) {
				G->edge[i][j]=0;
				
			}
			else  {
				G->edge[i][j]=MaxWeight; 
			
			}//MaxWeight表示权值无穷大
		}
		
		G->numOfEdges=0;  //边的条数置为0
		ListInitiate(&G->vertices);  //顶点顺序表初始化
}




//在带权有向图G中插入顶点vertex。如果图中已经有顶点vertex,则图不变
void InsertVertex(AdjMGraph *G,DataType vertex)
{
	//if(IsVertex(G,vertex)<0)
		if(ListInsert(&G->vertices,G->vertices.size,vertex)==0)//在顶点顺序表的表尾插入顶点vertex
		{
			printf("插入顶点时空间已满无法插入！");
			exit(1);
		}
}




// 在带权有向图G中删除一条第v1个顶点指向第v2个顶点的边
void DeleteEdge(AdjMGraph *G,int v1,int v2)
{
	
	
		G->edge[v1][v2]=MaxWeight;
		G->edge[v2][v1]=MaxWeight;
		G->numOfEdges--;
	
}





//删除顶点
//在带权有向图G中删除第v个顶点
void DeleteVertex(AdjMGraph *G,int v)
{
	
	int m3,i,j;
		   m3=v-1;
		   if(m3<0||m3>=G->vertices.size)
		   {
			   printf("对不起，此链路内没有您想要删除的路由节点\n");
			   exit(0);
		   }
		   else 
		   { 
			   
				   for(j=0,i=m3;j<G->vertices.size;j++)
				   {
                       G->edge[j][i]=MaxWeight;

				   }
					  for(i=m3,j=0;j<G->vertices.size;j++)
						 G->edge[i][j]=MaxWeight;
		   }
}
//在带权有向图G中取第v个顶点的第一个邻接顶点，如果这样的邻接顶点存在，则返回该顶点在顶点顺序表的序号，否则返回-1
int GetFirstVex(AdjMGraph G,int v)
{
    int col;DataType x;
	v=v-1;
    
    if(ListGet(G.vertices,v,&x)==0)
    {
        printf("取第一个邻接顶点时参数v越界出错！\n");
        exit(1);
	}
	
	//寻找邻接矩阵v行中从最左开始第一个值非零且非无穷大的权值对应的顶点
	for(col=0;col<G.vertices.size;col++)
        if(G.edge[v][col]>0 && G.edge[v][col] < MaxWeight) 
			return col;
		return -1; 
}

//在带权有向图G中取第v1个顶点的继邻接结点第v2个顶点之后的下一个邻接结点
int GetNextVex(AdjMGraph G,int v1,int v2)
{
    int col;DataType x;
    
    if((ListGet(G.vertices,v1,&x)==0)||(ListGet(G.vertices,v2,&x)==0))
    {
        printf("取下一邻接顶点时参数v1和v2越界出错！\n");
        exit(1);
	}
	if(G.edge[v1][v2]==0)
	{
		printf("v2不是v1的邻接顶点\n");
        exit(1);
	}
	//寻找邻接矩阵v行中从第v2+1列开始的第一个值非零且非无穷大的权值对应的顶点
	for(col=v2+1;col<G.vertices.size;col++)
        if(G.edge[v1][col]>0 && G.edge[v1][col]<MaxWeight) 
			return col;
        return -1;
}

//创建有向图G，通过在空图G中插入n个顶点和e条边实现
void CreatGraph(AdjMGraph *G,DataType v[],int n,RowColWeight W[],int e)
{
	int i,k;
	
	GraphInitiate(G);
	for(i=0;i<n;i++)
	{
			//cout<<n<<endl;
			InsertVertex(G,v[i]);
	}
}
void Dijkstra(AdjMGraph *G, int v0, int distance[], int path[ ])
/*带权图G从下标0顶点到其它顶点的最短距离distance
和最短路径上顶点前驱下标path*/
{ 
	int n = G->vertices.size;
	int *S = (int *)malloc(sizeof(int)*n); //S数组
	int minDis, i, j, u;
    	FILE *fp;  
	/*初始化*/
	for(i = 0; i < n; i ++)
	{ 
		distance[i] = G->edge[v0][i];
		S[i] = 0;
		if(i != v0 && distance[i] < MaxWeight)
			path[i] = v0;
		else path[i] = -1;
	}
	S[v0] = 1;
	//在当前还未找到最短路径的顶点集中选取具有最短距离的顶点u
	for(i = 1; i < n; i ++)
	{ 
		minDis = MaxWeight;
		for (j = 0;j < n;j ++)
			if(S[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
			//当已不再存在路径时算法结束
			if(minDis == MaxWeight) return;
			S[u] = 1; //标记顶点u已从集合T加入到集合S中
			//修改从v0到其它顶点的最短距离和最短路径
			for(j = 0; j < n; j++)
				if(S[j] == 0 && G->edge[u][j] < MaxWeight &&
					distance[u] + G->edge[u][j] < distance[j])
				{  
					distance[j] = distance[u] + G->edge[u][j];
					path[j] = u;
				}
	}
	printf("目的路由  下一跳路由\n");
	 fp=fopen("luyoubiao.txt","w");
	for(i=0;i<n;i++)
	{
		if (i==v0) continue;
		j=i;
		while(path[j]!=v0)
		{
			j=path[j];
			if (j==-1) break;
		}
		printf("%5d%12d\n",i+1,j+1);
        fprintf(fp,"%5d%12d\n",i+1,j+1);
	}
	fclose(fp);
}