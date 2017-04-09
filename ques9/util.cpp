#include"kbest.cpp"
using namespace std;

class util
{
  public:
      int coupling(int k)
      {
        boys bo; girls gfg;
	      int nb=bo.readboyscount();
	      int ng=gfg.readgirlscount();
        int a[nb],b[ng];
	      boys *boyss = new boys[nb];
	      girls *girlss= new girls[ng];
	      couples cc;
	      bo.input(boyss,nb); //!taking boys input from boys.txt
        for(int i=0;i<nb;i++)
          a[i] = boyss[i].budget;
	      gfg.input(girlss,ng);
        for(int i=0;i<ng;i++)
          b[i] = girlss[i].maintenance;//!taking girls input from boys.txt.
	      kbest<boys> kboys;
        kbest<girls> kgirls;
        kboys.ret_best(boyss,a,nb);
        kgirls.ret_best(girlss,b,ng);
        cout<<"---------- BEST RELATIONShIPS ------------\n"<<endl;
        cc.pairing(boyss,girlss,k,ng);  //!first priority for selection of boys will be budget and their second priority will be according to the girl type and the top "k" are eligible for the girls.
        //printf("1\n\n\n\n");
        return 0;
	     }
       int gifting(int k)
       {
         couples cc;
       	 int count = cc.readcouplecount(); //!counting the number of couples.
       	 couples *couple = new couples[count];
       	 cc.input(couple,count); //!Reading couples data from couple.txt.
       	 gifts gg;
       	 int ngf = gg.readgiftscount();
         int a[ngf];
       	 gifts *gif = new gifts[ngf];
       	 gg.input(gif,ngf); //!Reading the types of gifts.
         kbest<gifts> kgifts;
         for(int i=0;i<ngf;i++)
           a[i] = gif[i].value;
         kgifts.ret_best(gif,a,ngf);
         //sort(a,a+ngf);
         //for(int i=0;i<ngf;i++)
         cout<<"---------- GIFTINGS ------------"<<endl;
         cc.couplegifting(couple,count,gif,k); //!Gift exchanges among k best gifts,happiness and compatibility calculation and inserting into log file and fcalc.txt.
         return 0;
       }
};
