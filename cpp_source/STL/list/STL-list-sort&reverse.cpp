#include<iostream>
#include<list>
using namespace std;
//list ��ת������
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool myCompare(int v1, int v2)
{
    //����
    return v1>v2;
}
void test()
{
    //��ת
    list<int> L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);
    cout<<"��תǰ��"<<endl;
    L1.reverse();
    cout<<"��ת��"<<endl; 
    printList(L1);
    //����
    cout<<"����ǰ��"<<endl;
    printList(L1);
    L1.sort();   //Ĭ������
    cout<<"�����"<<endl;
    printList(L1);
    //���в�֧��������ʵ��������������������ñ�׼�㷨
    //��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
    L1.sort(myCompare);
    cout<<"�����"<<endl;
    printList(L1);
}
int main()
{
    test();
    system("pause");
    return 0;
}