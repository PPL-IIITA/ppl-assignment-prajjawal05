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
		int input1(couples* couple,int count)		//!data read.
		{
			FILE *fp = fopen("fcalc.txt","r");
			for(int i=0;i<count;i++)
			{
				char nm1[30],nm2[30];
				fscanf(fp,"%s %s %lf %d",nm1,nm2,&couple[i].happiness,&couple[i].compatibility);
				couple[i].bname=nm1;
				couple[i].gname=nm2;
				//printf("---   %s\n",couple[i].bname.c_str());
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
							fprintf(fc,"%s %s %s %s %d %d %d %d %d %d\n",boyss[minind].name.c_str(),boyss[minind].type.c_str(),girlss[i].name.c_str(),girlss[i].type.c_str(),boyss[minind].budget,girlss[i].maintenance,boyss[minind].attractiveness,girlss[i].attractiveness,boyss[minind].intelligence,girlss[i].intelligence);
						}
					}
				}
			}
			for(int i=0;i<nb;i++)
			{
				if(boyss[i].committed == 1)
					std::cout<<boyss[i].name<<" and "<<boyss[i].girlname<<"\n";
			}
			fclose(fc);
			return 0;
		}
		int couplegifting(couples* couple,int count,gifts* gif,int ngf)	//!Gift Exchanges.
		{
			std::ofstream output;
			output.open("log.txt", std::ios_base::app);
			FILE *fcc = fopen("fcalc.txt","w+");
			for(int i=0;i<count;i++)
			{
				printf("\n");
				int tl=0,tc=0,tv=0;
				if(couple[i].btype.compare("Miser")==0)
				{

					for(int j=0;j<ngf;j++)
					{
						time_t now = time(0);
						char *dt = ctime(&now);
						if(tc>=couple[i].gbud)
							break;
						if(gif[j].type.compare("Luxury")==0)
							tl+=gif[j].price;
						tc+=gif[j].price;
						tv+=gif[j].value;
						printf("%s gifted %s a %s of cost:%d and value:%d\n",couple[i].bname.c_str(),couple[i].gname.c_str(),gif[j].type.c_str(),gif[j].price,gif[j].value);
						output<<"Gifting---- "<<" "<<dt<<couple[i].bname<<" gifted "<<couple[i].gname<<" a "<<gif[j].type<<" of cost:"<<gif[j].price<<" and value:"<<gif[j].value<<"\n";
					}
					couple[i].happiness = std::max(0,couple[i].bbud-tc);
					if(couple[i].gtype.compare("Choosy")==0)
						couple[i].happiness += log(tc+tl)-log(couple[i].gbud);
					else if(couple[i].gtype.compare("Normal")==0)
						couple[i].happiness += ((tc+tv)/couple[i].gbud);
					else
						couple[i].happiness += exp((tc)/couple[i].gbud);
				}
				else if(couple[i].btype.compare("Generous")==0)
				{
					for(int j=ngf-1;j>=0;j--)
					{
						time_t now = time(0);
						char *dt = ctime(&now);
						if(tc+gif[j].price>couple[i].bbud)
							continue;
						if(gif[j].type.compare("Luxury")==0)
							tl+=gif[j].price;
						tc+=gif[j].price;
						tv+=gif[j].value;
						printf("%s gifted %s a %s of cost:%d and value:%d\n",couple[i].bname.c_str(),couple[i].gname.c_str(),gif[j].type.c_str(),gif[j].price,gif[j].value);
						output<<"Gifting---- "<<" "<<dt<<couple[i].bname<<" gifted "<<couple[i].gname<<" a "<<gif[j].type<<" of cost:"<<gif[j].price<<" and value:"<<gif[j].value<<"\n";
					}
					if(couple[i].gtype.compare("Choosy")==0)
						couple[i].happiness = 2*(log(tc+tl)-log(couple[i].gbud));
					else if(couple[i].gtype.compare("Normal")==0)
						couple[i].happiness = 2*((tc+tv)/couple[i].gbud);
					else
						couple[i].happiness =2*(exp(tc/couple[i].gbud));
				}
				else
				{
					for(int j=0;j<ngf;j++)
					{
						time_t now = time(0);
						char *dt = ctime(&now);
						if(tc>=couple[i].gbud)
							break;
						if(gif[j].type.compare("Luxury")==0)
							tl+=gif[j].price;
						tc+=gif[j].price;
						tv+=gif[j].value;
						printf("%s gifted %s a %s of cost:%d and value:%d\n",couple[i].bname.c_str(),couple[i].gname.c_str(),gif[j].type.c_str(),gif[j].price,gif[j].value);
						output<<"Gifting---- "<<" "<<dt<<couple[i].bname<<" gifted "<<couple[i].gname<<" a "<<gif[j].type<<" of cost:"<<gif[j].price<<" and value:"<<gif[j].value<<"\n";
					}
					if(tl==0)
					{
						time_t now = time(0);
						char *dt = ctime(&now);
						FILE *fpg = fopen("lgifts.txt","r");
						char o[20];
						int w,e;
						if(fscanf(fpg,"%s %d %d",o,&w,&e)!=EOF)
						{
							if(tc+w<=couple[i].bbud)
							{
								tc+=w;
								tl+=w;
								tv+=e;
							}
							printf("%s gifted %s a %s of cost:%d and value:%d\n",couple[i].bname.c_str(),couple[i].gname.c_str(),o,w,e);
						output<<"Gifting----"<<" "<<dt<<couple[i].bname<<" gifted "<<couple[i].gname<<" a "<<o<<" of cost:"<<w<<" and value:"<<e<<"\n";
						}
					}
					couple[i].happiness = couple[i].gint*1.0;
					if(couple[i].gtype.compare("Choosy")==0)
						couple[i].happiness += log(tc+tl)-log(couple[i].gbud);
					else if(couple[i].gtype.compare("Normal")==0)
						couple[i].happiness += ((tc+tv)/couple[i].gbud);
					else
						couple[i].happiness += exp(tc/couple[i].gbud);
				}
				printf("\n");
				couple[i].compatibility = (couple[i].bbud-couple[i].gbud) + abs(couple[i].bint-couple[i].gint) + abs(couple[i].batt-couple[i].gatt);
				fprintf(fcc,"%s %s %.3lf %d\n",couple[i].bname.c_str(),couple[i].gname.c_str(),couple[i].happiness,couple[i].compatibility);
			}
			fclose(fcc);
			return 0;
		}
		
};
