#include<iostream>
#include<set>
using namespace std;
//pair����Ĵ���
void test()
{
    //��һ�ַ�ʽ
    pair<string,int>p1("Ton", 20);
    cout<<"������"<<p1.first<<"���䣺"<<p1.second<<endl;
    //�ڶ��ַ�ʽ
    pair<string, int>p2=make_pair("jenrry", 10);
    cout<<"������"<<p2.first<<"���䣺"<<p2.second<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}