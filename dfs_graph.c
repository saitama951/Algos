#include "stdio.h"
void print_dfs(int [][6],int ,int );

void main()
{
	int n;
	int a[6][6]={
			1,1,1,0,1,0,
			0,1,0,1,1,1,
			0,0,1,1,1,0,
			0,0,0,1,0,1,
			0,0,0,1,1,0,
			0,0,0,0,0,1
	
			};
	printf("enter the source: ");
	scanf("%d",&n);
	print_dfs(a,6,n);
}

void print_dfs(int a[][6],int size,int n)
{
	int inp[6];
	int out[6];
	int stack[6];
	int i=-1,j,k=0,l=0,m,f=0;
	i++;
	stack[i]=n;
	inp[l]=n;
	l++;
	while(i>=0)
	{
		out[k]=stack[i];
		n=stack[i];
		i--;
		k++;
		for(j=0;j<6;j++)
		{
			if(a[n][j]==1)
			{
				for(m=0;m<l;m++)
				{	
					if(j==inp[m])
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					inp[l]=j;
					l++;
					i++;
					stack[i]=j;
				}
			}
			f=0;

		}
	}
	for(i=0;i<k;i++)
		printf("%c",out[i]+65);
	printf("\n");
}
