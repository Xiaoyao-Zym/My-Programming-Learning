#include<iostream>
#include<list>
using namespace std;
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list������С����
void size()
{
    list<int>L1;
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   printList(L1);
   //�ж������Ƿ�Ϊ��
   if (L1.empty())
   {
       cout<<"L1Ϊ��"<<endl;
   }
   else
   {
       cout<<"L1��Ϊ��"<<endl;
       cout<<"L1�Ĵ�С��"<<L1.size()<<endl;
   }
   //����ָ����С
   L1.resize(10, 1000);
   printList(L1);
}
int main()
{
    size();
    system("pause");
    return 0;
}