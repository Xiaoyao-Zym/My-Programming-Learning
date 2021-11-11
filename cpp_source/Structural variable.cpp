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
} s3;  //结构体变量创建方式3
int main()
{
    //结构体变量创建方式1
    struct Student s1;  //结构体变量定义时关键字可以省略
    s1.name  = "张三";
    s1.age   = 18;
    s1.score = 100;
    cout << "姓名：" << s1.name << "年龄：" << s1.age << "分数：" << s1.score
         << endl;
    //结构体变量创建方式2
    struct Student s2 = {"张三", 18, 100};
    cout << "姓名：" << s2.name << "年龄：" << s2.age << "分数：" << s2.score
         << endl;
    //结构体变量创建方式3
    struct Student s3 = {"张三", 18, 100};
    cout << "姓名：" << s3.name << "年龄：" << s3.age << "分数：" << s3.score
         << endl;
    system("pause");
}
