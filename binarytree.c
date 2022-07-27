/* To Develop a program to perform pre-order, in-order, post-order traversals on binary trees */
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left,*right;
};

struct node *create()
{
	int x;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data(-1 for no node): ");
	scanf("%d",&x);
	if(x==-1){
		return 0;}
	newnode->data=x;
	printf("\nFor left child of %d,\n",x);
	newnode->left=create();
	printf("\nFor right child of %d,\n",x);
	newnode->right=create();
	return newnode;
}

void preorder(struct node *root)
{
	if(root ==NULL){
		return;}
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root ==NULL){
		return;}
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}
	
void postorder(struct node *root)
{
	if(root ==NULL){
		return;}
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}
		
void main()
{

	struct node *root=NULL;
	root=create();
	printf("\nPRE ORDER TRAVERSAL:\n");
	preorder(root);
	printf("\nIN ORDER TRAVERSAL:\n");
	inorder(root);
	printf("\nPOST ORDER TRAVERSAL:\n");
	postorder(root);
	printf("\n");
}

