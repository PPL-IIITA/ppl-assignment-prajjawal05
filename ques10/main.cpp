#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"couples.cpp"
#include"util.cpp"

int main(int argc,char** argv)
{
	util x; couples cc; int k;
	//printf("Enter the value of k not greater than number of couples(%d)\n",cc.readcouplecount());
	k = rand()%10; //!Taking random value of k.
	x.coupling(k);	//!Inserting the couples formed into log file and couples.txt
	x.gifting(k);	//!Inserting happiness and compatibility into fcalc.txt

	//x.most(k);	//!Printing the k happiest and k compatible couples.
}
