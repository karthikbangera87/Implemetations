#include<stdio.h>
#include<stdlib.h>

void push(int *stack, int *ptrtop,int full)
{
	int item;
	if(*ptrtop+1 == full){
		printf("\nStack Overflow,cannot insert more items into the stack");
		return;
	}
	printf("\nEnter the element you want to push into the stack");
	scanf("%d",&item);
	stack[++(*ptrtop)] = item;


}
void pop(int *stack,int *ptrtop)
{
	int item;
	if(*ptrtop == -1){
		printf("\nStack underflow,no items present to remove");
		return;
	}
	item = stack[(*ptrtop)--];
	printf("\nThe popped item from the stack is %d",item);


}

void display(int *stack,int *ptrtop)
{
	int i,displaytop = *ptrtop;
	if(displaytop == -1)
		printf("\nStack empty no items to display");
		for(i=displaytop;i>=0;i--)
			printf("\nThe elements in the stack are: %d",stack[i]);

}

int main()
{
	int n,choice,top=-1;
	int *topptr,*stackptr=NULL;
	topptr = &top;


	printf("\nEnter the the no.of elements you want to enter into the stack");
	scanf("%d",&n);

	stackptr = (int*)malloc(n*sizeof(int));

	do
	{
			printf("\nPress\n1.Push\n2.Pop\n3.Display\n4.Exit");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:

					push(stackptr,topptr,n);
					break;

				case 2:

					pop(stackptr,topptr);
					break;

				case 3:
					display(stackptr,topptr);
					break;

			}
	}while(choice != 4);

	return 0;
}
