#include<iostream>
#include<string>
using namespace std;

//访问权限
//三种
//公共权限  public     成员  类内可以访问，类外可以访问
//保护权限  protect   成员  类内可以访问，类外不可以访问      子成员访问父成员保护内容
//私有权限  private   成员  类内可以访问，类外不可以访问      子成员不可以访问父成员保护内容
//默认权限是 private
class  person
{
private:
    /* 私有权限*/
    string m_Name;    //姓名
protected:
    /* 保护权限*/   
    string m_Car;
public:
    /*公有权限*/
    int m_Password; //银行卡密码

public:
    void func()
    {
        m_Name="张三";
        m_Car="拖拉机";
        m_Password=1223;
    }
};

struct C1
{
    /* 默认是公共权限*/
    int m_A; 
}s;

int main()
{
    person p1;
    // p1.m_Name="李四";           //私有权限无法访问
    //p1.m_Car="奔驰";             //保护权限无法访问
    p1.m_Password =123;  
    s.m_A=123;
    system("pause");
    return 0;
}