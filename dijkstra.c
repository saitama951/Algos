#include "stdio.h"
#include "stdlib.h"
#define inf 99  
struct data //output list
{
	int ip;
	int jp;
	int dist;
};
struct queue
{
	int ip;
	int jp;
	int dist;
	struct queue* link;
};
struct queue* f=0; //priority queue front
struct queue* r=0;//priority queue rear
void dijkstras_distance(int ,int [][9]);
int check_queue(int ,int ,int );
void add_queue(int ,int ,int );
void print_distance(int ,struct data []);

void main()
{	
	//graph intialisation 
	
	int a[9][9]={ 0,3,1,inf,4,inf,2,inf,1, 
		      3,0,inf,3,1,3,4,inf,inf, 
		      1,inf,0,1,3,inf,inf,3,2, 
		      inf,3,1,0,2,2,inf,4,inf, 
		      4,1,3,2,0,inf,inf,inf,inf, 
		      inf,3,inf,2,inf,0,5,4,inf, 
		      2,4,inf,inf,inf,5,0,inf,5, 
		      inf,inf,3,4,inf,4,inf,0,6, 
		      1,inf,2,inf,inf,inf,5,6,0  
	
			};
	int n;
	printf("enter source: ");
	scanf("%d",&n);
	dijkstras_distance(n,a);
	

}

void dijkstras_distance(int n,int a[][9])
{
	struct queue* q;
	r=(struct queue*)malloc(sizeof(struct queue));
	struct data out[9];
	int i,k=0,d=0,status;

	r->ip=n;
	r->jp=n;
	r->dist=d;
	r->link=0;
	f=r;

	while(f!=0)
	{
		out[k].ip=f->ip;
		out[k].jp=f->jp;
		out[k].dist=f->dist;
		d=f->dist;

		n=f->jp;
		k++;
		q=f->link;
		free(f);
		f=q;
		r=q;


		for(i=0;i<9;i++)
		{

			if(a[n][i]!=inf && a[n][i]!=0)
			{
				status =check_queue(n,i,a[n][i]+d);
				if(status==0)
				{
					add_queue(n,i,a[n][i]+d);
				}
				a[i][n]=0;
			}
		}
	}
	print_distance(k,out);

}
void print_distance(int k,struct data out[])
{
	int i;

	for(i=0;i<k;i++)
	{
		printf("%c %c %d\n",out[i].ip+65,out[i].jp+65,out[i].dist);
	}	
}
int check_queue(int ip,int jp,int value) //checking the value to insert into priority queue
{
	struct queue *q,*m=r;
	while(r!=0)
	{
		//printf("hi");
		if(jp==r->jp && value>=r->dist)
		{
			r=f;
			return 1;
		}
		else if(jp==r->jp && value<r->dist)
		{
			m->link=r->link;
			free(r);
			r=f;
			return 0;
		}
		m=r;
		r=r->link;

	}
	r=f;
	return 0;
}
void add_queue(int ip,int jp,int value) //adding to prority queue
{
	struct queue *q,*m;
	if(f==0)
	{
		r=(struct queue*)malloc(sizeof(struct queue));
		r->ip=ip;
		r->jp=jp;
		r->dist=value;
		r->link=0;
		f=r;
	}
	else if(value< r->dist)
	{
		q=(struct queue*)malloc(sizeof(struct queue));

		q->link=r;
		r=f=q;
		r->ip=ip;
		r->jp=jp;
		r->dist=value;
	}
	else
	{
		while(r!=0 && value>=r->dist)
		{
			m=r;
			r=r->link;

		}
		q=(struct queue*)malloc(sizeof(struct queue));

		m->link=q;
		q->link=r;
		q->ip=ip;
		q->jp=jp;
		q->dist=value;
		r=f;
	}
}
