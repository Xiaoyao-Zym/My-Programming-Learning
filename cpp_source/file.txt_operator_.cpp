#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void test01()
{
    //1.����ͷ�ļ�fstream
    //2.����������
    ofstream  ofs;
    //3.ָ���򿪷�ʽ
    ofs.open("test.txt ", ios :: out);  //����·���������·��
    //4.д����
    ofs<<"����������"<<endl;
    //5.�ر��ļ�
    ofs.close();
}
void test02()
{
    //1.����ͷ�ļ�
    //2.����������
    ifstream ifs;
    //3. ���ļ��������ж��Ƿ�򿪳ɹ�
    ifs.open("test01.txt", ios :: in);
    if(!ifs.is_open())
    {
        cout<<"�ļ���ʧ��"<<endl;
        return;
    }
    //4.������
    char buf[1024]={0};
    //��һ�ַ���
    while (ifs>>buf)
    {
        cout<<buf<<endl;
    }
    //�ڶ��ַ���
    while (ifs.getline(buf, 1024))
    {
        cout<<buf<<endl;
    }
    //�����ַ���
    char c;
    while (c=ifs.get()!=EOF)//EOF end of file
    {
        cout<<c<<endl;
    }
    
    //�ر��ļ�
    ifs.close();
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}