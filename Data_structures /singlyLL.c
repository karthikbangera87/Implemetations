#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

typedef struct node * NODE;

NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if(x == NULL)
	{
		printf("\nMemory unavailable");
		return 0;
	}

	return x;

}

void freenode(NODE x)
{
	free(x);
}

NODE insert_front(NODE first,int item)
{
	NODE temp;

	temp = getnode();
	temp->info = item;
	temp->link = first;
	return temp;

}

void display(NODE temp)
{
	if(temp == NULL){
		printf("\nList is empty");
		return;
	}
	while(temp !=NULL){
		printf("%d\n", temp->info);
		temp = temp->link;
	}

}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("\nList is empty");
		return 0;
	}


	temp = first->link;
	printf("\n Item deleted is %d",first->info);
	first = temp;
	free(temp);
	return first;

}

NODE insert_rear(NODE first,int item)
{
	NODE temp,cur;
	if (first ==NULL){
		temp = getnode();
		temp->info = item;
		temp->link = first;
		return temp;
	}
	cur = first;
	while(cur->link != NULL){
		cur = cur->link;

	}
	temp = getnode();
	temp->info = item;
	temp->link = NULL;
	cur->link = temp;
	return first;


}
NODE delete_rear(NODE first)
{
	NODE cur,prev;
	if(first ==NULL){
		printf("\nList is empty");
		return 0;
	}

	cur = first;
	if(cur->link ==NULL){
		printf("\nThe item removed is %d",cur->info);
		freenode(cur);
		first = NULL;
		return first;
	}
	while(cur->link !=NULL)
	{
		prev = cur;
		cur = cur->link;

	}

	prev->link = NULL;
	printf("\nThe item removed is %d",cur->info);
	freenode(cur);
	return first;

}

NODE reverse(NODE first)
{
	NODE cur,next,temp;
	cur = NULL;

	while(first!= NULL){

		temp = first;
		first = first->link;
		temp->link = cur;
		cur = temp;

	}
	return cur;

}
int main(){

	NODE first = NULL;
	int choice,item;
	for(;;)
	{
		printf("\n1.Insert into front of  LL\n2.Delete from front of LL \n3.Insert into LL rear \n4.Delete rear items in LL \n5.Display items in LL\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){

		case 1:
				printf("\nEnter the item you want to insert");
				scanf("%d",&item);
				first = insert_front(first,item);
				break;
		case 2:

			    first = delete_front(first);
				break;

		case 5:
				display(first);
				break;

		case 3:
				printf("\nEnter the item you want to insert");
				scanf("%d",&item);
				first = insert_rear(first,item);
				break;
		case 4:
				first = delete_rear(first);
				break;
		default:
					exit(0);

		}


	}
	return 0;

}
