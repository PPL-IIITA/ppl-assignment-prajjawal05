#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"couples.cpp"
#include<string.h>
#include<fstream>
#include<ctime>
#include"util.cpp"

int main(int argc,char** argv)
{
	// g++ randomgen.cpp -o random
	util x;
	x.coupling();
	return 0;
}
