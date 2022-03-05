#include<iostream>
#include<string>
using namespace std;
/*****************ͨ�õ�������*******************************
 * ���Զ��������������Լ��Զ����������͵����ݽ��д洢
 * �������е����ݴ洢������
 * ���캯���п��Դ������������
 * �ṩ��Ӧ�Ŀ��������Լ� operator=��ֹǳ��������
 * �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
 * ����ͨ���±�ķ�ʽ����������Ԫ��
 * ���Ի�ȡ�����е�ǰԪ�ظ�������������
 ************************************************************/
template<class T>
class MyArray
{
public:
     //�вι��죬����������
    MyArray(int capacity)
    {
        cout<<"MyArray�вι���"<<endl;
        this->m_Capacity=capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }
    //��������
    MyArray(const MyArray &arr)
    {
        cout<<"MyArray��������"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        //���
        this->pAddress=new T[arr.m_Capacity];
        //��arr�е����ݶ���������
        for (int i = 0; i < this->m_Size;  i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
    }
    //operator=��ֹǳ��������
    MyArray& operator=(const MyArray& arr)
    {
        //���ж�ԭ�������Ƿ������ݣ���������ͷ�
        if (this->pAddress !=NULL)
        {
            delete[] this->pAddress;
            this->pAddress=NULL;
            this->m_Capacity=0;
            this->m_Size=0;
        }
        //���
         cout<<"MyArray operator=��ֵ���� "<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size;  i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
        return *this;
    }
    //β�巨
    void Push_Back(const T&val)
    {
        //�ж������Ƿ���ڴ�С
        if (this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val; //������ĩβ�������ݣ�
        this->m_Size++; //���������С        
    }
    //βɾ�� 
    void Pop_Back()
    {
    //���û����ʵ����һ����Ԫ�أ���Ϊβɾ���߼�ɾ��
         if (this->m_Size==0)
        {
            return;
        }
        this->m_Size--;
    }
    //ͨ���±귽ʽ���������е�Ԫ��  arr[0]=100
    T& operator[] (int index)
    {
        return this->pAddress[index];
    }
    //������������
    int getCapacity()
    {
        return this->m_Capacity;
    }
    //���������С
    int getSize()
    {
        return this->m_Size;
    }
     //��������
    ~MyArray()
    {
        if (this->pAddress!=NULL)
        {
             cout<<"MyArray������������"<<endl;
            delete []this->pAddress;
            this->pAddress=NULL;
        }
    }
private:
    T *pAddress;   //ָ��ָ��������ٵ���ʵ����
    int m_Capacity;
    int m_Size;
};
void printIntArray(MyArray<int>&arr)
{
    for (int i = 0; i <arr.getSize() ; i++)
    {
        cout<<arr[i]<<endl;
    }
}
//����������������
void test01()
{
    MyArray<int>arr1(5);
    // MyArray<int>arr3(100);
    // arr3=arr1;
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    cout<<"arr1�Ĵ�ӡ�����"<<endl;
    printIntArray(arr1);
    cout<<"arr1�Ĵ�СΪ��"<<arr1.getSize()<<endl;
    cout<<"arr1������Ϊ��"<<arr1.getCapacity()<<endl;
    MyArray<int>arr2(arr1);
    cout<<"arr2�Ĵ�ӡ�����"<<endl;
    printIntArray(arr2);
    arr2.Pop_Back();
    cout<<"arr2βɾ��Ĵ�СΪ��"<<arr2.getSize()<<endl;
    cout<<"arr2βɾ�������Ϊ��"<<arr2.getCapacity()<<endl;
}
//�����Զ�����������
class Person
{
public:
    Person() {};
    Person(string name, int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
void printPersonArray(MyArray<Person>&arr)
{
    for (int i = 0; i <arr.getSize() ; i++)
    {
        cout<<"������"<<arr[i].m_Name<<"���䣺"<<arr[i].m_Age<<endl;
    }
}
void test02()
{
    MyArray<Person>arr(10);
    Person p1("�����", 500);
    Person p2("��˽�", 500);
    Person p3("ɳ����", 500);
    Person p4("��  ɮ", 500);
    Person p5("������", 500);
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);
    //��ӡ����
    printPersonArray(arr);
    cout<<"arr1�Ĵ�СΪ��"<<arr.getSize()<<endl;
    cout<<"arr1������Ϊ��"<<arr.getCapacity()<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
}
