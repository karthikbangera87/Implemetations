/*
 * hashfunctions.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: ICEMAN
 */

#include<iostream>
#include<cstdlib>
#include<string.h>

#include "hash.h"

using namespace std;

hashtest::hashtest()
{
	for(int i=0;i<SIZE;i++)
	{
		hashtables[i]=new item;
		hashtables[i]->name="empty";
		hashtables[i]->drink="empty";
		hashtables[i]->link=NULL;
	}


}

void hashtest::printout()
{
	for(int i=0;i<SIZE;i++)
	{
		int number=itemno(i);
		cout<<"----------------------"<<endl;
		cout<<"Index::" <<i<<endl;
		cout<<"Name::"<<hashtables[i]->name<<endl;
		cout<<"Drink::"<<hashtables[i]->drink<<endl;
		cout<<"No of items in the index::"<< number<<endl;
	}
}
int hashtest::itemno(int index)
{
	int count=0;

	if(hashtables[index]->name=="empty")
	{
		return count;
	}
	else
	{
		count++;
		while(hashtables[index]->link!=NULL)
		{
			count++;
			hashtables[index]=hashtables[index]->link;
		}
		return count;

	}
}
void hashtest::additem(string name,string drink)
{
	int index;
	index=hashfunc(name);

	if(hashtables[index]->name=="empty")
	{
		hashtables[index]->name=name;
		hashtables[index]->drink=drink;
		hashtables[index]->link=NULL;
	}
	else
	{
		item *ptr=hashtables[index];
		item * n=new item;
		n->name=name;
		n->drink=drink;
		n->link=NULL;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=n;
	}


}
int hashtest::hashfunc(string key)
{
	int index,hash=0;
    int length=key.length();
	for(int i=0;i< length ;i++)
	{
		hash=hash+(int)key[i];

	}

	index= hash % SIZE;
	return index;
}
