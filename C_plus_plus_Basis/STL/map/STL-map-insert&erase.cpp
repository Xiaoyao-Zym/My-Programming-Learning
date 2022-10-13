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
//map����  �����ɾ��
void test()
{
    map<int, int>m;
    //����1
    m.insert(pair<int, int>(1,10));
    //����2
    m.insert(make_pair(2,10));
    //����3
    m.insert(map<int, int>::value_type(3,10));
    //����4
    m[2]=40;     //������ʹ��
    //ɾ��
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);
    //���
    m.erase(m.begin(), m.end());
    m.clear();
}
int main()
{
    test();
    system("pause");
    return 0;
}