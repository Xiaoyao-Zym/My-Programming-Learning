#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//adjacent_find
void test()
{
    vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    vector<int>::iterator it=adjacent_find(v.begin(), v.end());
    if (it==v.end())
    {
        cout<<"û���ҵ�"<<endl;
    }
    else
    {
        cout<<"�ҵ�Ԫ�أ�"<<*it<<endl;
    }
}
int main()
{
    test();
    system("pause");
    return 0;
}