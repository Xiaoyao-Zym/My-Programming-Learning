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
                    cout<<"�²����"<<endl;
                    break;
            }
    else if (val>number)
            {
                    cout<<"�²��С"<<endl;
                    break;
            }
            else
                    cout<<"��ϲ�²���ȷ"<<endl;
                    break;
    }
    system("pause");
}