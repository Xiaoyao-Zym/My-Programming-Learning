#include<iostream>
using namespace std;
//��ָ����ʳ�Ա����
class Person
{
public:
   void ShowClassName()
   {
       cout <<"����Person�࣡"<<endl;
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