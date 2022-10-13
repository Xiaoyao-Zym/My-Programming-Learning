#include<iostream>
#include<string>
using namespace std;
int main()
{
    int m=0,n=0;
    string s;
    getline(cin,s);
    int len = s.size();
    char item[5][10];
    for(int i=0; i<len; i++)
    {
        if (s[i]!=' ')
        {
            item[m][n]=s[i];
            n++;
        }
         else
        {
            m++;
            n=0;
        }
    }
    for (int j = 0; j < (m+1); j++)
    {
        cout<<item[j];
    }
    system("pause");
}       