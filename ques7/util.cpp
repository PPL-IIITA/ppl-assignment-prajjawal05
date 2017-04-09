#include<map>
#include<string>
using namespace std;

map<string,string> m1; //! used a hash table to store name of partner.
map<string,int> m2;

class util
{
  public:
      int coupling(string x[],int n)
      {
        boys bo; girls gfg; int c;
	      int nb=bo.readboyscount();
	      int ng=gfg.readgirlscount();
	      boys *boyss = new boys[nb];
	      girls *girlss= new girls[ng];
	      couples cc;
	      bo.input(boyss,nb); //!taking boys input from boys.txt .
	      gfg.input(girlss,ng); //!taking girls input from boys.txt.
	      cc.pairing(boyss,girlss,nb,ng); //!pairing girl-boys if attractive of girl is greater than boy's reqquirement, satisfying the budget of boy and boys fall under the selection criterion of girl.
	      bo.logging(boyss,nb); //!inserting into log file relations of a boy.
        //couples cc;
        int count = cc.readcouplecount(); //!counting the number of couples.
        couples *couple = new couples[count];
        cc.input(couple,count);
        //std::vector< pair<string,string> > committedboys;
        string committedboys[count];
        for(int i=0;i<count;i++)
        {
          for(int j=0;j<nb;j++)
          {
            if(boyss[j].committed == 1)
            {
              committedboys[i] = boyss[j].name;//.push_back(make_pair(boyss[j].name,boyss[j].girlname));// =  //!created an array of name of committedboys.
              m2[boyss[j].name] = 1; //created a map(hashtable) of committedboys.
              m1[boyss[j].name] = boyss[j].girlname;
              boyss[j].committed = 2;
              break;
            }
          }
        }
        c = rand()%99;
        if(c%76==70)                                            //!usinglinearsearch.
        {
          printf("\nUsing linear search in an unsorted array\n\n");
          for(int i=0;i<n;i++)
          {
            int flag=0;
            for(int j=0;j<count;j++)
            {
              if(committedboys[j] == x[i])
              {
                flag=1;
                break;
              }
            }
            if(flag==1)
              cout<<x[i]<<" is in relationship with "<<m1[x[i]]<<"\n";
            else
              cout<<x[i]<<" is not in relationship\n";
          }
        }
        else if(c%4==2)
        {
          printf("\nUsing binary search in an sorted array\n\n");
          sort(committedboys,committedboys+count);
          for(int i=0;i<n;i++)
          {
            if(binary_search(committedboys,committedboys+count,x[i])) //!using binary_search.
              cout<<x[i]<<" is in relationship with "<<m1[x[i]]<<"\n";
            else
              cout<<x[i]<<" is not in relationship\n";
          }
        }
        else
        {
          printf("\nUsing hashing through mapping\n\n");
          for(int i=0;i<n;i++)
          {
            if(m2[x[i]] == 1) //!using maps as a hashtable.
              cout<<x[i]<<" is in relationship with "<<m1[x[i]]<<"\n";
            else
              cout<<x[i]<<" is not in relationship\n";
          }
        }
        //printf("1\n\n\n\n");
        return 0;
	     }
};
