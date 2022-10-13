#include<iostream>
using namespace std;
#include<ctime>
int main()
{
    srand((unsigned int) time(NULL));
    int number=rand()%100+1;
    int val=0;
    cin>>val;
    while (1)
    {
         if (val>number)
            {
                    cout<<"猜测过大"<<endl;
                    break;
            }
    else if (val>number)
            {
                    cout<<"猜测过小"<<endl;
                    break;
            }
            else
                    cout<<"恭喜猜测正确"<<endl;
                    break;
    }
    system("pause");
}