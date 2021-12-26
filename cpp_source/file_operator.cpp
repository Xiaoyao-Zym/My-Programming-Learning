#include<iostream>
#include<fstream>
using namespace std;
void test01()
{
    //1.包含头文件fstream
    //2.创建流对象
    ofstream  ofs;
    //3.指定打开方式
    ofs.open("test.txt ", ios :: out);  //绝对路径或者相对路径
    //4.写内容
    ofs<<"姓名：张三"<<endl;
    //5.关闭文件
    ofs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}