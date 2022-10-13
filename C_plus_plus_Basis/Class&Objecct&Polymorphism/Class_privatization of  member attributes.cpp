#include<iostream>
#include<string>
using namespace std;

//成员属性私有化
class Person
{
private:
    /* 姓名 , 可读可写*/  
    string m_Name;
    /* 年龄*， 只读*/
    int m_Age;
    /* 爱人*/
    string m_Lover;

public:
    //设置姓名
    void setName(string name)
    {
       m_Name=name;
    }
    //获取姓名
    string getName()
    {
       return m_Name;
    }
   //设置年龄
    void getAge(int age)
    {
       m_Age=22;
       if (age<<0||age>30)
       {
           cout<<"你的年龄有误，你不是逍遥张先生"<<endl;
           return;
       }
       m_Age=age;
    }
    //获取年龄
    int getAge()
    {
       m_Age=22;
       return m_Age;
    }
    //设置爱人信息
    void setLover(string name)
    {
       m_Lover=name;
    }
    //获取爱人信息
    string getLover()
    {
       return m_Lover;
    }
};
int main()
{
   Person s;
   int a;
   cin>>a;
   s.getAge(a);
   s.setName("逍遥张");
   s.setLover("裴秀智");
   cout<<"姓名："<<s.getName()<<endl;
   cout<<"年龄："<<s.getAge()<<endl;
   cout<<s.getName()<<"先生的爱人是"<<s.getLover()<<"小姐"<<endl;
   system("pause");
   return 0;
}