#include<set>
#include<iostream>
using namespace std;
//set��mutiset����
void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret=s.insert(10);
    if (ret.second)
    {
        cout<<"��һ�β���ɹ�"<<endl;
    }
    else
    {
        cout<<"��һ�β���ʧ��"<<endl;
    }
    ret=s.insert(10);
     if (ret.second)
    {
        cout<<"��һ�β���ɹ�"<<endl;
    }
    else
    {
        cout<<"��һ�β���ʧ��"<<endl;
    }
    multiset<int>ms;
    //��������ظ�ֵ
    ms.insert(10);
    ms.insert(10);
    for (set<int>::iterator it=ms.begin(); it!=ms.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}