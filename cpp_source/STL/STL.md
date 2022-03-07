# STL

## 1. STL�Ļ�������

* STL(Standard Templae Library)��׼ģ���
* STL�ӹ����Ϊ��**����(container)**��**�㷨(algorithm)**��**������(iterator)**
* **����**��**�㷨**֮��ͨ��**������**�����޷�����
* STL�������еĴ��붼������ģ�����ģ�庯��

## 2. STL���������

STL�����Ϊ����������������㷨�����������º�����������(�����)���ռ�������

1. �������������ݽṹ����vector��list��deque��set��set��map�ȣ������������
2. �㷨�����ֳ��õ��㷨����sort��find��copy��for_each��
3. ���������������������㷨֮��Ľ��ϼ�
4. �º�������Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ���
5. ��������һ�����������������߷º�����������ӿڵĶ���
6. �ռ�������������ռ�����������

## 3.STL���������㷨��������

STL�������ǽ�������㷺��һЩ����ʵ�ֳ���
���õ����ݽṹ�����顢��������ջ�����С����ϡ�ӳ���
��Щ������Ϊ**����ʽ����**��**����ʽ����**���֣�
**����ʽ����**��ǿ��ֵ����������ʽ������ÿ��Ԫ�ؾ��й̶���λ��
**����ʽ����**���������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ

**�㷨**�����޵Ĳ��裬����߼�����ѧ�ϵ����⣬��Ϊ�ʱ��㷨�ͷ��ʱ��㷨
�ʱ��㷨����ָ��������л���������ڵ�Ԫ�ص����ݣ����翽�����滻��ɾ����
���ʱ��㷨��ָ��������в�����������ڵ�Ԫ�����ݣ�������ҡ�������������Ѱ�Ҽ�ֵ

**������**���������㷨֮��ճ�ϼ�
�ṩһ�ַ�����ʹ֮�ܹ�����Ѱ��ĳ�������������ĸ���Ԫ�أ��������豩¶���������ڲ���ʾ��ʽ
ÿ�����������Լ�ר���ĵ�����
������ʹ�÷ǳ�����ָ��

���������ࣺ


| ����           | ����                                                       | ֧������              |
| ---------------- | ------------------------------------------------------------ | ----------------------- |
| ���������     | ������ֻ������                                             | ֻ����֧��++��==����= |
| ���������     | �����ݵ�ֻд����                                           | ֻд��֧��++          |
| ǰ�������     | ��д������������ǰ�ƽ�������                               | ��д��֧��++��==����= |
| ˫�������     | ��д������������ǰ��������                               | ��д��֧��++��==����= |
| ������ʵ����� | ��д��������������Ծ�ķ�ʽ�����������ݣ�  ������ǿ�ĵ����� | ��д��֧��++��==����= |

���õ������е���������Ϊ˫�����������������ʵ�������

## 4.�����㷨��������ʶ

STL����õ�����ΪVector���������Ϊ���飬����������в������ݣ��������������

### 4.1 Vector���������������

������  `vector`
�㷨��`for_each`
��������`vector<int> :: iterator`

����ʾ��

```C++
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//�Զ�����������
class Person
{
public:
   Person(string name, int age)
   {
       this->mName=name;
       this->mAge= age;
   }
   string  mName;
   int mAge;
};
void test01()
{
   vector<Person>v;
   Person p1("�����", 500);
   Person p2("��˽�", 500);
   Person p3("ɳ����", 500);
   Person p4("��  ɮ", 500);
   Person p5("������", 500);
   //���������������
   v.push_back(p1);
   v.push_back(p2);
   v.push_back(p3);
   v.push_back(p4);
   v.push_back(p5);
   //���������е�����
   for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<"������ "<<(*it).mName<<"  ���䣺"<<(*it).mAge<<endl;
   }
}
//����Զ������ݵ�ָ��
void test02()
{
   vector<Person*>v;
   Person p1("�����", 500);
   Person p2("��˽�", 500);
   Person p3("ɳ����", 500);
   Person p4("��  ɮ", 500);
   Person p5("������", 500);
   //���������������
   v.push_back(&p1);
   v.push_back(&p2);
   v.push_back(&p3);
   v.push_back(&p4);
   v.push_back(&p5);
    //���������е�����
   for (vector<Person*>:: iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<"������ "<<(*it)->mName<<"  ���䣺"<<(*it)->mAge<<endl;
   }
}
int main()
{
   //test01();
   test02();
   system("pause");
   return 0;   
}
```

# 5 string����

## 5.1 ��������

���ʣ�string��C++�����ַ�����������һ����**string��char**����

* char��һ��ָ��
* string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*���͵�����
  **�ص㣺**
  string���ڲ���װ�˺ܶ��Ա����
  ���磺����find������copy��ɾ��delete �滻replace������insert
  string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ�磬�����ڲ�����

## 5.2 string���캯��

���캯��ԭ�ͣ�

* char();                        //����һ���յ��ַ���������  string str
* string(const char* s);     //ʹ���ַ���s��ʼ��
* string(const string &str);   //ʹ��һ��string�����ʼ����һ��string����
* string(int n, char c);  //ʹ��n���ַ�c ��ʼ��

## 5.3string��ֵ����

��������

* ��string�ַ������и�ֵ
  ��ֵ�ĺ���ԭ�ͣ�
* string& operator=(const char* s);         //char*�����ַ�������ֵ����ǰ���ַ���
* string& operator=(const string &s);       //���ַ���s��ֵ����ǰ�ַ���
* string& operator=(char c);                      //�ַ�c��ֵ����ǰ�ַ���
* string& assign(const char *s, int n);        //���ַ���s��ǰn���ַ���ֵ����ǰ�ַ���
* string& assign(const string &s);             //���ַ�����ֵ����ǰ�ַ���
* string& aasign(int n, char c);                 //��n���ַ�c��ֵ����ǰ�ַ���

����ʾ��

```C++
#include<iostream>
#include<string>
using namespace std;
void test01()
{
   string str1;
   str1="hello world";
   cout<<"str1="<<str1<<endl;
   string str2;
   str2=str1;
   cout<<"sttr2="<<str2<<endl;
   string str3;
   str3.assign("hello C++");
   cout<<"str3="<<str3<<endl;
   string str4;
   str4.assign("hello C++",2);
   cout<<"str4="<<str4<<endl;
   string str5;
   str5.assign(str4);
   cout<<"str5="<<str5<<endl;
   string str6;
   str6.assign(10,'w');
   cout<<"str6="<<str6<<endl;
}
int main()
{
   test01();
   system("pause");
   return 0;
}
```

�ܽ᣺string��ֵ��ʽ�ܶ࣬operator-��ʽ�Ϻá�

## 5.4 string�ַ�����ƴ��

����������

* ʵ�����ַ���ĩβƴ���ַ���

����ԭ�ͣ�

* string& operator+= (const char* str);        //����+=������
* string& operator+= (const char c);           //����+=������
* string& operator+= (const string& str);     //����+=������
* string& append (const char *s);                 //���ַ���s���ӵ���ǰ�ַ�����β
* string& append (const char *s, int n);         //���ַ���s��ǰn���ַ������ӵ���ǰ�ַ�����β
* string& append (const string &s);              //ͬoperator+=(const string& str)
* string& append(const string &s, int pos, int n);   //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

����ʾ��

```C++
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
```

## 5.5 string���Һ��滻

����������

* ���ң�����ָ���ַ����Ƿ����
* �滻����ָ����λ���滻�ַ���

����ԭ�ͣ�

* int find (const string& str, int pos=0) const;     //����str��һ�γ���λ�ô�pos��ʼ����
* int find (const char* s, int pos=0) const;     //����s��һ�γ���λ�ô�pos��ʼ����
* int find (const char* s, int pos, int n) const;   //��posλ�ò���s��ǰn���ַ���һ��λ��
* int find (const char c��int pos=0)const;     //�����ַ�c��һ�γ���λ��
* int rfind(const string& str, int pos=nops)const;  //����str���һ��λ�ã���pos��ʼ����
* int rfind (const char* s, int pos=npos)const;       //�鿴s���һ�γ���λ�ã���pos��ʼ����
* int rfind(const char *s, int pos, int n) const;   //��pos����s��ǰn���ַ����һ��λ��
* int rfind(const char c, int pos=0) const;    //�����ַ�c���һ�γ���λ��
* string& replace(int pos, int n, const string& str);  //�滻��pos��ʼn���ַ���str
* string& repalce(int pos, int n, const char* s);   //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

����ʾ��

```C++
#include<string>
#include<iostream>
using namespace std;
//����
void test01()
{
   string str1="abcdefg";
   //find���Ҵ������ң�
   int pos =str1.find("cd");
   if (pos==-1)
   {
       cout<<"δ�ҵ��ַ���";
   }
   else
   {
       cout<<"�ҵ��Ӵ�λ�ã�"<<pos<<endl;
   }
   //rfind����������
   pos=str1.rfind("cd");
   cout<<"pos="<<pos<<endl; 
}
//�滻
void test02()
{
   string str2="abcdefd";
   str2.replace(2, 2,"12345");
   cout<<"str2="<<str2<<endl;
}
int main()
{
   test01();
   test02();
   system("pause");
   return 0;
}
```

## 5.6 string�ַ����Ƚ�

����������

* �ַ���֮��ıȽ�

�ȽϷ�ʽ��

* �ַ����Ƚ��ǰ����ַ�ASCII����бȽ�

���ڣ�����    0;���ڣ�����    1;С�ڣ�����   -1;����ԭ�ͣ�

* int compare(const string&s) const;    //���ַ���s�Ƚ�
* int compare(const char *s)const;        //���ַ���s�Ƚ�

����ʾ��

```C++
#include<iostream>
#include<string>
using namespace std;
void test01()
{
   string str1="hello";
   string str2="hello";
   if(str1.compare(str2)==0)
   {
       cout<<"str1����str2"<<endl;
   }
   else if (str1.compare(str2)>0)
   {
       cout<<"str1����str2"<<endl;
   }
   else
   {
       cout<<"str1С��str2"<<endl;
   }
}
int main()
{
   test01();
   system("pause");
   return 0;
}
```

## 5.7 string�ַ���ȡ

string�е����ַ���ȡ��ʽ������

* char& operator[](int n);      //ͨ��[]��ʽȡ�ַ�
* char& at(int n);                   //ͨ��at������ȡ�ַ�

����ʾ��

```C++
#include<iostream>
#include<string>
using namespace std;
//string �ַ���ȡ
void test01()
{
  //ͨ��[]��ʽȡ�ַ�
  string str1="hello";
  for (int i = 0; i < str1.size(); i++)
  {
      cout<<str1[i]<<" ";
  }
  cout<<endl;
  //ͨ��at������ȡ�ַ�
  for (int i = 0; i < str1.size(); i++)
  {
      cout<<str1.at(i)<<" ";
  }
  cout<<endl;
  //�޸ĵ����ַ�
  str1[0]='x';
  str1.at(1)='x';
  cout<<"str1="<<str1<<endl;
}
int main()
{
   test01();
   system("pause");
   return 0;
}
```

## 5.8 string�ַ��������ɾ��

����������

* ��string�ַ������в����ɾ���ַ�����

����ԭ�ͣ�

* string& insert(int pos, const char* s);   //�����ַ���
* string& insert(int pos, const string& str);  //�����ַ���
* string& insert(int pos, int n, cha c);       //��ָ��λ�ò���n���ַ�c
* string& erase(int pos, int n=nops);       //ɾ����Pos��ʼ��n���ַ�

����ʾ��

```C++
#include<iostream>
#include<string>
using namespace std;
//string �ַ�
void test01()
{
  //ͨ��[]��ʽȡ�ַ�
  string str1="hello";
  str1.insert(2,"xxx");
  cout<<"str1="<<str1<<endl;
  //ɾ��
  str1.erase(2, 3);
  cout<<"str1="<<str1<<endl;
}
int main()
{
   test01();
   system("pause");
   return 0;
}
```

## 5.9 string�Ӵ�

�������������ַ�����ѡȡ����Ҫ���Ӵ�

* string substr (int pos=0, int  n=npos)   //������pos��ɵ�n���ַ���ɵ��ַ�����

����ʾ��

```C++
#include<iostream>
#include<string>
using namespace std;
//string ���Ӵ�
void test01()
{
   string str="abcdef";
   string subStr=str.substr(1, 2);
   cout<<"subStr="<<subStr<<endl;
}
void test02()
{
    string email="zym@qq.com";
    //��ȡ�û���
    int pos= email.find("@");
    string userName=email.substr(0, pos);
    cout<<"userName="<<userName<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
```

# 6 vector����

## 6.1 vector ��������

���ܣ�

* vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������

vector����ͨ����������

* ��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ

��̬��չ��

* ��������ԭ�ռ�֮�����ӿռ䣬�����Ҹ��õ��ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ䡣
* vector����������֧��������ʵĵ�����

## 6.2 vector���캯��

����������

* ����vector����

�������ͣ�

* vector<T>v;                            //ʵ��ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
* vector (v.begin(), v.end());       //��[beg, end]�����е�Ԫ�ؿ���������
* vector (n, elem);                     //���캯����n��elem����������
* vector (const vector &vec);    //�������캯��

����ʾ��

```C++
#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//����vector��������
void test()
{
   vector<int>v1;                 //Ĭ�Ϲ���
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   printVector(v1);
   //ͨ�����䷽ʽ����
   vector<int>v2(v1.begin(), v1.end());
    printVector(v2);
    //ͨ��n��elem��ʽ����
    vector<int>v3(10, 100);
    printVector(v3);
    //��������
    vector<int>v4(v3);
    printVector(v4);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

## 6.3 vector������ֵ

����������

* ��vector�������и�ֵ

����ԭ�ͣ�

* vector& operator=(const vector &vec);  //���صȺŲ�����
* assign(beg, end);         //��(beg, end)�����е����ݿ�������ֵ����
* assign(n, elem);           //��n��elem������ֵ������

����ʾ����

```C++
#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//vector����f��ֵ
void test()
{
   vector<int>v1;                 //Ĭ�Ϲ���
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   printVector(v1);
   //operator=��ֵ
   vector<int>v2=v1;
    printVector(v2);
    //ͨ��assign��ʽ��ֵ
    vector<int>v3;
    v3.assign(v2.begin(), v2.end());       //Ϊ����ҿ�����
    printVector(v3);
    //��������
    vector<int>v4;
    v4.assign(10, 9);;
    printVector(v4);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

## 6.4 vector�����ʹ�С

����������

* ��vector�����������ʹ�С����

����ԭ�ͣ�

* empty();                                  //�ж������Ƿ�Ϊ��
* capacity();                                //����������
* size();                         //����������Ԫ�صĸ���
* resize(int num);                //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã����������̣���ĩβ��������������Ԫ��ɾ��
* resize(int num, elem);       //����ָ�������ĳ���Ϊnum���������䳤������elem�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ػᱻɾ��

����ʾ��

```C++
#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//vector����f�����ʹ�С
void test()
{
   vector<int>v1;                 //Ĭ�Ϲ���
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   //�ж������Ƿ�Ϊ��
   if (v1.empty())
   {
       cout<<"v1����Ϊ��"<<endl;
   }
   else
   {
       cout<<"v1��Ϊ��"
              <<"v1������Ϊ��"<<v1.capacity()
              <<"  v1�Ĵ�СΪ"<<v1.size()<<endl;
   }
   v1.resize(18, 10);  //�������ָ��������Ĭ����0��䣬Ҳ��ָ���滻����
   v1.resize(9);       //�������ָ�����̣���ɾ����������
   printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

## 6.5 vector�����Ĳ�����ɾ��

����������

* ��vector�������в��롢ɾ������

����ԭ�ͣ�

* push_back(else);       //β������Ԫ��ele
* pop_back();              //ɾ�����һ��Ԫ��
* insert(const_itrerator pos, ele);     //������ָ��λ��pos����Ԫ��ele
* insert(const_iterator pos, int count,ele);    //������ָ��λ��pos����count��Ԫ��ele
* errase(const_iterator pos);      //ɾ����������Ԫ��
* erase(const_iterrator start, const_iterator end);     //ɾ����������start��end֮���Ԫ��
* clear();
  ����ʾ����

```C++
#include<iostream>
#include<vector>
using namespace std;
//vector �����Ĳ�����ɾ��
/*
*push_back(else);                           //β������Ԫ��ele
*pop_back();                                  //ɾ�����һ��Ԫ��
*insert(const_itrerator pos, ele);   //������ָ��λ��pos����Ԫ��ele
*insert(const_iterator pos, int count,ele); //������ָ��λ��pos����count��Ԫ��ele
*errase(const_iterator pos);        //ɾ����������Ԫ��
*erase(const_iterrator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
*clear();
*/
void printVector(vector<int>&v)
{
    for (vector<int>:: iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v1;
    //β�巨��ʼ������
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //βɾ��
    v1.pop_back();
    printVector(v1);
    //β����  ��һ�������ǵ�����
    v1.insert(v1.begin(), 2, 100);
    printVector(v1);
    //ɾ��   ����Ҳ�ǵ�����
    v1.erase(v1.begin());
    printVector(v1);
    //�������
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

�ܽ�

* β��--push_back
* βɾ--pop_back
* ����--insert(λ�õ�����)
* ɾ��--erase(λ�õ�����)
* ���--clear

## 6.6 vector���ݴ�ȡ

### ��������

* ��vector�е����ݵĴ�ȡ����

### ����ԭ�ͣ�

* at(int idx);          //��������idx��ָ������
* operator[];         //��������idx��ָ������
* front();               //���������е�һ������Ԫ��
* back();                //�������������һ������Ԫ��

### ����ʾ����

```C++
#include<iostream>
#include<vector>
using namespace std;
//vector�������ݴ�ȡ
void printVector(vector<int>v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);
    //����[]��ʽ��������Ԫ��
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //����at��ʽ����Ԫ��
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    //���ʵ�һ��Ԫ��
    cout<<"��һ��Ԫ��Ϊ��"<<v.front()<<endl;
    //��ȡ���һ��Ԫ��
    cout<<"���һ��Ԫ��Ϊ��"<<v.front()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

## 6.7 vector��������

### ����������

* ʵ������������Ԫ�ؽ��л���

### ����ԭ�ͣ�

* swap(vec);   //��vec�뱾���Ԫ�ػ���

### ����ʾ��

```C++
#include<vector>
#include<iostream>
using namespace std;
//��������
void printVector(vector<int>v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//1.����ʹ��
void test01()
{
    cout<<"����ǰ��"<<endl;
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int>v2;
    for (int i = 10; i >0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    cout<<"������"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2.ʵ����;
//����swap���������ڴ�ռ�
void test02()
{
    vector<int>v3;
    for (int i = 0; i < 10000; i++)
    {
        v3.push_back(i);
    }
    cout<<"v3������Ϊ��"<<v3.capacity()<<endl;
    cout<<"v3�Ĵ�СΪ��"<<v3.size()<<endl;
    //����ָ����С
    v3.resize(3);
    cout<<"v3������Ϊ��"<<v3.capacity()<<endl;
    cout<<"v3�Ĵ�СΪ��"<<v3.size()<<endl;
    //����swap�����ڴ�
    vector<int>(v3).swap(v3);
    cout<<"v3������Ϊ��"<<v3.capacity()<<endl;
    cout<<"v3�Ĵ�СΪ��"<<v3.size()<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
```

## 6.8 vectorԤ���ռ�

### ����������

* ����vector�ڶ�̬��չ����ʱ����չ����

### ����ԭ�ͣ�

* reserve(int len);      //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���

### ����ʾ����

```C++
#include<iostream>
#include<vector>
using namespace std;

void test01()
{
    vector<int> v;
    //Ԥ���ռ�
    v.reserve(10000);
    int num=0;    //ͳ�ƿռ俪�ٴ���
    int *p=NULL;
    for (int i = 0; i < 10000; i++)
    {
       v.push_back(i);
       if(p!=&v[0])
       {
           p=&v[0];
           num++;
       }
    }
   cout<<"num="<<num<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

# 7 deque����

### ��������

���ܣ�

* ˫�����飬���Զ�ͷ�˽���ɾ������

**deque**��**vector**����

* vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
* deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻ��vector��
* vector����Ԫ��ʱ���ٶȻ��deque�죬��������ڲ�ʵ���й�

deque �ڲ�����ԭ��deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ�����п���ά������ÿ���������ĵ�ַ��ʹ��ʹ�õ�dequeʱ��һƬ�������ڴ�ռ�

* deque�����ĵ�����Ҳ��֧���������

## 7.1 deque���캯��

### ����������

* deque��������

### ����ԭ�ͣ�

* deque<T>deqT;                    //ʵ��ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
* deque(beg, end());                //��[beg, end]�����е�Ԫ�ؿ���������
* deque(n, elem);                     //���캯����n��elem����������
* deque(const deque &vec);     //�������캯��

### ����ʾ����

```C++
#include<iostream>
#include<deque>
using namespace std;
void printDeque(const deque<int>d)    //�޶�����Ϊֻ��״̬
{
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//deque ���캯��
void test()
{
    deque<int>d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1.begin(), d1.end());
    printDeque(d1);
    deque<int>d3(10,10);
    printDeque(d3);
    deque<int>d4(d3);
    printDeque(d4);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

## 7.2 deque��ֵ����

### ����������

* ��deque�������и�ֵ

### ����ԭ�ͣ�

* deque& operator=(const deque &deq);      //���صȺŲ���
* assign(beg, end);                                          //��[beg,end]�����е����ݿ�����ֵ������
* assign(n, elem)                                           //��n��elem������ֵ������

### ����ʾ����

```C++
void test01()
{
    deque<int>d1;
    for (int i = 0; i <10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    //operator=��ֵ
    deque<int>d2;
    d2=d1;
    printDeque(d2);
    //assign��ֵ
    deque<int>d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);
    deque<int>d4;
    d4.assign(10, 9);
    printDeque(d4);
}
```

## 7.3 deque��С����

### ����������

* ��deque�����Ĵ�С���в���

### ����ԭ�ͣ�

* deque.empty();            //�ж������Ƿ�Ϊ��
* deque.size();                //����������Ԫ�صĸ���
* deque.resize(num);     //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã�                    //���������̣���ĩβ�������ȵ�Ԫ�ر�ɾ��
* deque.resize(num, elem);    //����ָ�������ĳ���Ϊnum���������䳤������elem�����λ�ã����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

### ����ʾ����

```C++
//deque������С
void test01()
{
    deque<int>d1;
    for (int i = 0; i <10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    if (d1.empty())
    {
        cout<<"d1Ϊ��"<<endl;
    }
    else
    {
         cout<<"d1��Ϊ��"
              <<"  d1�Ĵ�СΪ"<<d1.size()<<endl;
              //dequeû����������
    }
    //����ָ����С
    d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);
    d1.resize(5);
    printDeque(d1);
}
```

### �ܽ᣺

* dequeû����������
* �ж��Ƿ�Ϊ��----empty
* ����Ԫ�ظ���----size
* �����ƶ�����----resize

## 7.4 deque�����ɾ��

### ����������

* ��deque�����в����ɾ������

### ����ԭ�ͣ�

#### ���˲��������

* push_back(elem);       //������β�����һ������
* push_front(elem);       //������ͷ������һ������
* pop_back();                 //ɾ���������һ������
* pop_front();                 //ɾ��������һ������

#### ָ��λ�ò�����

* insert(pos, elem);         //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
* insert(pos, n, elem);      //��posλ�ò���n��elem���ݣ��޷���ֵ��
* insert(pos, beg, end);    //��posλ�ò���[beg, end]��������ݣ��޷���ֵ��
* insert(pos, beg, end);    //��posλ�ò���[beg, end]��������ݣ��޷���ֵ
* clear();                           //�������������λ��
* erase(beg, end);            //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
* erase(pos);                    //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��

### ����ʾ����

```C++
void test01()
{
    deque<int>d1;
    //β��
    d1.push_back(10);
    d1.push_back(20);
    //ͷ��
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    //βɾ
    d1.pop_front();
    printDeque(d1);
}
void test02()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    //insert����
    d1.insert(d1.begin(),1000);
    //1000  200 100  10  20
    printDeque(d1);
    d1.insert(d1.begin(), 2, 1000);
    //1000  10000  1000  200  100  10  20
    printDeque(d1);
    //����������в���
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    //1, 2, 3, 10000,  10000, 1000, 200,  100, 10, 20
    printDeque(d1);
}
void test03()
{
     deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    //ɾ��
    deque<int>::iterator it=d1.begin();
    it++;
    d1.erase(it);
    //200 10 20
    printDeque(d1);
    //�������䷽ʽɾ��
    d1.erase(d1.begin(), d1.end());
    printDeque(d1);
    //���
    d1.clear();
    printDeque(d1);
}
```

�ܽ᣺

* �����ɾ���ṩ��λ���ǵ�������
* β��   ---push_back
* βɾ   ---pop_back
* ͷ��   ---push_front
* ͷɾ   ---pop_front

## 7.5 deque ���ݴ�ȡ

### ����������

* ��deque�е����ݵĴ�ȡ����

### ����ԭ�ͣ�

* at(int idx);       //��������idx��ָ������
* operator[];      //��������idx��ָ������
* front();            //���������е�һ������Ԫ��
* back();            //�������������һ������Ԫ��

### ����ʾ����

```C++
//deque�������ݴ�ȡ
void test01()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //ͨ��[]��ʽ����Ԫ��
    //300  200  100  10  20 30
    for (int i = 0; i < d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    //ͨ��at��ʽ����Ԫ��
    for (int i = 0; i < d.size(); i++)
    {
        cout<<d.at(i)<<" ";
    }
    cout<<"��һ��Ԫ��Ϊ��"<<d.front()<<endl;
    cout<<"���һ��Ԫ�أ�"<<d.back()<<endl;
}
```

### �ܽ᣺

* �����õ�������ȡdeque������Ԫ�أ�[]��atҲ����
* front����������һ��Ԫ��
* back�����������һ��Ԫ��

## 7.6 deque����

### ����������

* �����㷨ʵ�ֶ�deque������������

### �㷨��

* sort(iterator beg, iterator end)    //��beg��end������Ԫ�ؽ�������

### ����ʾ����

```C++
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//deque����
void printDeque(const deque<int>d)    //�޶�����Ϊֻ��״̬
{
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    deque<int>d;
    for (int i = 10; i > 0; i--)
    {
        d.push_back(i);
    }
    cout<<"����ǰ"<<endl;;
    printDeque(d);
    //����Ĭ���������
    //����֧��������ʵĵ�����������������������sort�㷨
    sort(d.begin(), d.end());
    cout<<"�����"<<endl;
    printDeque(d);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

## 7.7 ����-��ί���

### 1. ��������

* ��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ����

2. ʵ�ֲ���

* ��������ѡ�֣��ŵ�vector��
* ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque����
* sort�㷨��deque�����з�������ȥ����߷ֺ���ͷ�
* deque��������һ�飬�ۼ��ܷ�
* ��ȡƽ����

### ʾ�����룺

```C++
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//ѡ����
class Person
{
public:
   Person(string name, int score) 
   {
       m_Name=name;
       m_Score=score;
   }
   string m_Name;
   int m_Score;
};
void creatPerson(vector<Person>&v)
{
    string nameSeed="ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name="ѡ�֣�";
        name+=nameSeed[i];
        int score=0;
        //��������person���󣬷��뵽������
        Person p(name, score);
        v.push_back(p);
    }
}
//���
void setScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        //����ί�Ĵ�ַ���deque������
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score=rand()%41+60; //60~100
            d.push_back(score);
        }
        // cout<<it->m_Name<<"��֣�"<<endl;
        // for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        // {
        //     cout<<*dit<<" ";   
        // }
        // cout<<endl;
        //����
        sort(d.begin(), d.end());
        //ȥ����߷ֺ���ͷ�
        d.pop_back();
        d.pop_front();
        //ȡƽ����
        int sum=0;
        for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        {
            sum+=*dit;   //�ۼ�ÿ������
        }
        int avg=sum/d.size();
        //��ƽ���� ��ֵ��ѡ������
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        cout<<it->m_Name<<"   ƽ���÷֣�"<<it->m_Score<<endl;
    }
}
int main()
{
    //1. ����5��ѡ��
    vector<Person>v;  //���ѡ�ֵ�����
    creatPerson(v);
    // for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"������"<<(*it).m_Name;
    //     cout<<"������"<<(*it).m_Score<<endl;
    // }  
    //ѡ�ִ��
    setScore(v);  
    //�������
    showScore(v);
    system("pause");
    return 0;
}
```

# 8  stack����

### ��������

* stack��һ���Ƚ����(First In Last Out��FILO)�����ݽṹ����ֻ��һ������
* ջ��ֻ�ж��˵�Ԫ�زſ��Ա����ʹ�ã����ջ�������б�����Ϊ
* ջ�����ж��Ƿ�Ϊ�գ�empty()
* ջ���Է���Ԫ�ظ�����size()
* ��ջ��push()����ջ��pop()

### ���ýӿ�

����������ջ�������õĶ���ӿڹ��캯����

* stack<T>stk;      //stack����ģ��ʵ�֣�stack�����Ĭ�Ϲ�����ʽ
* stack(const stack &stk);   //�������캯��

��ֵ������

* stack& operator=(const stack &stk);     //���صȺŲ�����

���ݴ�ţ�

* push(elem);       //��ջ�����Ԫ��
* pop();                //��ջ���Ƴ���һ��Ԫ��
* top();                 //����ջ��Ԫ��

��С����

* empty();            //�ж϶�ջ�Ƿ�Ϊ��
* size();                //����ջ�Ĵ�С

### ����ʾ��

```C++
#include<iostream>
#include<stack>
using namespace std;
//ջstack����
void test()
{
    stack<int>s;
    //��ջ
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    //ֻҪջ��Ϊ�գ��鿴ջ��������ִ��ջ����
    while (!s.empty())
    {
        //�鿴ջ��Ԫ��
        cout<<"ջ��Ԫ��Ϊ��"<<s.top()<<endl;
        //��ջ
        s.pop();
    }
    cout<<"ջ�Ĵ�С��"<<s.size()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

# 9 queue����

### ��������

* Queue��һ���Ƚ��ȳ�(First In First Out��FIFO)�����ݽṹ��������������
* ��ͷ��front()����β��back()����ӣ�push()�����ӣ�pop()
* ֻ�����˿��Ա����ʣ��������б�����Ϊ

### ���ýӿ�

����������ջ�������õĶ���ӿڹ��캯����

* queue<T>que;      //queue����ģ��ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
* queue(const queue &stk);   //�������캯��

��ֵ������

* queue& operator=(const stack &stk);     //���صȺŲ�����

���ݴ�ţ�

* push(elem);       //���β���Ԫ��
* pop();                //�Ӷ�ͷ�Ƴ���һ��Ԫ��
* back();               //�������һ��Ԫ��
* front();               //���ص�һ��Ԫ��

��С����

* empty();            //�ж϶�ջ�Ƿ�Ϊ��
* size();                //����ջ�Ĵ�С

### ����ʾ��

```C++
#include<iostream>
#include<queue>
using namespace std;
//����queue����
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
};
void test()
{
    //��������
    queue<Person>q;
    //��ջ
    Person p1("������", 100);
    Person p2("�����", 500);
    Person p3("��˽�", 400);
    Person p4("ɳ����", 300);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"���еĴ�С��"<<q.size()<<endl;
    //ֻҪ���в�Ϊ�գ��鿴��ͷ�Ͷ�β������ִ�г��Ӳ���
    while (!q.empty())
    {
        //�鿴��ͷԪ��
        cout<<"��ͷԪ��Ϊ--������"<<q.front().m_Name
               <<"--���䣺"<<q.front().m_Age<<endl
               <<"��βԪ��Ϊ--������"<<q.back().m_Name
               <<"--���䣺"<<q.back().m_Age<<endl;
        //����
        q.pop();
    }
    cout<<"���еĴ�С��"<<q.size()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

# 10 list����

### ��������

* ���ܣ������ݽ�����ʽ�洢
* ����(list)��һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
* �������ɣ�������һϵ�н�����
* ������ɣ�һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
* STL�е�������һ��˫��ѭ������
* �ŵ㣺���Զ������λ�ý��п��ٲ����ɾ��Ԫ��
* ȱ�㣺�����ı����ٶȲ������飬ռ�ÿռ�������
* ��������Ĵ洢��ʽ�����������ڴ棬����˫�������

### list���ŵ�

* ���ö�̬�洢���䣬��������ڴ��˷Ѻ����
* ����ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��

### list��ȱ��

* ���������ǿռ�(ָ����)��ʱ��(����)����ķѽϴ�
  list��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ�������

### �ܽ�

STL��list��vector���������ʹ�õ�������������ȱ��

## 10.1 list���캯��

### ��������

* ����list����

### ����ԭ��

* list<T>lst;                   //list����ģ����ʵ�֣������Ĭ�Ϲ�����ʽ
* list(beg, end);             //���캯����[beg, end]�����е�Ԫ�ؿ���������
* list(n, elem);               //���캯����n��elem����������
* list(const list &lst);    //�������캯��

### ����ʾ��

```C++
//list�������캯��
void printList(const list<int>&L)
{
   for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
void test()
{
   //����list������Ĭ�Ϲ���
   list<int>L1;
   //�������
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   //��������
   printList(L1);
   //���䷽ʽ����
   list<int>L2(L1.begin(), L1.end());
   printList(L2);
   //��������
   list<int>L3(L2);
   printList(L3);
   //n��elem
   list<int>L4(10, 1000);
   printList(L4);
}
```

# 10.2 list ������ֵ�ͽ���

###����������

* ��list�������и�ֵ���Լ�����list����

### ����ԭ��

* assign(beg, end);                               //��[beg, end]�����е����ݿ�����ֵ������
* assign(n, elem);                                 //��n��elem������ֵ������
* list&  operator=(const list &lst);      //���صȺŲ�����
* swap(lst);                                          //��lst�뱾���Ԫ�ػ���

### ����ʾ��

```C++
   

void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list������ֵ�ͽ���
void assignment()
{
    list<int>L1;
    //�������
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   printList(L1);
   list<int>L2;
   L2=L1;
   printList(L2);
   list<int>L3;
   L3.assign(L2.begin(), L2.end());
   printList(L3);
   list<int>L4;
   L4.assign(10, 100);
   printList(L4);
}
//����
void exchange()
{
   list<int>L1;
    //�������
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   list<int>L2;
   L2.assign(10,100);
   printList(L1);
   printList(L2);
   cout<<"������"<<endl;
   L1.swap(L2);
   printList(L1);
   printList(L2);
}
```
## 10.3 List��С����  
### ��������
* ��list�����Ĵ�С���в���  

### ����ԭ��  
* size();                            //����������Ԫ�صĸ���
* empty();                        //�ж������Ƿ�Ϊ��
* resize(num);                 //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
* resize(num, elem);       //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�ã����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

### ����ʾ��
```C++
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list������С����
void size()
{
    list<int>L1;
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   printList(L1);
   //�ж������Ƿ�Ϊ��
   if (L1.empty())
   {
       cout<<"L1Ϊ��"<<endl;
   }
   else
   {
       cout<<"L1��Ϊ��"<<endl;
       cout<<"L1�Ĵ�С��"<<L1.size()<<endl;
   }
   //����ָ����С
   L1.resize(10, 1000);
   printList(L1);
}
```  
# 10.4 List�����ɾ��  
### ��������
* ��list�����������ݵĲ����ɾ��
### ����ԭ��  
* push_back(elem);                  //������β������һ��Ԫ��
* pop_back();                          //ɾ�����������һ��Ԫ��
* push_front(elem);                //��������ͷ����һ��Ԫ��
* pop_front();                         //��������ͷ�Ƴ���һ��Ԫ��
*  insert(pos, elem);               //��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
*  insert(pos, n, elem);           //��posλ�ò���n��elem���ݣ��޷���ֵ
*  insert(pos, beg, end);        //��posλ�ò���[beg, end]��������ݣ��޷���ֵ
*  clear();                               //�Ƴ���������������
*  erase(beg, end);                //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
*  erase(pos);                        //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
*  remove(elem);                 //ɾ��������������elemֵƥ���Ԫ��
