#include<iostream>
#include<string>
using namespace std;
/**************
*�ַ���ƴ��
*string& operator+= (const char* str);                    //����+=������
*string& operator+= (const char c);                       //����+=������
*string& operator+= (const string& str);               //����+=������
*string& append (const char *s);                            //���ַ���s���ӵ���ǰ�ַ�����β
*string& append (const char *s, int n);                  //���ַ���s��ǰn���ַ������ӵ���ǰ�ַ�����β
*string& append (const string &s);                        //ͬoperator+=(const string& str)
*string& append(const string &s, int pos, int n);   //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
**************/
void test01()
{
    string str1="��";
    str1+="����";
    cout<<"str1="<<str1<<endl;
    str1+=":";
    cout<<"str1="<<str1<<endl;
    string str2="xxx";
    str1+=str2;
    cout<<"str1="<<str1<<endl;
    str1.append(str2);
    cout<<"str1="<<str1<<endl;
    string str3="I";
    str3.append(" love ");
    str3.append(" your", 4);
    string str4="is your";
    str3.append(str4, 3, 3 );
    cout<<"str3="<<str3<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}