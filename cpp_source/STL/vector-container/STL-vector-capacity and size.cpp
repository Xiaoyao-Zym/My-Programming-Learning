#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//vector����f�����ʹ�С
void test()
{
   vector<int>v1;                 //Ĭ�Ϲ���
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   //�ж������Ƿ�Ϊ��
   if (v1.empty())
   {
       cout<<"v1����Ϊ��"<<endl;
   }
   else
   {
       cout<<"v1��Ϊ��"
              <<"v1������Ϊ��"<<v1.capacity()
              <<"  v1�Ĵ�СΪ"<<v1.size()<<endl;
   }
   v1.resize(18, 10);  //�������ָ��������Ĭ����0��䣬Ҳ��ָ���滻����
   v1.resize(9);       //�������ָ�����̣���ɾ����������
   printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}