#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int  i, num=0;
    cout<<"1000���ڵ�ˮ�ɻ�����"<<endl;
    for (i = 100; i <1000000; i++)
    {
        num=pow((i%10),3)+pow(((i/10)%10),3)+pow((i/100),3);
        if (num==i)
        {
            cout<<i<<endl;
        }
    }
    system("pause");
}