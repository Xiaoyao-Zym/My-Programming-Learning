#include<iostream>
#include<map>
using namespace std;
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }
};
void printMap(map<int, int, MyCompare>&m)
{
    for (map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<"key=  "<<it->first<<" "<<"value= "<<it->second<<endl;
    }
    cout<<endl;
}
//mapÈİÆ÷  ÅÅĞò
void test()
{
    map<int, int, MyCompare>m;
    m.insert(pair<int, int>(12, 13));
    m.insert(pair<int, int>(14, 15));
    m.insert(pair<int, int>(16, 17));
    m.insert(pair<int, int>(18, 19));
    m.insert(make_pair(9, 10));
    printMap(m);
}
int main()
{
    test();
    system("pause");
    return 0;
}