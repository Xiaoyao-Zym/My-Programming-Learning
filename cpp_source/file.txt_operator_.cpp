#include<iostream>
#include<string>
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
void test02()
{
    //1.包含头文件
    //2.创建流对象
    ifstream ifs;
    //3. 打开文件，并且判断是否打开成功
    ifs.open("test01.txt", ios :: in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    //4.读数据
    char buf[1024]={0};
    //第一种方法
    while (ifs>>buf)
    {
        cout<<buf<<endl;
    }
    //第二种方法
    while (ifs.getline(buf, 1024))
    {
        cout<<buf<<endl;
    }
    //第三种方法
    char c;
    while (c=ifs.get()!=EOF)//EOF end of file
    {
        cout<<c<<endl;
    }
    
    //关闭文件
    ifs.close();
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}