class util
{
public:
  int coupling()
  {
    boys bo; girls gg;
  	int nb=bo.readboyscount();	//!Reading the count of boys from "boys.txt" .
  	int ng=gg.readgirlscount(); //!Reading the count of boys from "boys.txt" .
  	boys *boyss = new boys[nb];
  	girls *girlss= new girls[ng];
  	couples cc;
  	bo.input(boyss,nb); //!taking boys input from boys.txt .
  	gg.input(girlss,ng); //!taking girls input from boys.txt.
  	cc.pairing(boyss,girlss,nb,ng); //!pairing girl-boys if attractive of girl is greater than boy's reqquirement, satisfying the budget of boy and boys fall under the selection criterion of girl.
  	bo.printrelation(boyss,nb); //!printing girlfriend of a boy if he is committed.
    return 0;
  }
};
