#include<iostream>
using namespace std;
int main()
{
    int score=0;
    cout <<"�����Ӱ���д��"<<endl;
    cin>>score;
    switch (score)
    {
    case 10:
        cout<<"����Ϊ�Ǿ����Ӱ"<<endl;
        break;
     case 9:
        cout<<"����Ϊ�Ǿ����Ӱ"<<endl;
        break;
     case 8:
        cout<<"����Ϊ��Ӱ�ǳ���"<<endl;
        break;
     case 7:
        cout<<"����Ϊ��Ӱ�ǳ���"<<endl;
        break;
     case 6:
        cout<<"����Ϊ��Ӱһ��"<<endl;  
        break;
     case 5:
        cout<<"����Ϊ��Ӱһ��"<<endl;
        break;
    default:
        cout<<"����Ϊ��һ����Ƭ"<<endl;
        break;
    }
    system("pause");
}