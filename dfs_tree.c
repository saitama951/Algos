#include "stdio.h"
#include "stdlib.h"

struct node
{
	struct node* left;
	struct node* right;
	int data;
};
struct node* create_bst(struct node* ,int );
void post_order_traversal(struct node* );
void pre_order_traversal(struct node* );
void in_order_traversal(struct node* );
void main()
{
	struct node* root=NULL;
	int n,data;
	while(1)
	{
		printf("\n1.insert element\n2.post order traversal\n3.pre order traversal\n4.inorder traversal\n0.exit\nenter choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter data: ");
			       scanf("%d",&data);
				root=create_bst(root,data);
			       break;
			case 2:post_order_traversal(root);
			       break;
			case 3:pre_order_traversal(root);
			       break;
			case 4:in_order_traversal(root);
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
void post_order_traversal(struct node* root)
{
	struct node* temp=root;
	if(root!=NULL)
	{
		post_order_traversal(temp->left);
		post_order_traversal(temp->right);
		printf("%d ",temp->data);
	}
}
void pre_order_traversal(struct node* root)
{
	if(root!=NULL)
	{
		struct node* temp=root;
		printf("%d ",temp->data);
		pre_order_traversal(temp->left);
		pre_order_traversal(temp->right);
	}
}
void in_order_traversal(struct node* root)
{
	if(root!=NULL)
	{
		struct node* temp=root;
		in_order_traversal(temp->left);
		printf("%d ",temp->data );
		in_order_traversal(temp->right);
	}
}
