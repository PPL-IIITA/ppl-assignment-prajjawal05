template <class T> class kbest
{
    public:
      void ret_best( T a[] ,int ar[],int n)
      {
        int i,j,t;
        T tmp;
        for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                if(ar[i]>ar[j])
                {
                  t=ar[i];
                  ar[i]=ar[j];
                  ar[j]=t;
                  tmp=a[i];
                  a[i]=a[j];
                  a[j]=tmp;
                }
            }
        }
    }
};
