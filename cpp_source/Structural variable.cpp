#include <iostream>
#include <string>
using namespace std;
//�ṹ�嶨��
struct Student
{
    //��Ա��Ϣ�б�
    string name;
    int    age;
    int    score;
} s3;  //�ṹ�����������ʽ3
int main()
{
    //�ṹ�����������ʽ1
    struct Student s1;  //�ṹ���������ʱ�ؼ��ֿ���ʡ��
    s1.name  = "����";
    s1.age   = 18;
    s1.score = 100;
    cout << "������" << s1.name << "���䣺" << s1.age << "������" << s1.score
         << endl;
    //�ṹ�����������ʽ2
    struct Student s2 = {"����", 18, 100};
    cout << "������" << s2.name << "���䣺" << s2.age << "������" << s2.score
         << endl;
    //�ṹ�����������ʽ3
    struct Student s3 = {"����", 18, 100};
    cout << "������" << s3.name << "���䣺" << s3.age << "������" << s3.score
         << endl;
    system("pause");
}
