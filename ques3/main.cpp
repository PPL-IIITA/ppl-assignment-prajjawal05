#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"couples.cpp"
#include"util.cpp"

int main(int argc,char** argv)	//!inheritance is used here to connect common attributes of boys and girls in a class attribute.
{
	util x; couples cc; int k;
	x.coupling();	//!Inserting the couples formed into log file and couples.txt
	x.gifting();	//!Inserting happiness and compatibility into fcalc.txt
	k = rand()%cc.readcouplecount() + 1;
	//printf("Enter the value of k not greater than number of couples(%d)\n",cc.readcouplecount());
	//scanf("%d",&k);
	x.most(k);	//!Printing the k happiest and k compatible couples.
}
