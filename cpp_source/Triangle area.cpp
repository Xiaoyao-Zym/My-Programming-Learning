#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c;
	double s, A;
	cout<<"Please imput three edges a, b, c=";//输出提示
	cin>> a >> b >> c;                                        //输入
	s=(a+b+c)/2.0;
	A=sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<"The area is "<<A<<endl;
	system("pause");   //以便在退出程序前调用系统的暂停命令暂停命令行
	return 0;
}