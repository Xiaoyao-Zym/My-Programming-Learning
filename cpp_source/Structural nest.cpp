#include <iostream>
#include <string>
using namespace std;
//结构体定义
struct Student
{
    //成员信息列表
    string name;
    int    age;
    int    score;
};
struct Teacher
{
    //成员信息列表
    int            ID;
    string         name;
    int            age;
    struct Student stu;
};
int main()
{
    //创建结构体嵌套
    struct Teacher s2 = {1000, "老李", 25, {"张三", 18, 100}};
    //创建结构体指针指向结构体变量
    struct Teacher* p = &s2;
    //通过指针访问结构体变量数据
    cout <<"姓名：" << p->name << endl
         << " 年龄：" << p->age << endl
         << "老师的学生信息：" << endl
         << "姓名：" << p->stu.name << endl
         << "年龄：" << p->stu.age << endl
         << "分数：" << p->stu.score << endl;
    system("pause");
}
