#include<iostream>
#include<set>
using namespace  std;
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set�������Һ�ͳ��
void test01()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    s.insert(10);
    s.insert(80);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //����
    set<int>:: iterator pos =s.find(30);
    if (pos!=s.end())
    {
        cout<<"�ҵ�Ԫ�أ�"<<endl;
    }
}
void test02()
{
    //����
    set<int>s;
    //��������
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //ͳ��30�ĸ���
    int num=s.count(30);
    cout<<"������"<<num<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}