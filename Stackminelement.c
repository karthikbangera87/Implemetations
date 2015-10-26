#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5

struct stack
{
	int stack1[STACK_SIZE];
	int stack2[STACK_SIZE];
	int top1,top2;
};

typedef struct stack STACK;

int push(int item,STACK *s1)
{
     int count=0,temp,temp1;
	 if(s1->top1==STACK_SIZE-1)
	 {
		 printf("\nStack Overflow");
		 return 0;
	 }

	 if(s1->top1==-1)
	 {
		 	s1->stack1[++(s1->top1)]=item;
		 	return 0;
	 }
	 else
	 	 {
		 	 	 if(item < (s1->stack1[s1->top1]))

	 	 	 	 {
		 	 		 temp=s1->top1;
		 	 	 	 while(item < (s1->stack1[s1->top1]))
		 	 	 	 {
		 	 	 		 temp1=--(s1->top1);
		 	 	 		 count++;
		 	 	 		if(temp1==-1)break;
		 	 	 	 }
		 	 	 	 	s1->top1=temp;

		 	 	 	 while(count!=0)
		 	 	 	 {
		 	 		 	 s1->stack2[++(s1->top2)]=s1->stack1[(s1->top1)--];
		 	 		 	 count--;
		 	 	 	 }


		 	 		 s1->stack1[++(s1->top1)]=item;

		 	 		 while((s1->top2)!=-1)
		 	 		 {
		 	 			 s1->stack1[++(s1->top1)]=s1->stack2[s1->top2];
		 	 			 (s1->top2)--;
		 	 		 }

	 	 	 	 }
		 	 	 else
		 	 	 s1->stack1[++(s1->top1)]=item;

	 	 }

	return 0;

}

int pop(STACK *s1)
{
    int item_deleted1;
	if(s1->top1==-1)
	{
		printf("\nThe stack is empty");
		return 0;
	}
	item_deleted1=s1->stack1[(s1->top1)--];


	printf("\nThe item deleted in main stack is %d",item_deleted1);




	return 0;
}

int display(STACK s)
{
		 int i;
		 	 if(s.top1==-1)
		 	 {
		 		 printf("\nList is empty");
		 		 return 0;
		 	 }
		 	 printf("\nThe ordered elements of stack are:\n");
		 	 for(i=s.top1;i>=0;i--)
		 	 {
		 		 printf("\n%d",s.stack1[i]);

		 	 }

		 	 return 0;
}


int main()

{
	int choice,item;
	STACK s;
	s.top1=-1;
	s.top2=-1;
    for(;;)
    {
    	printf("\n******MENU****\n");
    	printf("\n1.Push onto Stack\n2.Pop from stack\n3.Display\n4.Exit");
    	printf("\nEnter your choice");
    	scanf("%d",&choice);
    	switch(choice)
    	{
			case 1:		printf("\nEnter the item to insert");
						scanf("%d",&item);
						push(item,&s);
						break;
			case 2:
						pop(&s);
						break;

			case 3:		display(s);
						break;

			default:
						exit(0);
    	}

     }
    return 0;
}
