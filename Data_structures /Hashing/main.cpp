/*
 * main.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: ICEMAN
 */

#include<iostream>
#include<cstdlib>
#include<string.h>

#include "hash.h"

using namespace std;

 int main(int argc,char ** argv)
 {
     hashtest hashobj;
     hashobj.additem("Kaku bangera","rootbeer");
     hashobj.additem("Kakfefse","rootbeer");
     hashobj.additem("Kaku","roeotbeer");
     hashobj.additem("Kakeeeu","rootbeer");
     hashobj.additem("Kakfu","rootbeer");
     hashobj.additem("Kakvue","rootbeer");
     hashobj.printout();

     return 0;
 }
