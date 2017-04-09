class gifts
{
	public:
		std::string type;	//!attributes of gifts.
		int value,price;
		int readgiftscount()
		{
			char p;
			int count=0;
			FILE *fp = fopen("gifts.txt","r");
			for (p = getc(fp); p != EOF; p = getc(fp))
				if (p == '\n') //! Increment count if this character is newline.
					count = count + 1; //!number of couples.
			fclose(fp);
			return count;
		}
		int input(gifts *gif,int ngf)	//!reading gifts data.
		{
			FILE *fp1=fopen("gifts.txt","r");
			char a[15];
			for(int i=0;i<ngf;i++)
			{
				fscanf(fp1,"%s %d %d",a,&gif[i].price,&gif[i].value);
				gif[i].type = a;
			}
			fclose(fp1);
			return 0;
		}
};
