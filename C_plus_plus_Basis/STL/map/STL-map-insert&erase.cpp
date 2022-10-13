#include<iostream>
#include<map>
using namespace std;
void printMap(map<int, int>&m)
{
    for (map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<"key=  "<<it->first<<" "<<"value= "<<it->second<<endl;
    }
    cout<<endl;
}
//map容器  插入和删除
void test()
{
    map<int, int>m;
    //插入1
    m.insert(pair<int, int>(1,10));
    //插入2
    m.insert(make_pair(2,10));
    //插入3
    m.insert(map<int, int>::value_type(3,10));
    //插入4
    m[2]=40;     //不建议使用
    //删除
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);
    //清空
    m.erase(m.begin(), m.end());
    m.clear();
}
int main()
{
    test();
    system("pause");
    return 0;
}