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
//map����  ���Һ�ͳ��
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(12, 13));
    m.insert(pair<int, int>(14, 15));
    m.insert(pair<int, int>(16, 17));
    m.insert(pair<int, int>(18, 19));
    //����
    map<int, int>::iterator pos=m.find(3);
    if (pos!=m.end())
    {
        cout<<"�鵽��Ԫ��key= "<<(*pos).first<<"value="<<pos->second<<endl;
    }
    else
    {
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }
    //ͳ��
    //map����������ظ�keyԪ�أ�countͳ�ƶ��ԣ����Ҫô��0��Ҫô��1
    //mutimap��countͳ�ƿ��ܴ���1
    int num=m.count(13);
    cout<<"num="<<num<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}