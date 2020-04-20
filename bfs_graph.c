#include "stdio.h"

void bfs_traversal(int [][6],int );
										
void main()
{
	int a[6][6]={			//graph
			1,1,1,0,1,0,
			0,1,0,1,1,1,
			0,0,1,1,1,0,
			0,0,0,1,1,0,
			0,0,0,0,0,1
		};
	int n;
	printf("enter source: ");
	scanf("%d",&n);
	bfs_traversal(a,n);
}
void bfs_traversal(int a[][6],int n)
{

	int inp[6];
	int out[6];
	int queue[6];
	int i,r=0,f=-1,j,k=0,l=0,m,flag=0;
	queue[r]=n;
	f=r;
	r++;
	inp[l]=n;
	l++;
	while(f!=r)
	{
		out[k]=queue[f];
		k++;
		f++;
		if(f==r)
			f=r=0;
		n=queue[f];
		for(j=0;j<6;j++)
		{
			if(a[n][j]==1)
			{
				for(m=0;m<l;m++)
				{
					if(j==inp[m])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					inp[l]=j;
					l++;
					queue[r]=j;
					r++;
				}
				flag=0;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%c",out[i]+65);
	}
	printf("\n");

}
