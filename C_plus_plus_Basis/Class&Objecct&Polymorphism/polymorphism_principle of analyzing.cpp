#include<iostream>
using namespace std;
//��̬
//��̬��̬���������غ������������ھ�̬��̬�����ú���������̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
//��̬��̬����������麯��ʵ�����ж�̬����̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ
//������
class Animal
{
public:
    //speak���������麯��
    //����ǰ�����virtual�ؼ��֣���Ϊ�麯������ô�������ڱ����ʱ��Ͳ���ȷ������������
    virtual void  speak()
    {
        cout<<"������˵��"<<endl;
    }
};
//è��
class Cat : public Animal
{
public:
    //��д  ��������ֵ���� ������  �����б�  ��ȫһ��
    virtual void speak()
    {
        cout<<"Сè��˵��"<<endl;
    }
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout<<"С����˵��"<<endl;
    }
};
void doSpeak(Animal &animal)    //Animal &  animal=cat��
{
    animal.speak();
}
void test01()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}
void test02()
{
    cout<<"sizeof Animal= "<<sizeof(Animal)<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}