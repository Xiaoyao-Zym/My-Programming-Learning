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
int main()
{
    //创建结构体变量
    struct Student s2 = {"张三", 18, 100};
    //创建结构体指针指向结构体变量
    struct Student* p = &s2;
    //通过指针访问结构体变量数据
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score
         << endl;
    system("pause");
}
