#include<iostream>
using namespace std;
//空指针访问成员函数
class Person
{
public:
   void ShowClassName()
   {
       cout <<"我是Person类！"<<endl;
   }
   void ShowPersonAge()
   {
       if(this==NULL)
       {
           return;
       }
       cout<<"age="<<m_Age<<endl;
   }
   int m_Age;
};
void test01()
{
    Person *p=NULL;
    p->ShowClassName();
    p->ShowPersonAge();
}
int main()
{
    test01();
    system("pause");
    return 0;
}