#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"couples.cpp"
#include"util.cpp"
#include<string>
using namespace std;

int main(int argc,char** argv)	//inheritance is used here to connect common attributes of boys and girls in a class attribute
{
	util x; couples cc;int n;
	string s[] = {"b0","b1","b2","b3","b4","b5","b6","b7","b8","b9","b10"};//!Given array of boys for which we have to search.
	n = 11;
	x.coupling(s,n);	//!Inserting the couples formed into log file and couples.txt
}
