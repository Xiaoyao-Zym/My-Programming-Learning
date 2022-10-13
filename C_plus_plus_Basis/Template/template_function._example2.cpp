#include<iostream>
using namespace std;
/************************************
**ʵ��ͨ�ö������������ĺ���
**���򣺴�С����
**�㷨��ѡ������
**���ԣ�char���飬int ����
***********************************/
template<typename T>  //typename�����滻��class
void mySwap(T&a, T&b)
{
    T temp=a;
    a=b;
    b=temp;
}
//����s����
template <typename T>
void mySort(T arry[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max=i; //�϶����ֵ���±�
        for (int j = i+1; j < len;  j++)
        {
            if (arry[max] > arry[j])
            {
                max=j;  //�������ֵ�±�
            }
        }
        if (max!=i)
        {
            mySwap(arry[max], arry[i]);   //��������Ԫ��
        }
    }
}
//�ṩ��ӡ����ģ��
template<typename T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len;  i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}
//����
void test01()
{
    //����char����  
    char charArray[]="bacdfe";
    mySort(charArray, sizeof(charArray)/sizeof(char));
    cout<<"�����"<<endl;
    printArray(charArray, sizeof(charArray)/sizeof(char));
    //���� int ����
    int intArray[]={0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
     mySort(intArray, sizeof(intArray)/sizeof(int));
    cout<<"�����"<<endl;
    printArray(intArray, sizeof(intArray)/sizeof(int));
}
int main()
{
    test01();
    system("pause");
}
