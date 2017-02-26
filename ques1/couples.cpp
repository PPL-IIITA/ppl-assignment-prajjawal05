#include"girls.cpp"
#include"boys.cpp"
#include"gifts.cpp"
#include<fstream>
#include<ctime>
#include<math.h>

class couples
{
	public:
		std::string bname,btype,gname,gtype;	////!attributes of couples.
		int bbud,gbud,batt,gatt,bint,gint,compatibility;
		double happiness;
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
							fprintf(fc,"%s %s %s %s %d %d %d %d %d %d\n",boyss[minind].name.c_str(),boyss[minind].type.c_str(),girlss[i].name.c_str(),girlss[i].type.c_str(),boyss[minind].budget,girlss[i].maintenance,boyss[i].attractiveness,girlss[i].attractiveness,boyss[i].intelligence,girlss[i].intelligence);
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
							fprintf(fc,"%s %s %s %s %d %d %d %d %d %d\n",boyss[minind].name.c_str(),boyss[minind].type.c_str(),girlss[i].name.c_str(),girlss[i].type.c_str(),boyss[minind].budget,girlss[i].maintenance,boyss[i].attractiveness,girlss[i].attractiveness,boyss[i].intelligence,girlss[i].intelligence);
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
