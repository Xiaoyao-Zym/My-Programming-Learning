#include<iostream>
#include<map>
using namespace std;
//map容器 构造和赋值
void printMap(map<int, int>&m)
{
    for (map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<"key="<<(*it).first<<"value="<<it->second<<endl;
    }
    cout<<endl;
}
void test01()
{
    //创建map容器
    map<int, int>m;
    m.insert(pair<int, int>(90, 80));
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(30, 40));
    m.insert(pair<int, int>(50, 90));
    printMap(m);
    //拷贝构造
    map<int, int>m2(m);
    printMap(m2);
    //赋值
    map<int, int>m3;
    m3=m2;
    printMap(m3);
}
int main()
{
    test01();
    system("pause");
    return 0;
}