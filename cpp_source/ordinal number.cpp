#include<iostream>
using namespace std;
int main()
{
	long long M=0, num ;  //��int�Ļ����ܺ�������������⣬�����ֹ�����������
    cout<<"������һ������λ��������";
	cin>>num;
	int i=0;  //һ��Ҫ��ʼ���������ʼ��Ϊ1����Ϊѭ��һ��ʼ�ͽ�numȥ����һλ��
	while(num!=0)   //����һλ����ȥ��һλ
	{
		M=M*10 +num%10;
        i++;   //����
        num/=10;
	} 
	cout<<"�������ǣ�"<<M<<endl;
    system("pause");
	return 0;
}
