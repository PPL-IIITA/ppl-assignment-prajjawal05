class util
{
  public:
      int coupling()
      {
        boys bo; girls gfg;
	      int nb=bo.readboyscount();
	      int ng=gfg.readgirlscount();
	      boys *boyss = new boys[nb];
	      girls *girlss= new girls[ng];
	      couples cc;
	      bo.input(boyss,nb); //!taking boys input from boys.txt .
	      gfg.input(girlss,ng); //!taking girls input from boys.txt.
	      cc.pairing(boyss,girlss,nb,ng); //!pairing girl-boys if attractive of girl is greater than boy's reqquirement, satisfying the budget of boy and boys fall under the selection criterion of girl.
	      bo.logging(boyss,nb); //!inserting into log file relations of a boy.
        //printf("1\n\n\n\n");
        return 0;
	     }
       int gifting()
       {
         couples cc;
       	 int count = cc.readcouplecount(); //!counting the number of couples.
       	 couples *couple = new couples[count];
       	 cc.input(couple,count); //!Reading couples data from couples.txt.
       	 gifts gg;
       	 int ngf = gg.readgiftscount();
       	 gifts *gif = new gifts[ngf];
       	 gg.input(gif,ngf); //!Reading the types of gifts.
       	 cc.couplegifting(couple,count,gif,ngf); //!Gift exchanges,happiness and compatibility calculation and inserting into log file and fcalc.txt.
         return 0;
       }
       int most(int k)
       {
         couples cc;
       	 int count = cc.readcouplecount(); //!counting the number of couples.
       	 couples *coup = new couples[count];
       	 cc.input1(coup,count); //!Reading the happiness and compatibility of couples in couples* coup.
       	 cc.mosthappy(coup,count,k);	//!find the k-most happy couple.
         return 0;
       }
};
