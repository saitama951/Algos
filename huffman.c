#include "stdio.h"
#include "stdlib.h"
struct node
{
	char data;
	int freq;
	struct node* left,*right;
};

struct node* intialize(int [],int []);
void build_heap(struct node** );
void min_heapify(struct node** ,int );
void swap(char* ,char*  ,int* ,int* );
void huffman_tree(struct node** );
struct node* extract_min(struct node** );
void insert_node(struct node**, struct node*);
void print_values_huffman(struct node*,int [],int );

int size;

void main()
{
	int i,arr[500];
	int data[]={'c','f','d','a','e','b'};
	int freq[]={10,80,13,5,14,20};
	size=6;
	printf("inital values:\n");
	for(i=0;i<6;i++)
	{
		printf("%c %d\n",data[i],freq[i]);
	}
	struct node *root=intialize(data,freq);
	printf("huffman tree codes:\n");
	print_values_huffman(root,arr,0);
	

}
struct node* intialize(int data[],int freq[])
{
	int i;
	struct node**arr=(struct node**)malloc(size*sizeof(struct node)); //creating array of nodes
	for(i=0;i<size;i++)
	{
		arr[i]=(struct node*)malloc(sizeof(struct node));
		arr[i]->data=data[i];
		arr[i]->freq=freq[i];
		arr[i]->left=arr[i]->right=0;
	}
	
	build_heap(arr);

	huffman_tree(arr);	

	return arr[0];


}
void print_values_huffman(struct node* root,int arr[],int i)
{
	int j;
	if(root->left)
	{
		arr[i]=0;
		print_values_huffman(root->left,arr,i+1);
	}
	if(root->right)
	{
		arr[i]=1;
		print_values_huffman(root->right,arr,i+1);

	}
	if(root->right==0 && root->left==0)
	{
		printf("%c %d  ",root->data,root->freq);
		for(j=0;j<i;j++)
		{
			printf("%d",arr[j]);
		}
		printf("\n");
	}
}
void build_heap(struct node **arr)
{
	int i;
	for(i=(size-1)/2;i>=0;i--)
	{
		min_heapify(arr,i);
	}
}
void min_heapify(struct node** arr,int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int min=i;

	if(l<size && arr[l]->freq<arr[min]->freq)
		min=l;
	if(r<size && arr[r]->freq<arr[min]->freq)
		min=r;

	if(min!=i)
	{
		struct node *temp;
		swap(&arr[i]->data,&arr[min]->data,&arr[i]->freq,&arr[min]->freq); //swapping values
		
		temp=arr[i]->left;	//swapping addresses
		arr[i]->left=arr[min]->left;
		arr[min]->left=temp;

		temp=arr[i]->right; 	//swapping address
		arr[i]->right=arr[min]->right;
		arr[min]->right=temp;
		
		min_heapify(arr,min);
	}
}
void swap(char* id ,char* md,int* ifr,int* mfr) //id-> i data, md-> min data, ifr-> i frequency, mfr-> min frequency
{
	int temp;
	char ctemp;

	temp = *ifr;
	*ifr = *mfr;
	*mfr = temp;
	
	ctemp = *id;
	*id = *md;
	*md = ctemp;


}
struct node* extract_min(struct node** arr) //extracting the min from heap
{
	struct node* min =(struct node*)malloc(sizeof(struct node));
	min->data=arr[0]->data;
	min->freq=arr[0]->freq;
	min->left=arr[0]->left;
	min->right=arr[0]->right;

	arr[0]->data=arr[size-1]->data;
	arr[0]->freq=arr[size-1]->freq;
	arr[0]->right=arr[size-1]->right;
	arr[0]->left=arr[size-1]->left;
	size--;
	min_heapify(arr,0);

	return min;

	

}
void insert_node(struct node** arr,struct node* new_node)
{
	size++;
	arr[size-1]=new_node;

	build_heap(arr);	
}
void huffman_tree(struct node** arr)
{
	char *temp="#";
	while(size!=1)
	{
		struct node* min1=extract_min(arr);
		struct node* min2=extract_min(arr); 
	
		struct node* new_node =(struct node*)malloc(sizeof(struct node));
	
		new_node->freq=(min1->freq)+(min2->freq);
		new_node->data=*temp;
		new_node->left=min1;
		new_node->right=min2;

		insert_node(arr,new_node);	
	}
	
}

