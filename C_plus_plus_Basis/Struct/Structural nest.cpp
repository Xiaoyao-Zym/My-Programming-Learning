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
};
struct Teacher
{
    //��Ա��Ϣ�б�
    int            ID;
    string         name;
    int            age;
    struct Student stu;
};
int main()
{
    //�����ṹ��Ƕ��
    struct Teacher s2 = {1000, "����", 25, {"����", 18, 100}};
    //�����ṹ��ָ��ָ��ṹ�����
    struct Teacher* p = &s2;
    //ͨ��ָ����ʽṹ���������
    cout <<"������" << p->name << endl
         << " ���䣺" << p->age << endl
         << "��ʦ��ѧ����Ϣ��" << endl
         << "������" << p->stu.name << endl
         << "���䣺" << p->stu.age << endl
         << "������" << p->stu.score << endl;
    system("pause");
}
