#include "stdio.h"
#define inf 99

int min(int ,int );

void main()
{
	int a[9][9]={
			0,3,1,inf,4,inf,2,inf,1,
			3,0,inf,3,1,3,4,inf,inf,
			1,inf,0,1,3,inf,inf,3,2,
			inf,3,1,0,2,2,inf,4,inf,
			4,1,3,2,0,inf,inf,inf,inf,
			inf,3,inf,2,inf,0,5,4,inf,
			2,4,inf,inf,inf,5,0,inf,5,
			inf,inf,3,4,inf,4,inf,0,6,
			1,inf,2,inf,inf,inf,5,6,0
			};
	int i,j,k;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			for(k=0;k<9;k++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;

}

/*---------------OUTPUT--------------------
0 3 1 2 4 4 2 4 1 
3 0 4 3 1 3 4 7 4 
1 4 0 1 3 3 3 3 2 
2 3 1 0 2 2 4 4 3 
4 1 3 2 0 4 5 6 5 
4 3 3 2 4 0 5 4 5 
2 4 3 4 5 5 0 6 3 
4 7 3 4 6 4 6 0 5 
1 4 2 3 5 5 3 5 0 
----------------END------------------------*/
