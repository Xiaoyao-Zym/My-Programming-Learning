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
//set������С�ͽ���
//��С
void size()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //��ӡ����
    printSet(s);
    //�ж��Ƿ�Ϊ��
    if (s.empty())
    {
        cout<<"sΪ��"<<endl;
    }
    else
    {
        cout<<"s��Ϊ��"<<endl;
        cout<<"s�Ĵ�С"<<s.size()<<endl;
    }
}
//����
void exchange()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    set<int>s1;
    //�������ݣ�ֻ���� insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s1.insert(60);
    s1.insert(70);
    s1.insert(80);
    s1.insert(90);
    s1.insert(100);
    cout<<"����ǰ��"<<endl;
    printSet(s);
    printSet(s1);
    s1.swap(s);
    cout<<"������"<<endl;
    printSet(s);
    printSet(s1);
}
int main()
{
    size();
    exchange();
    system("pause");
    return 0;
}