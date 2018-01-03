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
	//			printf("ɾ�����ɹ�\n");
		   }
}
