#include<iostream>
#include"gifts.cpp"
int main(int argc, char **argv)
{
	//printf("Enter the number of boys,girls and the number of gifts in order separated by spaces\n");
	int nb,ng,ngf;
	nb = 50,ng = 30,ngf = 75;

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

	FILE *gi=fopen("gifts.txt","w+");		//!different types of gift int gift.txt.
	for(int i=0;i<ngf;i++)
	{
		int type=rand()%3;			//!type.
		if(type==0)
			fprintf(gi,"Essential ");
		else if(type==1)
			fprintf(gi,"Luxury ");
		else if(type==2)
			fprintf(gi,"Utility ");
		int x = rand()%200 + 1;
		int y = rand()%100 + 1;
		if(type!=1)
		{
			fprintf(gi,"%d ",x); //!Price.
			fprintf(gi,"%d ",y); //!Value.
		}
		else
		{
			fprintf(gi,"%d ",x+201); //!luxury gifts will have more Price.
			fprintf(gi,"%d ",y+101); //!Value.
		}
		fprintf(gi,"\n");
	}
	fclose(gi);
	FILE *fp1=fopen("gifts.txt","r");
	char a[15];
	gifts *gif = new gifts[ngf];
	for(int i=0;i<ngf;i++)
	{
		fscanf(fp1,"%s %d %d",a,&gif[i].price,&gif[i].value);
		gif[i].type = a;
	}
	//!Generating the gifts in an srted order of their price.
	std::string s;
	for(int i=0;i<ngf;i++)
	{
		for(int j=0;j<ngf-1;j++)
		{
			if(gif[j+1].price<gif[j].price)
			{
				std::swap(gif[j+1].price,gif[j].price);
				std::swap(gif[j+1].value,gif[j].value);
				s=gif[j].type;
				gif[j].type=gif[j+1].type;
				gif[j+1].type=s;
			}
			else if(gif[j+1].price==gif[j].price &&gif[j+1].value>gif[j].value)
			{
				std::swap(gif[j+1].price,gif[j].price);
				std::swap(gif[j+1].value,gif[j].value);
				s=gif[j].type;
				gif[j].type=gif[j+1].type;
				gif[j+1].type=s;
			}

		}
	}
	fclose(fp1);
	FILE *fp2=fopen("gifts.txt","w+");
	FILE *fp3=fopen("lgifts.txt","w+");
	for(int i=0;i<ngf;i++)
	{
		fprintf(fp2,"%s %d %d\n",gif[i].type.c_str(),gif[i].price,gif[i].value);
		if(gif[i].type.compare("Luxury")==0)
			fprintf(fp3,"%s %d %d\n",gif[i].type.c_str(),gif[i].price,gif[i].value);		//!if gift is luxury keeping it in luxury.txt as well.
	}
 	fclose(fp2);
	fclose(fp3);

	return 0;
}
