#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//deque����
void printDeque(const deque<int>d)    //�޶�����Ϊֻ��״̬
{
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    deque<int>d;
    for (int i = 10; i > 0; i--)
    {
        d.push_back(i);
    }
    cout<<"����ǰ"<<endl;;
    printDeque(d);
    //����Ĭ���������
    //����֧��������ʵĵ�����������������������sort�㷨
    sort(d.begin(), d.end());
    cout<<"�����"<<endl;
    printDeque(d);
}
int main()
{
    test();
    system("pause");
    return 0;
}