/*********类模板分文件编写**********
 * 1、直接包含头文件
 * 2、将 .h和 .cpp文件代码写在一块，将后缀名改为 .hpp文件
 * 类模板头文件
*********template_class.h*********
#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T1, class T2>
class Person
{
public: 
    Person(T1 name, T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
     void showPerson();
    T1 m_Name;
    T2 m_Age;
};
**************************************/
 // 类模板成员函数
/*********template_class.cpp*********
 #include<template_class_file.h>
template<class T1, class T2>
void  Person <T1, T2>:: showPerson()
{
    cout<<"姓名："<<this->m_Name<<"年龄："<<this->m_Age<<endl;
}
**************************************/
//主函数
/********main.cpp*********
#include<iostream>
#include<string>
#include<template_class.cpp>
using namespace std;
void test01()
{
    Person<string,int>p("Marry", 18);
    p.showPerson();
}
int main()
{
    test01();
    system("pause");
}
**************************************/