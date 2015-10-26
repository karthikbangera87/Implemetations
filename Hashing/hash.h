/*
 * hash.h
 *
 *  Created on: Feb 17, 2014
 *      Author: ICEMAN
 */


#ifndef HASH_H_
#define HASH_H_

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;


class hashtest

{
	private:
	static const int SIZE=10;
			struct item
			{
				string name;
				string drink;
				item * link;
			};

			item *hashtables[SIZE];


	public:
			hashtest();
			int hashfunc(string name);
			void additem(string name,string drink);
			int itemno(int index);
			void printout();

};




#endif /* HASH_H_ */
