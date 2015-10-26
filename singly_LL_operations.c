#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE temp;

	temp = (NODE)malloc(sizeof(NODE));
	if (temp == NULL){
		printf("\nInsufficient memory");
		exit(0);
	}

	return temp;
}

void freenode(NODE x)
{
	free(x);
	return;
}
void display(NODE first)
{
	NODE cur;
	cur = first;

	if (first ==NULL){
		printf("\nThe list is empty");
		return;
	}
	while(cur!= NULL){
		printf("\nThe element in the LL is %d",cur->info);
		cur = cur->link;
	}

	return;

}
NODE insert_front(int item,NODE first)
{
	NODE temp;
	temp = getnode();

	if(first ==NULL){

		temp->link = NULL;
		temp->info = item;
		return temp;

	}

	temp->link = first;
	temp->info = item;


	return temp;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first==NULL){
		printf("\nThe list is empty,item cannot be deleted");
		return first;
	}
	temp = first;
	if((temp->link) == NULL){
		printf("\nThe item deleted is %d",temp->info);
		free(temp);
		first = NULL;
		return first;
	}

	first = temp->link;
	printf("\nThe item deleted is %d",temp->info);
	free(temp);
	return first;

}

NODE insert_rear(int item,NODE first)
{
	NODE cur,temp;
	temp = getnode();

	if(first == NULL){
		temp->link = NULL;
		temp->info = item;
		return temp;

	}


	cur = first;
	while(cur->link !=NULL){
		cur = cur->link;
	}

	cur->link = temp;
	temp->info = item;
	temp->link = NULL;
	return first;

}

NODE delete_rear(NODE first)
{
	NODE temp,prev;
	if(first==NULL){
		printf("\nThe list is empty,item cannot be deleted");
		return first;
	}

	temp = first;
	if((temp->link) == NULL){
		printf("\nThe item deleted is %d",temp->info);
		free(temp);
		first = NULL;
		return first;
		}

	while(temp->link !=NULL){

		prev = temp;
		temp = temp->link;
	}
	printf("\nThe item deleted is %d",temp->info);
	free(temp);
	prev->link = NULL;
	return first;


}
int main()
{
	NODE first = NULL;
	int choice,item;
	for(;;){
			printf("\nPress\n1.Insert into FRONT of LL\n2.Display\n3.Delete from front of LL\n4.Insert into LL rear\n5.Delete from LL rear");
			scanf("%d",&choice);
			switch(choice){

				case 1:
						printf("\nEnter the item you want to insert ::");
						scanf("%d",&item);

						first = insert_front(item,first);

						break;

				case 2:
						display(first);
						break;


				case 3:
						first = delete_front(first);
						break;

				case 4:
						printf("\nEnter the item you want to insert ::");
						scanf("%d",&item);
						first = insert_rear(item,first);
						break;

				case 5:
						first = delete_rear(first);
						break;



			}
	}

	return 0;
}
