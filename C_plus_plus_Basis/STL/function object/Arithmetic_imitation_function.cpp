#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
//�ڽ��������������º���
//negate  һԪ�º��� ��ȡ�� �º���
void test()
{
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus ��Ԫ�º���  �ӷ�
void test01()
{
    plus<int>p;
    cout<<p(2, 3)<<endl;
}
int main()
{
    test01();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    system("pause");
    return 0;
}