#include "SeqList.h"


//�ڽӾ���ʵ��ͼ�Ĵ洢���Ͷ���
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

//��ʼ��
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
			
			}//MaxWeight��ʾȨֵ�����
		}
		
		G->numOfEdges=0;  //�ߵ�������Ϊ0
		ListInitiate(&G->vertices);  //����˳����ʼ��
}




//�ڴ�Ȩ����ͼG�в��붥��vertex
void InsertVertex(AdjMGraph *G,DataType vertex)
{
	//if(IsVertex(G,vertex)<0)
		if(ListInsert(&G->vertices,G->vertices.size,vertex)==0)//�ڶ���˳���ı�β���붥��vertex
		{
			printf("���붥��ʱ�ռ������޷����룡");
			exit(1);
		}
}

// �ڴ�Ȩ����ͼG�в���һ����v1������ָ���v2�����㣬ȨֵΪweight������� 

void InsertEdge(AdjMGraph *G,int v1,int v2,int weight)
{
	DataType x;
	if(v1!=v2)
	{
		if((ListGet(G->vertices,v1,&x)==0)||(ListGet(G->vertices,v2,&x)==0))
		{
			printf("�����ʱ����v1��v2Խ�����\n");
			exit(1);
		}
		
		G->edge[v1][v2]=weight;
		G->edge[v2][v1]=weight;
		G->numOfEdges++;
	}
}



// �ڴ�Ȩ����ͼG��ɾ��һ����v1������ָ���v2������ı�

void DeleteEdge(AdjMGraph *G,int v1,int v2)
{
	
	
		G->edge[v1][v2]=MaxWeight;
		G->edge[v2][v1]=MaxWeight;
		G->numOfEdges--;
	
}





//ɾ������
//�ڴ�Ȩ����ͼG��ɾ����v������
void DeleteVertex(AdjMGraph *G,int v)
{
	
	int m3,i,j;
		   m3=v-1;
		   if(m3<0||m3>=G->vertices.size)
		   {
			   printf("�Բ��𣬴���·��û������Ҫɾ����·�ɽڵ�\n");
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

int GetFirstVex(AdjMGraph G,int v)
{
    int col;DataType x;
	v=v-1;
    
    if(ListGet(G.vertices,v,&x)==0)
    {
        printf("ȡ��һ���ڽӶ���ʱ����vԽ�����\n");
        exit(1);
	}
	
	for(col=0;col<G.vertices.size;col++)
        if(G.edge[v][col]>0 && G.edge[v][col] < MaxWeight) 
			return col;
		return -1; 
}

int GetNextVex(AdjMGraph G,int v1,int v2)
{
    int col;DataType x;
    
    if((ListGet(G.vertices,v1,&x)==0)||(ListGet(G.vertices,v2,&x)==0))
    {
        printf("ȡ��һ�ڽӶ���ʱ����v1��v2Խ�����\n");
        exit(1);
	}
	if(G.edge[v1][v2]==0)
	{
		printf("v2����v1���ڽӶ���\n");
        exit(1);
	}
	for(col=v2+1;col<G.vertices.size;col++)
        if(G.edge[v1][col]>0 && G.edge[v1][col]<MaxWeight) 
			return col;
        return -1;
}1
void CreatGraph(AdjMGraph *G,DataType v[],int n,RowColWeight W[],int e)
{
	int i,k;
	
	GraphInitiate(G);
	for(i=0;i<n;i++)
	{
			//cout<<n<<endl;
			InsertVertex(G,v[i]);
	}
	for(k=0;k<e;k++)
        InsertEdge(G,W[k].row,W[k].col,W[k].weight);
}




void Dijkstra(AdjMGraph *G, int v0, int distance[], int path[ ])
{ 
	int n = G->vertices.size;
	int *S = (int *)malloc(sizeof(int)*n); //S����
	int minDis, i, j, u;
    	FILE *fp;  
	/*��ʼ��*/
	for(i = 0; i < n; i ++)
	{ 
		distance[i] = G->edge[v0][i];
		S[i] = 0;
		if(i != v0 && distance[i] < MaxWeight)
			path[i] = v0;
		else path[i] = -1;
	}
	S[v0] = 1;
	for(i = 1; i < n; i ++)
	{ 
		minDis = MaxWeight;
		for (j = 0;j < n;j ++)
			if(S[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
			if(minDis == MaxWeight) return;
			S[u] = 1; 
			for(j = 0; j < n; j++)
				if(S[j] == 0 && G->edge[u][j] < MaxWeight &&
					distance[u] + G->edge[u][j] < distance[j])
				{  
					distance[j] = distance[u] + G->edge[u][j];
					path[j] = u;
				}
	}
	printf("Ŀ��·��  ��һ��·��\n");
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
