#include<iostream>
#include<string>
using namespace std;
//?ַ?????ֵ
void test01()
{
    string str1;
    str1="hello world";
    cout<<"str1="<<str1<<endl;
    string str2;
    str2=str1;
    cout<<"sttr2="<<str2<<endl;
    string str3;
    str3.assign("hello C++");
    cout<<"str3="<<str3<<endl;
    string str4;
    str4.assign("hello C++",2);
    cout<<"str4="<<str4<<endl;
    string str5;
    str5.assign(str4);
    cout<<"str5="<<str5<<endl;
    string str6;
    str6.assign(10,'w');
    cout<<"str6="<<str6<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}