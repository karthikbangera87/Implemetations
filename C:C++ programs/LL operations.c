#include <stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
    
};
typedef struct node * NODE;

NODE getnode()
{
	NODE x;
    
	x=(NODE)malloc(sizeof(struct node));
    
	return x;
    
    
}

NODE insert(int item,NODE first)
{
	NODE temp;
    
	temp=getnode();
    
	temp->info=item;
	temp->link=first;
    
	return temp;
    
}

NODE delete(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
    	printf("\nThe linked list is empty");
    	return 0;
    }
    cur=first;
    printf("\nThe item deleted is:%d",first->info);
    
    first=cur->link;
    nodefree(cur);
    return first;
    
}

int nodefree(NODE p)
{
	free(p);
	return 0;
}

int display(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("\nList is empty");
		return 0;
	}
    
	temp=first;
    
	while(temp != NULL)
	{
		printf("\nContents of the linked list:%d\n",temp->info);
		temp=temp->link;
	}
    
	return 0;
}

NODE insert_rear(int item,NODE first)
{
	NODE cur,temp;
    
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
    
	if(first==NULL)
	{
		printf("\nThe list is empty");
		return 0;
	}
    
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
    }
    cur->link=temp;
    
    return first;
    
}

NODE delete_rear(NODE first)
{
	NODE prev,cur;
    
	cur=first;
	if(first==NULL)
	{
        printf("\nThe list is empty");
        return 0;
	}
	if(first->link==NULL)
	{
		printf("\nThe item deleted from the LL is %d",first->info);
	    nodefree(first);
	    return NULL;
	}
    
    
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
        
    }
    printf("\nThe item deleted is %d:",cur->info);
    prev->link=NULL;
    nodefree(cur);
    return first;
}

NODE delete_info(int key,NODE first)
{
    NODE cur=NULL;
    NODE prev=NULL;
    if(first==NULL)
    {
        printf("\nList is empty");
        return 0;
    }
    if(key==first->info)
    {
        cur=first;
        first=cur->link;
        nodefree(cur);
        return first;
    }
    
    cur=first;
    while(cur !=NULL)
    {
        if(key==cur->info) break;
        
        prev=cur;
        cur=cur->link;
        
    }
    
    if(cur==NULL)
    {
        printf("\nThe given key is not available in the list");
        return 0;
    }
    
    prev->link=cur->link;
    nodefree(cur);
    return first;
    
}


NODE delete_position(int position,NODE first)
{
    NODE prev=NULL;
    NODE cur=NULL;
    int count=1;
    if(first==NULL)
    {
        printf("\nList is empty");
        return 0;
    }
    if(position==1)
    {
        cur=first;
        first=cur->link;
        nodefree(cur);
        return first;
    }
    
    cur=first;
    
    while(cur!=NULL)
    {
        
    	if(position==count)break;
    	prev=cur;
    	cur=cur->link;
    	count++;
        
    }
    if(count!=position)
    {
        printf("\nThe position is not available in the list");
        return 0;
    }
    
    prev->link=cur->link;
    nodefree(cur);
    return first;
    
    
    
}




int main()

{
    
	int choice,item,item1,key,position;
	NODE first=NULL;
    for(;;)
    {
    	printf("\n1.Insert into LL\n2.Delete from front-end\n3.Insert from rear end\n4.Delete from rear-end\n5.Display\n6.Delete base on info\n7.Delete based on position");
    	printf("\nEnter your choice:");
    	scanf("%d",&choice);
    	switch(choice)
    	{
                
			case 1:  	 printf("\nEnter the item to insert");
                scanf("%d",&item);
                first=insert(item,first);
                break;
			case 2:
                first=delete(first);
                break;
                
			case 3:		 printf("\nEnter the item to insert");
                scanf("%d",&item1);
                first= insert_rear(item1,first);
                break;
                
			case 4:		first=delete_rear(first);
                break;
                
			case 5: 	 display(first);
                break;
                
			case 6:		printf("\nEnter the key element to be deleted");
                scanf("%d",&key);
                first=delete_info(key,first);
                break;
                
			case 7:
                printf("\nEnter the position you want an element to be removed");
                scanf("%d",&position);
                first=delete_position(position,first);
                break;
                
                
	    }
    }
    return 0;
}
