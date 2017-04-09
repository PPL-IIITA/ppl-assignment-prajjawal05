class girls:public attributes
{
	public:
		std::string boyname,need;	//!attributes of girls.
		int maintenance;
		int readgirlscount()
		{
			char p;
			int count=0;
			FILE *fp = fopen("girls.txt","r");
			for (p = getc(fp); p != EOF; p = getc(fp))
				if (p == '\n') //! Increment count if this character is newline.
					count = count + 1; //!number of couples.
			fclose(fp);
			return count;
		}
		int input(girls* girlss,int ng) //!reading girls data.
		{
			FILE* fg=fopen("girls.txt","r");
				char nme[10],nme2[10],nme3[20];
			for(int i=0;i<ng;i++)
			{
				fscanf(fg,"%s %s %s %d %d %d",nme,nme2,nme3,&girlss[i].attractiveness,&girlss[i].intelligence,&girlss[i].maintenance);
				girlss[i].name = nme;
				girlss[i].type = nme2;
				girlss[i].need = nme3;
				girlss[i].committed=0;
			}
			fclose(fg);
			return 0;
		}
};
