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
//set��������͸�ֵ
void test()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //��������
    //set�����ص㣬����Ԫ�ز���ʱ���Զ�����
    //set��������������ظ�ֵ
    printSet(s);
    //��������
    set<int>s2(s);
    printSet(s2);
    //��ֵ
    set<int>s3;
    s3=s2;
    printSet(s3);
}
int main()
{
    test();
    system("pause");
    return 0;
}