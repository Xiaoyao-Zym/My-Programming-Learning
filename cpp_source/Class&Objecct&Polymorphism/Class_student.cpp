#include<iostream>
#include<string>
using namespace std;

class student
{
private:
    /* data */
public:
    //类属性和行为 统称为成员
    //属性：成员属性  成员变量
    //行为：成员函数  成员方法
    //属性
    string m_name;
    string m_ID;

    //行为
    void Input()
    {
        cout<<"请输入学生姓名和ID";
        cin>>m_name;
        cin>>m_ID;
    }
    void Output()
    {
        cout<<"姓名："<<m_name<<"ID："<<m_ID<<endl;
    }
};
int main()
{
    student s;  //创建类实例
    s.Input();
    s.Output();   
    system("pause");
    return 0;
}