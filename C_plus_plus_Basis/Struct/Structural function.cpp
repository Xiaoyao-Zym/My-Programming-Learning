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

//值传递
void printStudent1(struct Student s)
{
    cout<<"姓名："<<s.name<<"年龄："<<s.age<<"分数："<<s.score<<endl;
}
//地址传递
void printStudent2(struct Student *s)
{
    cout<<"姓名："<<s->name<<"年龄："<<s->age<<"分数："<<s->score<<endl;
}
int main()
{
    //创建结构体变量
    struct Student s = {"张三", 18, 100};
    printStudent1(s);
    //创建结构体指针指向结构体变量
    struct Student * p = &s;  
    printStudent1(*p);
    //通过指针访问结构体变量数据
    system("pause");
}