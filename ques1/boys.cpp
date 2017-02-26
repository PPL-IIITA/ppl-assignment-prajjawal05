#include<fstream>
class boys
{
	public:
		std::string name,type,girlname;
		int attractiveness,intelligence,budget,happiness,committed,min_attractive;
		int readboyscount()
		{
			char p;
			int count=0;
			FILE *fp = fopen("boys.txt","r");
			for (p = getc(fp); p != EOF; p = getc(fp))
				if (p == '\n') //! Increment count if this character is newline.
					count = count + 1; //!number of couples.
			fclose(fp);
			return count;
		}
		int input(boys *boyss,int nb)	//!boys data input.
		{
			FILE* fb=fopen("boys.txt","r");
			char nme[10],nme2[10],nme3[20];
			for(int i=0;i<nb;i++)
			{
				fscanf(fb,"%s %s %d %d %d %d",nme,nme2,&boyss[i].attractiveness,&boyss[i].intelligence,&boyss[i].budget,&boyss[i].min_attractive);
				boyss[i].name=nme;
				boyss[i].type=nme2;
				boyss[i].committed=0;
			}
			fclose(fb);
			return 0;
		}
		int printrelation(boys* boyss,int nb) //!print girlfriend for a boyfriend if exists and inserts it into log file.
		{
			std::ofstream outfile;
		  outfile.open("log.txt", std::ios_base::app);
			for(int i=0;i<nb;i++)
			{
				time_t now = time(0);
				char* dt = ctime(&now);
				if(boyss[i].committed == 1)
				{
					printf("%s in relationship with %s\n",boyss[i].name.c_str(),boyss[i].girlname.c_str());
					outfile<<"New Relationship ----"<<" "<<dt<<" "<<boyss[i].name<<" in relationship with "<<boyss[i].girlname<<"\n";
				}
			}
			return 0;
		}
};
