#include<iostream>
using namespace std;
#define M 9
int main()
{
    int i, j, data[M]={4, 2, 3, 5, 1, 9, 7, 8, 6};
    cout<<"����ǰ��"<<endl;
    for (i = 0; i < M; i++)
    {
        cout<<data[i];
    }
   
    //��ʼð������
    //����������Ԫ�ظ���-1
    for (i = 0; i < M-1; i++)
    {
        //�ڲ�ѭ���Աȴ�����Ԫ�ظ���-��ǰ����-1
        for (j = 0; j <M-i-1 ; j++)
        {
            if (data[j]>data[j+1])
            {
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
     cout<<"�����"<<endl;
     for (i = 0; i < M; i++)
    {
        cout<<data[i];
    }
    system("pause");
}