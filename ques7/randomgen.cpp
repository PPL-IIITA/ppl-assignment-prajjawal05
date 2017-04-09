#include<iostream>
int main(int argc, char **argv)
{
	//printf("Enter the number of boys,girls in order separated by spaces\n");
	//int nb,ng;
	int nb = 50,ng = 30;
	FILE*fb=fopen("boys.txt","w+");	//!Randomly Generating different types of boys in boys.txt.
	for(int j=0;j<nb;j++)
	{
		fprintf(fb,"b");
		fprintf(fb,"%d",j);	//!boy name.
		fprintf(fb," ");
		int type=rand()%3;		//!boy type.
		if(type==0)
			fprintf(fb,"Miser ");
		else if(type==1)
			fprintf(fb,"Generous ");
		else if(type==2)
			fprintf(fb,"Geeks ");
		fprintf(fb,"%d ",rand()%100+1); //!attractiveness.
		fprintf(fb,"%d ",rand()%100+1); //!intelligent.
		fprintf(fb,"%d ",rand()%1000+200); //!budget.
		fprintf(fb,"%d ",rand()%100+1); //!minimum attr.
		fprintf(fb,"\n");
	}

	FILE*fg=fopen("girls.txt","w+");  //!Randomly Generating different types of girls in girls.txt.
	for(int j=0;j<ng;j++)
	{
		fprintf(fg,"g%d",j);	//!Name.
		fprintf(fg," ");
		int type=rand()%3;
		if(type==0)
			fprintf(fg,"Choosy ");	//!type.
		else if(type==1)
			fprintf(fg,"Normal ");
		else if(type==2)
			fprintf(fg,"Desperate ");
           	 type=rand()%3;
		if(type==0)
			fprintf(fg,"Attractive ");	//!type.
		else if(type==1)
			fprintf(fg,"Rich ");
		else if(type==2)
			fprintf(fg,"Intelligent ");
		fprintf(fg,"%d ",rand()%100+1); //!attractiveness.
		fprintf(fg,"%d ",rand()%100+1); //!intelligent.
		fprintf(fg,"%d ",rand()%1000+200); //!maintenance.
		fprintf(fg,"\n");
	}
	return 0;
}
