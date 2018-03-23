#include<stdio.h>
#define  MaxN   101
#define  infine  1000
int a[MaxN][MaxN],N,M;					//N是顶点点数，M是边数
void create()		
{
	int i,j,number1,number2,number3,Length;
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			if(i==j)
				a[i][j]=0;
			else 
				a[i][j]=infine;
		}
	for(i=1;i<=M;i++)
	{
		scanf("%d %d %d",&number1,&number2,&Length);
		a[number1][number2]=a[number2][number1]=Length;
	}
}
void floyd()
{
	int i,j,k;
	for(k=1;k<=N;k++)   
		for(i=1;i<=N;i++)   
     		for(j=1;j<=N;j++)   
  				if(a[i][j]>a[i][k]+a[k][j] )   	//如果 i到j的直接路径大于从i经过k节点到j的路径，那就更新数据
      				a[i][j]=a[i][k]+a[k][j];
}
int judge()
{
	int MaxMin=infine,Q,animal,i,j;
	for(i=1;i<=N;i++)
	{
		Q=0;
		for(j=1;j<=N;j++)
		{
			if(i==j)
				continue;
			else
				if(a[i][j]>Q)
					Q=a[i][j];
		}
		if(Q<MaxMin)
		{
			animal=i;
			MaxMin=Q;
		}
	}
	printf("%d %d",animal,MaxMin);		
}
int main()
{
	int i,j;
	create();
	floyd();
	judge();
	return 0;
}

