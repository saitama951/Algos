#include "stdio.h"
#include "stdlib.h"

struct node
{
	struct node* left;
	struct node* right;
	int data;
};
struct node* create_bst(struct node* ,int );
void level_order(struct node*);
void print_level_order(struct node* ,int );
void main()
{
	struct node* root=NULL;
	int n,data;
	while(1)
	{
		printf("\n1.insert element\n2.traverse\n0.exit\nenter choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter data: ");
			       scanf("%d",&data);
				root=create_bst(root,data);
			       break;
			case 2:level_order(root);
			       break;
			case 0: exit(0);
				break;
			default: printf("inavlid choice!!!");
		}
	
	}

}
struct node* create_bst(struct node* root,int data)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=data;
		root->right=NULL;
		root->left=NULL;
		return root;	
	}
	if(data>root->data)
	{
		root->right=create_bst(root->right,data);
		
	}
	if(data<root->data)
	{
		root->left=create_bst(root->left,data);
	}
	return root;

}
int height(struct node* root)
{
	struct node* temp=root;
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
	
		int lheight=height(temp->left);
		int rheight=height(temp->right);
		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}

}
void level_order(struct node* root)
{
	struct node* temp=root;
	int i;
	int h=height(temp);
	for(i=1;i<=h;i++)
	{
		print_level_order(temp,i);
	}

}
void print_level_order(struct node* root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d",root->data);
	else if(level>1)
	{
		print_level_order(root->left,level-1);
		print_level_order(root->right,level-1);
	}
}
