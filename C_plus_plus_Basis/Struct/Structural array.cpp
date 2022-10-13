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
    //创建结构体数组
    struct Student s2[3] = {
        {"张三", 18, 100},
        {"李四", 19, 100},
        {"王五", 20, 100},
    };
    //结构体数组赋值
    s2[2].name = "赵六";
    //结构体遍历
    for (int i = 0; i < 3; i++) {
        cout << "姓名：" << s2[i].name << "年龄：" << s2[i].age << "分数："
             << s2[i].score << endl;
    }
    system("pause");
}
