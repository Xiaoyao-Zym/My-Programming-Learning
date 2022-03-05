#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int  i, j, num=0;
    cout<<"10000以内的质数有"<<endl;
    for (i = 2; i <10000; i++)
    {
        for(j=2; j<i; j++)
        {
            if (i%j==0)
            {
               break;
            }
        }
        if (j==i)
        {
              cout<<i<<' ';
              num++;
                if (num%20==0)
                {
                      cout<<endl;
                }
        }
    }
    system("pause");
    return 0;
}