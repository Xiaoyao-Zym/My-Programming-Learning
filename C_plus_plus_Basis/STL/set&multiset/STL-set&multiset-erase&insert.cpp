#include<iostream>
#include<set>
using namespace  std;
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    set<int>s;
    //����
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    //����
    printSet(s);
    //ɾ��
    s.erase(s.begin());
    printSet(s);
    //ɾ�����ذ汾
    s.erase(30);
    printSet(s);
    //���
    //s.erase(s.begin(), s.end());
    s.clear();
    printSet(s);
}
int main()
{
    test();
    system("pause");
    return 0;
}