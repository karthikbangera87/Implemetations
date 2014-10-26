/*
 * Bucketsort.c
 *
 *Created on: Sep 25, 2014
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node_struct
{
	double d;
	struct node_struct *next;
}node;

void generateRandomNumbers(double a[], int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		// rand () generates a random number from 0 to RAND_MAX, defined in <stdlib.h>
		// After the division with RAND_MAX, the array will have random value within (0,1)
		a[i] = rand()/(double)RAND_MAX;
	}
}
void insert(double value, int index, node *B[])
{
	// This function insert a new node with value into the B[index] linked list. The function
	// inserts the new node in the correct place of the linked list so that the link list is sorted
	node *t;
	if (B[index] == NULL){
		// No elements in the linked list, create and insert the node at the beginning of the list
		t = (node *) malloc(sizeof(node));
		t -> d = value;
		t -> next = NULL;
		B[index] = t;
	}
	else
	{
		// Take two pointers p0 and p1. p0 always stays one node behind p1
		// The new node t will be inserted either on the end of the linked list
		// or before a node that has a value greater than the new node value.
		node *p0,*p1;
		p0 = B[index];
		if(p0->d > value){
			t = (node *) malloc(sizeof(node));
			t ->d = value;
			t ->next = p0;
			B[index]=t;

		}
		else{
				while(p0 !=NULL){
					if(p0->d > value){
						t = (node *) malloc(sizeof(node));
						t ->d = value;
						t ->next = p0;
						p1->next=t;
						return;
					}
					else{
						p1=p0;
						p0=p0->next;
					}
				}
				t = (node *) malloc(sizeof(node));
				t ->d = value;
				t ->next = NULL;
				p1->next=t;
		}
	}

}
int main(){

	int n=50,i,index;
	double a[50];
	node *B[50];
	for(i = 0; i < n; ++i)
		B[i] = NULL;
	generateRandomNumbers(a,n);
	printf("\nUnsorted array is:\n");
	for(i=0;i<n;i++){
			printf("%f\t",a[i]);
			//generate index
			index=(n*a[i]);
			printf("%d\n",index);
			insert(a[i],index,B);

	}
	printf("\nSorted array is:\n");
	for(i=0;i<n;i++){
		if(B[i]!=NULL){
			while(B[i]->next!= NULL){
				printf("%f\n",B[i]->d);
				B[i]=B[i]->next;
			}
			printf("%f\n",B[i]->d);
		}

	}
return 0;

}



