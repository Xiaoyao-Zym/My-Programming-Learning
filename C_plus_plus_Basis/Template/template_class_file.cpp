/*********��ģ����ļ���д**********
 * 1��ֱ�Ӱ���ͷ�ļ�
 * 2���� .h�� .cpp�ļ�����д��һ�飬����׺����Ϊ .hpp�ļ�
 * ��ģ��ͷ�ļ�
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
 // ��ģ���Ա����
/*********template_class.cpp*********
 #include<template_class_file.h>
template<class T1, class T2>
void  Person <T1, T2>:: showPerson()
{
    cout<<"������"<<this->m_Name<<"���䣺"<<this->m_Age<<endl;
}
**************************************/
//������
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