#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"couples.cpp"
#include"util.cpp"

int main(int argc,char** argv)
{
	util x; couples cc; int k;
	x.coupling();	//!Inserting the couples formed into log file and couples.txt
	x.gifting();	//!Inserting happiness and compatibility into fcalc.txt
	k = rand() % cc.readcouplecount();
	x.most(k);	//!Printing the k happiest and k compatible couples.
}
