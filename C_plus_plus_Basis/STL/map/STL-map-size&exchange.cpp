#include<iostream>
#include<map>
using namespace std;
void printMap(map<int, int>&m)
{
    for (map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<"key="<<(*it).first<<"value="<<it->second<<endl;
    }
    cout<<endl;
}
//map������С�ͽ���
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(30, 40));
    m.insert(pair<int, int>(50, 60));
    if (m.empty())
    {
        cout<<"m����Ϊ��";
    }
    else
    {
        cout<<"m������Ϊ��"<<m.size()<<endl;
    }
    printMap(m);
    map<int, int>m1;
    m1.insert(pair<int, int>(12, 13));
    m1.insert(pair<int, int>(14, 15));
    m1.insert(pair<int, int>(16, 17));
    m1.insert(pair<int, int>(18, 19));
    cout<<"����ǰ"<<endl;
    m1.swap(m);
    printMap(m);
    printMap(m1);
}
int main()
{
    test();
    system("pause");
    return 0;
}