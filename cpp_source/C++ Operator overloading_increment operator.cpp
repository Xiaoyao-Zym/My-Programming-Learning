#include<iostream>
using namespace std;
//���ص��������
//ǰ�õ����������ã����õ�������ֵ
class MyInteger
{
   friend ostream& operator<<(ostream&cout, MyInteger myit);
public:
   MyInteger()
   {
       m_Num = 0;
   }
   //����ǰ��++�����������������Ϊһֱ��һ����ֵ����
   MyInteger &operator++()
   {
      //�Ƚ���++����
       m_Num++;
       return *this;
   }
  // ���غ���++
   MyInteger operator++(int) //int��������ǰ�úͺ��õ���
   {
        //�ȼ�¼���
       MyInteger  temp=*this;
       m_Num++;
       //�ٷ���
       return temp;
   }
private:
   int m_Num;
};
//����<<�����
ostream& operator<<(ostream& cout, MyInteger myit)
{
    cout<<myit.m_Num<<endl;
    return cout;
}
void test01()
{
    MyInteger myint;
    cout<<++myint<<endl;
}
void test02()
{
    MyInteger myint;
    cout<<myint++<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}