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

int main()
{
	int choice,item;
	NODE root=NULL;

	for(;;){

		printf("\nPress\n1.Insert into BST\n2.Display in BST\n3.Search item");
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
					scnaf("%d",&item);
					search(root,item);

			default:
					exit(0);
		}


	}

}
