#include<stdio.h>
#include<stdlib.h>

struct node {

	int info;
	struct node *rlink;
	struct node *llink;
};

typedef struct node * NODE;
NODE getnode()
{
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	if(temp ==NULL)
	{
		printf("\nInsufficient memory");
		return 0;
	}
	temp->info= 0;
	temp->rlink = temp->llink = NULL;
	return temp;

}

void freenode(NODE x)
{
	free(x);
}

void display(NODE root,int level)
{
	int i;
	if(root==NULL) return;
	display(root->rlink,level+1);
	for(i=0;i<level;i++) printf("  ");
	printf("%d\n",root->info);
	display(root->llink,level+1);
}
NODE insert(NODE root,int item)
{
	NODE temp,prev,cur;
	temp = getnode();
	if(root == NULL)
	{
		temp->info = item;
		return temp;
	}
	temp->info = item;
	prev=NULL;
	cur = root;
	while(cur!=NULL){

		prev=cur;
		if(item < cur->info)
			cur = cur->llink;
		else
			cur= cur->rlink;
	}

	if(item < prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;

	return root;

}

void search(NODE root,int item)
{
	if(root == NULL){
		printf("\nThe list is empty,nothing to search");
		return;
	}


	while(root !=NULL){
		if (item ==root->info){
			printf("\nItem found");
			break;
		}
		else if(item < root->info){
			root=root->llink;
		}
		else{
			root=root->rlink;
		}
	}
	if(root==NULL)
		printf("\nItem not found");
}

NODE delete_item(NODE root,int item)
{
	NODE parent,successor,cur,q;
	if(root ==NULL)
	{
		printf("\nThe list is empty");
		return root;
	}
	parent = NULL;
	cur = root;
	while(cur!=NULL)
	{

		if(item == cur->info)
			break;

		else if(item < cur->info){
			parent = cur;
			cur= cur->llink;}

		else{
			parent = cur;
			cur= cur->rlink;}
	}
	if(cur ==NULL)
	{
		printf("\nItem to be deleted not found");
		return root;
	}

	if (cur->rlink ==NULL)
		q = cur->llink;
	else if (cur->llink == NULL)
		q = cur->rlink;
	else
	{
		successor = cur->rlink;
		while(successor->llink !=NULL)
		{
			successor = successor-> llink;
		}

		successor->llink = cur->llink;
		q = cur->rlink;

	}
	if(parent == NULL) return q;
	if(cur == parent->llink){
		parent ->llink = q;
	}
	else{
		parent->rlink = q;
	}
	free(cur);
	return root;
}
int main()
{
	int choice,item;
	NODE root=NULL;

	for(;;){

		printf("\nPress\n1.Insert into BST\n2.Display in BST\n3.Search item\4.Delete item in BST");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf("\nEnter the item to insert:");
					scanf("%d",&item);
					root=insert(root,item);
					break;
			case 2:
					display(root,2);
					break;
			case 3:
					printf("\nEnter the item to be searched");
					scanf("%d",&item);
					search(root,item);
					break;
			case 4:
					printf("\nEnter the item to be deleted");
					scanf("%d",&item);
					root = delete_item(root,item);
					break;

			default:
					exit(0);
		}


	}

}
