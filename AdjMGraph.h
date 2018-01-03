#include "SeqList.h"


//邻接矩阵实现图的存储类型定义
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

//初始化
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




//在带权有向图G中插入顶点vertex
void InsertVertex(AdjMGraph *G,DataType vertex)
{
	//if(IsVertex(G,vertex)<0)
		if(ListInsert(&G->vertices,G->vertices.size,vertex)==0)//在顶点顺序表的表尾插入顶点vertex
		{
			printf("插入顶点时空间已满无法插入！");
			exit(1);
		}
}

// 在带权有向图G中插入一条第v1个顶点指向第v2个顶点，权值为weight的有向边 

void InsertEdge(AdjMGraph *G,int v1,int v2,int weight)
{
	DataType x;
	if(v1!=v2)
	{
		if((ListGet(G->vertices,v1,&x)==0)||(ListGet(G->vertices,v2,&x)==0))
		{
			printf("插入边时参数v1和v2越界出错！\n");
			exit(1);
		}
		
		G->edge[v1][v2]=weight;
		G->edge[v2][v1]=weight;
		G->numOfEdges++;
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
			   
	//		   for(i=m3;i<G->vertices.size;i++)
				   for(j=0,i=m3;j<G->vertices.size;j++)
				   {
                       G->edge[j][i]=MaxWeight;

				   }
	//			  for(i=m3;i<G->vertices.size;i++)
					  for(i=m3,j=0;j<G->vertices.size;j++)
						 G->edge[i][j]=MaxWeight;
	//		   for(i=m3;i<G->vertices.size;i++)
//				   G->vertices.list[i]=G->vertices.list[i]-1;
	//		       G->vertices.size--;
	//			printf("删除结点成功\n");
		   }
}
