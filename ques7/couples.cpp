#include"attributes.cpp"
#include"girls.cpp"
#include"boys.cpp"
#include<fstream>
#include<ctime>
#include<math.h>

class couples
{
	public:
		std::string bname,btype,gname,gtype;	////!attributes of couples.
		int bbud,gbud,batt,gatt,bint,gint,compatibility;
		double happiness;
		int input(couples* couple,int count)
		{
			FILE* fp = fopen("couples.txt","r");	//!data read of couples.
			for(int i=0;i<count;i++)
			{
				char nm1[30],nm2[30],nm3[30],nm4[30];
				fscanf(fp,"%s %s %s %s %d %d %d %d %d %d",nm1,nm2,nm3,nm4,&couple[i].bbud,&couple[i].gbud,&couple[i].batt,&couple[i].gatt,&couple[i].bint,&couple[i].gint);
				couple[i].bname=nm1;
				couple[i].btype=nm2;
				couple[i].gname=nm3;
				couple[i].gtype=nm4;
			}
			fclose(fp);
			return 0;
		}
		int readcouplecount()
		{
			char p;
			int count=0;
			FILE *fp = fopen("couples.txt","r");
			for (p = getc(fp); p != EOF; p = getc(fp))
				if (p == '\n') //! Increment count if this character is newline.
					count = count + 1; //!number of couples.
			fclose(fp);
			return count;
		}
		int pairing(boys *boyss,girls *girlss,int nb,int ng)		//!Pairing.
		{
			FILE *fc = fopen("couples.txt","w+");
			for(int i=0;i<ng;i++)
			{
				//printf("%s\n",girlss[i].name.c_str());
				if(girlss[i].committed==0)
				{
					if(girlss[i].need.compare("Attractive")==0)
					{
						int min_att=0,minind=-1;
						for(int j=0;j<nb;j++)
						{
							if(boyss[j].committed == 0 && boyss[j].min_attractive<=girlss[i].attractiveness && boyss[j].budget>=girlss[i].maintenance && boyss[j].attractiveness>=min_att)
							{
								min_att = boyss[j].attractiveness;
								minind = j;
							}
						}
						if(minind!=-1)
						{
							boyss[minind].committed = 1;
							girlss[i].committed = 1;
							boyss[minind].girlname = girlss[i].name;
							girlss[i].boyname = boyss[minind].name;
							fprintf(fc,"%s %s %s %s %d %d %d %d %d %d\n",boyss[minind].name.c_str(),boyss[minind].type.c_str(),girlss[i].name.c_str(),girlss[i].type.c_str(),boyss[minind].budget,girlss[i].maintenance,boyss[minind].attractiveness,girlss[i].attractiveness,boyss[minind].intelligence,girlss[i].intelligence);
						}
					}
					else if(girlss[i].need.compare("Rich")==0)
					{
						int min_att=0,minind=-1;
						for(int j=0;j<nb;j++)
						{
							if(boyss[j].committed == 0 && boyss[j].min_attractive<=girlss[i].attractiveness && boyss[j].budget>=girlss[i].maintenance && boyss[j].budget>=min_att)
							{
								min_att = boyss[j].budget;
								minind = j;
							}
						}
						if(minind!=-1)
						{
							boyss[minind].committed = 1;
							girlss[i].committed = 1;
							boyss[minind].girlname = girlss[i].name;
							girlss[i].boyname = boyss[minind].name;
							fprintf(fc,"%s %s %s %s %d %d %d %d %d %d\n",boyss[minind].name.c_str(),boyss[minind].type.c_str(),girlss[i].name.c_str(),girlss[i].type.c_str(),boyss[minind].budget,girlss[i].maintenance,boyss[minind].attractiveness,girlss[i].attractiveness,boyss[minind].intelligence,girlss[i].intelligence);
						}
					}
					else if(girlss[i].need.compare("Intelligent")==0)
					{
						int min_att=0,minind=-1;
						for(int j=0;j<nb;j++)
						{
							if(boyss[j].committed == 0 && boyss[j].min_attractive<=girlss[i].attractiveness && boyss[j].budget>=girlss[i].maintenance && boyss[j].intelligence>=min_att)
							{
								min_att = boyss[j].intelligence;
								minind = j;
							}
						}
						if(minind!=-1)
						{
							boyss[minind].committed = 1;
							girlss[i].committed = 1;
							boyss[minind].girlname = girlss[i].name;
							girlss[i].boyname = boyss[minind].name;
							fprintf(fc,"%s %s %s %s %d %d %d %d %d %d\n",boyss[minind].name.c_str(),boyss[minind].type.c_str(),girlss[i].name.c_str(),girlss[i].type.c_str(),boyss[minind].budget,girlss[i].maintenance,boyss[i].attractiveness,girlss[i].attractiveness,boyss[i].intelligence,girlss[i].intelligence);
						}
					}
				}
			}
			fclose(fc);
			return 0;
		}
};
