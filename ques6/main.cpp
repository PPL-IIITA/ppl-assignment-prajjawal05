#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"couples.cpp"
#include"util.cpp"

int main(int argc,char** argv)	//inheritance is used here to connect common attributes of boys and girls in a class attribute
{
	util x; couples cc; int k;
	x.coupling();	//!Inserting the couples formed into log file and couples.txt
	k = rand()%10; //!Taking random value of t.
	for(int i=0;i<k;i++)	//The breakup and formation of couples with happineess level<k is performed k times
	{
		x.gifting();	//!Inserting happiness and compatibility into fcalc.txt
		x.most(k);	//!Printing the k happiest and k compatible couples.
	}
}
