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
//map容器  查找和统计
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(12, 13));
    m.insert(pair<int, int>(14, 15));
    m.insert(pair<int, int>(16, 17));
    m.insert(pair<int, int>(18, 19));
    //查找
    map<int, int>::iterator pos=m.find(3);
    if (pos!=m.end())
    {
        cout<<"查到了元素key= "<<(*pos).first<<"value="<<pos->second<<endl;
    }
    else
    {
        cout<<"未找到元素"<<endl;
    }
    //统计
    //map不允许插入重复key元素，count统计而言，结果要么是0，要么是1
    //mutimap的count统计可能大于1
    int num=m.count(13);
    cout<<"num="<<num<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}