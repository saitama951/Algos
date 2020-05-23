//SANJAM KUMAR PANDA-A1-15
//IMPLEMENTATION OF KRUSHKAL ALGORITHM

#include "stdio.h"
#define inf 99


struct xxx
{
	int ip;
	int jp;
	int cost;
};

int position(int [],int );
void sort(struct xxx [],int );

void main()
{
	int x[5][5]={
			0,2,3,2,inf,
			2,0,inf,6,inf,
			3,inf,0,1,5,
			2,6,1,0,4,
			inf,inf,5,4,0
	
			};
	
	struct xxx p[10];
	struct xxx out[10];
	int i,j,l=0,k=0,ip,jp;
	int inp[5];
	
	for(i=0;i<5;i++)
		inp[i]=i;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(x[i][j]!=0 && x[i][j]!=inf)
			{
				p[l].ip=i;
				p[l].jp=j;
				p[l].cost=x[i][j];
				x[j][i]=0;
				l++;
			}
		}
	}
	
	sort(p,l);
	
	for(i=0;i<l;i++)
	{
		ip=position(inp,p[i].ip);
		jp=position(inp,p[i].jp);
		if(ip!=jp)
		{
			out[k].ip=p[i].ip;
			out[k].jp=p[i].jp;
			out[k].cost=p[i].cost;

			k++;
			
			for(j=0;j<5;j++)
			{
				if(inp[j]==jp)
					inp[j]=ip;
			}

		}
	}
	
	int c=0;
	
	for(i=0;i<k;i++)
	{
		c=c+out[i].cost;
		printf("%c %c %d\n",out[i].ip+65,out[i].jp+65,out[i].cost);
	
	}
	
	printf("total cost:%d\n",c);
}
int position(int inp[],int v)
{
	return inp[v];
}
void sort(struct xxx p[],int s)
{
	int i,j;
	struct xxx temp;
	
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(p[i].cost>p[j].cost)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
/*---------------------OUTPUT---------------------

C D 1
A D 2
A B 2
D E 4
total cost:9
-------------------END-----------------------------*/
