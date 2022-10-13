# STL

## 1. STL�Ļ�������

* STL(Standard Templae Library)��׼ģ���
* STL�ӹ����Ϊ��**����(container)**��**�㷨(algorithm)**��**������(iterator)**
* **����**��**�㷨**֮��ͨ��**������**�����޷�����
* STL�������еĴ��붼������ģ�����ģ�庯��

### 1.2 STL���������

STL�����Ϊ����������������㷨�����������º�����������(�����)���ռ�������

1. �������������ݽṹ����vector��list��deque��set��set��map�ȣ������������
2. �㷨�����ֳ��õ��㷨����sort��find��copy��for_each��
3. ���������������������㷨֮��Ľ��ϼ�
4. �º�������Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ���
5. ��������һ�����������������߷º�����������ӿڵĶ���
6. �ռ�������������ռ�����������

### 1.3 STL���������㷨��������

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

### 1.4 �����㷨��������ʶ

STL����õ�����ΪVector���������Ϊ���飬����������в������ݣ��������������

####  Vector���������������

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

## 2 STL��������
### 2.1 string����

#### ��������

���ʣ�string��C++�����ַ�����������һ����**string��char**����

* char��һ��ָ��
* string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*���͵�����
  **�ص㣺**
  string���ڲ���װ�˺ܶ��Ա����
  ���磺����find������copy��ɾ��delete �滻replace������insert
  string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ�磬�����ڲ�����

#### string���캯��

���캯��ԭ�ͣ�

* char();                        //����һ���յ��ַ���������  string str
* string(const char* s);     //ʹ���ַ���s��ʼ��
* string(const string &str);   //ʹ��һ��string�����ʼ����һ��string����
* string(int n, char c);  //ʹ��n���ַ�c ��ʼ��

#### string��ֵ����

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

#### string�ַ�����ƴ��

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

#### string���Һ��滻

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

#### string�ַ����Ƚ�

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

#### string�ַ���ȡ

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

#### string�ַ��������ɾ��

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

#### string�Ӵ�

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

### 2.2vector����

#### vector ��������

���ܣ�

* vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������

vector����ͨ����������

* ��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ

��̬��չ��

* ��������ԭ�ռ�֮�����ӿռ䣬�����Ҹ��õ��ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ䡣
* vector����������֧��������ʵĵ�����

#### vector���캯��

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

#### vector������ֵ

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

#### vector�����ʹ�С

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

#### vector�����Ĳ�����ɾ��
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

#### vector���ݴ�ȡ
��������
* ��vector�е����ݵĴ�ȡ����  

����ԭ�ͣ�
* at(int idx);          //��������idx��ָ������
* operator[];         //��������idx��ָ������
* front();               //���������е�һ������Ԫ��
* back();                //�������������һ������Ԫ��

����ʾ����
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

#### vector��������

����������

* ʵ������������Ԫ�ؽ��л���

����ԭ�ͣ�

* swap(vec);   //��vec�뱾���Ԫ�ػ���

����ʾ��

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

#### vectorԤ���ռ�

����������

* ����vector�ڶ�̬��չ����ʱ����չ����

����ԭ�ͣ�

* reserve(int len);      //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���

����ʾ����
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

### 2.3 deque����

#### ��������

���ܣ�

* ˫�����飬���Զ�ͷ�˽���ɾ������

**deque**��**vector**����

* vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
* deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻ��vector��
* vector����Ԫ��ʱ���ٶȻ��deque�죬��������ڲ�ʵ���й�

deque �ڲ�����ԭ��deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ�����п���ά������ÿ���������ĵ�ַ��ʹ��ʹ�õ�dequeʱ��һƬ�������ڴ�ռ�

* deque�����ĵ�����Ҳ��֧���������

####  deque���캯��

����������

* deque��������

����ԭ�ͣ�

* deque<T>deqT;                    //ʵ��ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
* deque(beg, end());                //��[beg, end]�����е�Ԫ�ؿ���������
* deque(n, elem);                     //���캯����n��elem����������
* deque(const deque &vec);     //�������캯��

����ʾ����

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

#### deque��ֵ����

����������

* ��deque�������и�ֵ

����ԭ�ͣ�

* deque& operator=(const deque &deq);      //���صȺŲ���
* assign(beg, end);                                          //��[beg,end]�����е����ݿ�����ֵ������
* assign(n, elem)                                           //��n��elem������ֵ������

����ʾ����

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

#### deque��С����

����������

* ��deque�����Ĵ�С���в���

����ԭ�ͣ�

* deque.empty();            //�ж������Ƿ�Ϊ��
* deque.size();                //����������Ԫ�صĸ���
* deque.resize(num);     //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã�                    //���������̣���ĩβ�������ȵ�Ԫ�ر�ɾ��
* deque.resize(num, elem);    //����ָ�������ĳ���Ϊnum���������䳤������elem�����λ�ã����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

����ʾ����

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

�ܽ᣺

* dequeû����������
* �ж��Ƿ�Ϊ��----empty
* ����Ԫ�ظ���----size
* �����ƶ�����----resize

#### deque�����ɾ��

����������

* ��deque�����в����ɾ������

����ԭ�ͣ�

���˲��������

* push_back(elem);       //������β�����һ������
* push_front(elem);       //������ͷ������һ������
* pop_back();                 //ɾ���������һ������
* pop_front();                 //ɾ��������һ������

ָ��λ�ò�����

* insert(pos, elem);         //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
* insert(pos, n, elem);      //��posλ�ò���n��elem���ݣ��޷���ֵ��
* insert(pos, beg, end);    //��posλ�ò���[beg, end]��������ݣ��޷���ֵ��
* insert(pos, beg, end);    //��posλ�ò���[beg, end]��������ݣ��޷���ֵ
* clear();                           //�������������λ��
* erase(beg, end);            //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
* erase(pos);                    //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��

����ʾ����

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

#### deque ���ݴ�ȡ

����������

* ��deque�е����ݵĴ�ȡ����

 ����ԭ�ͣ�

* at(int idx);       //��������idx��ָ������
* operator[];      //��������idx��ָ������
* front();            //���������е�һ������Ԫ��
* back();            //�������������һ������Ԫ��

����ʾ����

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

�ܽ᣺

* �����õ�������ȡdeque������Ԫ�أ�[]��atҲ����
* front����������һ��Ԫ��
* back�����������һ��Ԫ��

#### deque����

����������

* �����㷨ʵ�ֶ�deque������������

�㷨��

* sort(iterator beg, iterator end)    //��beg��end������Ԫ�ؽ�������

����ʾ����

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

#### ����-��ί���
 ��������

* ��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ����

ʵ�ֲ���

* ��������ѡ�֣��ŵ�vector��
* ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque����
* sort�㷨��deque�����з�������ȥ����߷ֺ���ͷ�
* deque��������һ�飬�ۼ��ܷ�
* ��ȡƽ����

ʾ�����룺

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

###2.4 stack����

��������

* stack��һ���Ƚ����(First In Last Out��FILO)�����ݽṹ����ֻ��һ������
* ջ��ֻ�ж��˵�Ԫ�زſ��Ա����ʹ�ã����ջ�������б�����Ϊ
* ջ�����ж��Ƿ�Ϊ�գ�empty()
* ջ���Է���Ԫ�ظ�����size()
* ��ջ��push()����ջ��pop()

���ýӿ�

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

����ʾ��

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

### 2.5 queue����

��������

* Queue��һ���Ƚ��ȳ�(First In First Out��FIFO)�����ݽṹ��������������
* ��ͷ��front()����β��back()����ӣ�push()�����ӣ�pop()
* ֻ�����˿��Ա����ʣ��������б�����Ϊ

���ýӿ�

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

����ʾ��

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

### 2.6 list����

��������

* ���ܣ������ݽ�����ʽ�洢
* ����(list)��һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
* �������ɣ�������һϵ�н�����
* ������ɣ�һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ������ַ��ָ����
* STL�е�������һ��˫��ѭ������
* �ŵ㣺���Զ������λ�ý��п��ٲ����ɾ��Ԫ��
* ȱ�㣺�����ı����ٶȲ������飬ռ�ÿռ�������
* ��������Ĵ洢��ʽ�����������ڴ棬����˫�������

list���ŵ�

* ���ö�̬�洢���䣬��������ڴ��˷Ѻ����
* ����ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��

list��ȱ��

* ���������ǿռ�(ָ����)��ʱ��(����)����ķѽϴ�
  list��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ�������

�ܽ�

STL��list��vector���������ʹ�õ�������������ȱ��

#### list���캯��

��������

* ����list����

����ԭ��

* list<T>lst;                   //list����ģ����ʵ�֣������Ĭ�Ϲ�����ʽ
* list(beg, end);             //���캯����[beg, end]�����е�Ԫ�ؿ���������
* list(n, elem);               //���캯����n��elem����������
* list(const list &lst);    //�������캯��

����ʾ��

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

#### list ������ֵ�ͽ���

###����������

* ��list�������и�ֵ���Լ�����list����

����ԭ��

* assign(beg, end);                               //��[beg, end]�����е����ݿ�����ֵ������
* assign(n, elem);                                 //��n��elem������ֵ������
* list&  operator=(const list &lst);      //���صȺŲ�����
* swap(lst);                                          //��lst�뱾���Ԫ�ػ���

����ʾ��

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

#### List��С����

��������

* ��list�����Ĵ�С���в���

����ԭ��

* size();                            //����������Ԫ�صĸ���
* empty();                        //�ж������Ƿ�Ϊ��
* resize(num);                 //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�ã����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
* resize(num, elem);       //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�ã����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

����ʾ��

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

#### List�����ɾ��

��������

* ��list�����������ݵĲ����ɾ��

����ԭ��

* push_back(elem);                  //������β������һ��Ԫ��
* pop_back();                          //ɾ�����������һ��Ԫ��
* push_front(elem);                //��������ͷ����һ��Ԫ��
* pop_front();                         //��������ͷ�Ƴ���һ��Ԫ��
* insert(pos, elem);               //��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
* insert(pos, n, elem);           //��posλ�ò���n��elem���ݣ��޷���ֵ
* insert(pos, beg, end);        //��posλ�ò���[beg, end]��������ݣ��޷���ֵ
* clear();                               //�Ƴ���������������
* erase(beg, end);                //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
* erase(pos);                        //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
* remove(elem);                 //ɾ��������������elemֵƥ���Ԫ��

����ʾ��

```C++
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
    list<int> L1;
    //β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //β��
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);
    L1.push_front(400);
    printList(L1);
    //βɾ
    L1.pop_back();
    //300, 200, 100, 10, 20
    printList(L1);
    //ͷɾ
    L1.pop_front();
    printList(L1);
    //insert����
    list<int>:: iterator  it=L1.begin();
    L1.insert(++it, 1000);
    L1.insert(L1.begin(), 1000);
    //1000  200  100  10  20
    printList(L1);
    //ɾ��
    it=L1.begin();
    L1.erase(it);
    //200 100 10  20
    printList(L1);
    //�Ƴ�
    L1.push_back(10000);
    printList(L1);
    L1.remove(1000);
    //���
    L1.clear();
    printList(L1);
}
```

#### list���ݴ�ȡ

��������

* ��list���������ݽ��д�ȡ

����ԭ��

* front();                                          //���ص�һ��Ԫ��
* back();                                          //�������һ��Ԫ��

����ʾ��

```C++
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
     list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //L1(0)   ��������[]����list�����е�Ԫ��
    //L1.at(0);   ��������at��ʽ����list�����е�Ԫ��
    //ԭ����list�������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�
    cout<<"��һ��Ԫ��Ϊ��"<<L1.front()<<endl;
    cout<<"���һ��Ԫ��Ϊ��"<<L1.back()<<endl;
    //��֤�������ǲ�֧���������
    list<int>::iterator it=L1.begin();
    //it=it+2;  ����
    it++;      //��ȷ
    it--;       //��֧���������
}
```

#### list ��ת������
��������

* �������е�Ԫ�ط�ת���Լ��������е����ݽ�������

����ԭ��

* reverse()     //��ת����
* sort()          //��������

����ʾ��

```C++
#include<iostream>
#include<list>
using namespace std;
//list ��ת������
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool myCompare(int v1, int v2)
{
    //����
    return v1>v2;
}
void test()
{
    //��ת
    list<int> L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);
    cout<<"��תǰ��"<<endl;
    L1.reverse();
    cout<<"��ת��"<<endl; 
    printList(L1);
    //����
    cout<<"����ǰ��"<<endl;
    printList(L1);
    L1.sort();   //Ĭ������
    cout<<"�����"<<endl;
    printList(L1);
    //���в�֧��������ʵ��������������������ñ�׼�㷨
    //��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
    L1.sort(myCompare);
    cout<<"�����"<<endl;
    printList(L1);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

#### ������

��������

* ��Perosn�Զ����������ͽ�������Person�����������������䡢���
* ������򣺰�����������������������ͬ������߽��н���

����ʾ��

```C++
#include<iostream>
#include<list>
using namespace std;
//list����  ������  �����Զ�����������  ������
//������������������������ͬ������߽��н���
class Person
{
public:
     Person(string name, int age, int height)
     {
         this->m_Name=name;
         this->m_Age=age;
         this->m_Height=height;
     }
     string m_Name;
     int m_Age;
     int m_Height;
};
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool myCompare(int v1, int v2)
{
    //����
    return v1>v2;
}
//ָ���������
bool comparePerson(Person &p1, Person &p2)
{
    //�������䣬����
    if (p1.m_Age==p2.m_Age)
    {
        return p1.m_Height<<p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}
void test()
{
    //��ת
    list<Person> L;
   //��������
   Person p1("����", 35, 163);
   Person p2("�ŷ�", 39, 168); 
   Person p3("����", 34, 176);
   Person p4("�ܲ�", 41, 170);
   Person p5("���", 43, 180);
   Person p6("����", 35, 178);
   //��������
   L.push_back(p1);
   L.push_back(p2);
   L.push_back(p3);
   L.push_back(p4);
   L.push_back(p5);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"������"<<(*it).m_Name
              <<" ���� ��"<<it->m_Age
              <<" ��� ��"<<it->m_Height<<endl;
   }
   //����
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------�����---------------"<<endl;
   L.sort(comparePerson);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"������"<<(*it).m_Name
              <<" ���� ��"<<it->m_Age
              <<" ��� ��"<<it->m_Height<<endl;
   }
}
int main()
{
    test();
    system("pause");
    return 0;
}   
```

### 2.7 set/multiset����

��������

* ����Ԫ�ض����ڲ���ʱ�Զ�������

����

* set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

set��multiset����

* set ���������������ظ���Ԫ��
* multiset�������������ظ���Ԫ��

#### set����͸�ֵ

����ʾ��

```C++
#include<iostream>
#include<set>
using namespace  std;
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set��������͸�ֵ
void test()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //��������
    //set�����ص㣬����Ԫ�ز���ʱ���Զ�����
    //set��������������ظ�ֵ
    printSet(s);
    //��������
    set<int>s2(s);
    printSet(s2);
    //��ֵ
    set<int>s3;
    s3=s2;
    printSet(s3);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

#### set��С�ͽ���

��������

* ͳ��set�����Լ�����set����

����ԭ��

* size();     //����������Ԫ�ص���Ŀ
* empty();    //�ж������Ƿ�Ϊ��
* swap();      //����������������

����ʾ��

```C++
#include<iostream>
#include<set>
using namespace  std;
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set������С�ͽ���
//��С
void size()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //��ӡ����
    printSet(s);
    //�ж��Ƿ�Ϊ��
    if (s.empty())
    {
        cout<<"sΪ��"<<endl;
    }
    else
    {
        cout<<"s��Ϊ��"<<endl;
        cout<<"s�Ĵ�С"<<s.size()<<endl;
    }
}
//����
void exchange()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    set<int>s1;
    //�������ݣ�ֻ���� insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s1.insert(60);
    s1.insert(70);
    s1.insert(80);
    s1.insert(90);
    s1.insert(100);
    cout<<"����ǰ��"<<endl;
    printSet(s);
    printSet(s1);
    s1.swap(s);
    cout<<"������"<<endl;
    printSet(s);
    printSet(s1);
}
```

#### set�����ɾ��

��������

* set�������в������ݺ�ɾ������

����ԭ��

* insert(elem);             //�������в���Ԫ��
* clean();                     //�������Ԫ��
* erase(pos);               //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
* erase(beg, end);       //ɾ������[beg, end]������Ԫ�أ�������һ��Ԫ�صĵ�����
* erase(elem);             //ɾ��������ֵΪelem��Ԫ��

����ʾ��

```C++
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    set<int>s;
    //����
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    //����
    printSet(s);
    //ɾ��
    s.erase(s.begin());
    printSet(s);
    //ɾ�����ذ汾
    s.erase(30);
    printSet(s);
    //���
    //s.erase(s.begin(), s.end());
    s.clear();
    printSet(s);
}
```

* ����  ---insert
* ɾ��  ---erase
* ���  ---clear

####set���Һ�ͳ��

��������

* ��set�������в��������Լ�ͳ������

����ԭ��

* find(key);    //����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
* count(key);   //ͳ��key��Ԫ�ظ���

����ʾ��

```C++
//set�������Һ�ͳ��
void test01()
{
    set<int>s;
    //�������ݣ�ֻ����insert��ʽ
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //����
    set<int>:: iterator pos =s.find(30);
    if (pos!=s.end())
    {
        cout<<"�ҵ�Ԫ�أ�"<<endl;
    }
}
void test02()
{
    //����
    set<int>s;
    //��������
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //ͳ��30�ĸ���
    int num=s.count(30);
    cout<<"������"<<num<<endl;
}
```  
#### set��multiset����
ѧϰĿ��
* ����set��multiset������
����
* set�����Բ����ظ����ݣ���multiset����
* set�������ݵ�ͬʱ�᷵�ز���������˿��Բ����ظ�����
����ʾ��
```C++
//set��mutiset����
void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret=s.insert(10);
    if (ret.second)
    {
        cout<<"��һ�β���ɹ�"<<endl;
    }
    else
    {
        cout<<"��һ�β���ʧ��"<<endl;
    }
    ret=s.insert(10);
     if (ret.second)
    {
        cout<<"��һ�β���ɹ�"<<endl;
    }
    else
    {
        cout<<"��һ�β���ʧ��"<<endl;
    }
    multiset<int>ms;
    //��������ظ�ֵ
    ms.insert(10);
    ms.insert(10);
    for (set<int>::iterator it=ms.begin(); it!=ms.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
```  
#### pair���鴴��  
 ��������  
* �ɶԳ��ֵ����ݣ����ö�����Է�����������
���ִ�����ʽ
* pair<type, type>p(valuel, value);
* pair<type, type>p=make_pair(value1, value2);
����ʾ��
```C++
void test()
{
    //��һ�ַ�ʽ
    pair<string,int>p1("Ton", 20);
    cout<<"������"<<p1.first<<"���䣺"<<p1.second<<endl;
    //�ڶ��ַ�ʽ
    pair<string, int>p2=make_pair("jenrry", 10);
    cout<<"������"<<p2.first<<"���䣺"<<p2.second<<endl;
}
```
#### set��������
* set����Ĭ���������Ϊ��С����������θı��������
* ���÷º��������Ըı��������
����ʾ��
```C++
/����set�����������
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        //����
        return v1>v2;
    }
};
//set����  ������  ����������������  ������
void test01()
{
    set<int, MyCompare>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    for (set<int, MyCompare>:: const_iterator  it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set �����Զ����������ͽ������򣬰�����������������������ͬ������߽��н���
class Person
{
public:
     Person(string name, int age, int height)
     {
         this->m_Name=name;
         this->m_Age=age;
         this->m_Height=height;
     }
     string m_Name;
     int m_Age;
     int m_Height;
};
class ComparePerosn
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        //�������䣬����
        return p1.m_Height>p2.m_Height;
    }
};
void test02()
{
   set<Person, ComparePerosn> s;
   //��������
   Person p1("����", 35, 163);
   Person p2("�ŷ�", 39, 168); 
   Person p3("����", 34, 176);
   Person p4("�ܲ�", 41, 170);
   Person p5("���", 43, 180);
   Person p6("����", 35, 178);
   //��������
   s.insert(p1);
   s.insert(p2);
   s.insert(p3);
   s.insert(p4);
   s.insert(p5);
      //����
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------�����---------------"<<endl;
   for (set<Person, ComparePerosn>:: iterator it=s.begin(); it!=s.end(); it++)
   {
       cout<<"������"<<(*it).m_Name
              <<" ���� ��"<<it->m_Age
              <<" ��� ��"<<it->m_Height<<endl;
   }
}
```  
### 2.8map����
#### map��������  
���
* map������Ԫ����pair
* pair�е�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)
* ����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
 ����  
* map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�
�ŵ�  
* ���Ը���keyֵ�����ҵ�valueֵ��map��multimap����map���������������ظ�keyֵԪ��
* multimap�������������ظ�keyֵԪ��
####12.2 map����͸�ֵ
��������
* ��map�������й���͸�ֵ����
����ԭ��
* map<T1, T2>mp;     //map���캯��
* map(const map &mp);  //�������캯��
 ��ֵ
* map& operator=(const, map&mp);   //���صȺŲ�����
����ʾ��
```C++
void test01()
{
    //����map����
    map<int, int>m;
    m.insert(pair<int, int>(90, 80));
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(30, 40));
    m.insert(pair<int, int>(50, 60));
    printMap(m);
    //��������
    map<int, int>m2(m);
    printMap(m2);
    //��ֵ
    map<int, int>m3;
    m3=m2;
    printMap(m3);
}
```
#### map��С�ͽ���  
��������  
* ͳ��map������С�Լ�����map����
����ԭ��
* size();       //����������Ԫ�ص���Ŀ
* empty();   //�ж������Ƿ�Ϊ��
* swap(st);  //������������
����ʾ��
```C++
//map������С�ͽ���
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(30, 40));
    m.insert(pair<int, int>(50, 60));
    if (m.empty())
    {
        cout<<"m����Ϊ��";
    }
    else
    {
        cout<<"m������Ϊ��"<<m.size()<<endl;
    }
    printMap(m);
    map<int, int>m1;
    m1.insert(pair<int, int>(12, 13));
    m1.insert(pair<int, int>(14, 15));
    m1.insert(pair<int, int>(16, 17));
    m1.insert(pair<int, int>(18, 19));
    cout<<"����ǰ"<<endl;
    m1.swap(m);
    printMap(m);
    printMap(m1);
}
```
#### map�����ɾ��  
��������  
* map�������в������ݺ�ɾ������  
����ԭ��  
* insert(elem);            //�������в���Ԫ��
* clean();                    //�������Ԫ��
* erasre(pos);             //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
* erase(beg, end);      //ɾ������[beg, end]������Ԫ�أ�������һ��Ԫ�صĵ�����
* erase(key);               //ɾ��������ֵΪkey��Ԫ��
����ʾ��
```C++
//map����  �����ɾ��
void test()
{
    map<int, int>m;
    //����1
    m.insert(pair<int, int>(1,10));
    //����2
    m.insert(make_pair(2,10));
    //����3
    m.insert(map<int, int>::value_type(3,10));
    //����4
    m[2]=40;     //������ʹ��
    //ɾ��
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);
    //���
    m.erase(m.begin(), m.end());
    m.clear();
}
```  
#### map���Һ�ͳ��  
��������
* ��map�������в��������Լ�ͳ������
����ԭ��
* find(key);         //����key�Ƿ���ڣ������ڣ����ظļ���Ԫ�صĵ��������������ڣ�����set.end();
* count(key);      //ͳ��key��Ԫ��
����ʾ��
```C++
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(12, 13));
    m.insert(pair<int, int>(14, 15));
    m.insert(pair<int, int>(16, 17));
    m.insert(pair<int, int>(18, 19));
    //����
    map<int, int>::iterator pos=m.find(3);
    if (pos!=m.end())
    {
        cout<<"�鵽��Ԫ��key= "<<(*pos).first<<"value="<<pos->second<<endl;
    }
    else
    {
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }
    //ͳ��
    //map����������ظ�keyԪ�أ�countͳ�ƶ��ԣ����Ҫô��0��Ҫô��1
    //mutimap��countͳ�ƿ��ܴ���1
    int num=m.count(13);
    cout<<"num="<<num<<endl;
}
```   
�ܽ�
* ����---find�����ص��ǵ�������
* ͳ��---count������map�����Ϊ0����1��  
#### map��������  
* map����Ĭ���������Ϊ����keyֵ���д�С��������������θı��������
��Ҫ������
* ���÷º��������Ըı��������

����ʾ��
```C++
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }
};
void printMap(map<int, int, MyCompare>&m)
{
    for (map<int, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<"key=  "<<it->first<<" "<<"value= "<<it->second<<endl;
    }
    cout<<endl;
}
//map����  ����
void test()
{
    map<int, int, MyCompare>m;
    m.insert(pair<int, int>(12, 13));
    m.insert(pair<int, int>(14, 15));
    m.insert(pair<int, int>(16, 17));
    m.insert(pair<int, int>(18, 19));
    m.insert(make_pair(9, 10));
    printMap(m);

}
```  
�ܽ�
* ���÷º�������ָ��map�������������
* �����Զ����������ͣ� map����ָ���������ͬset����  
#### ����-Ա������  
��������  
* ��˾������Ƹ��10��Ա��(ABCDEFGHI)��10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
* Ա����Ϣ��������������ɣ����ŷ�Ϊ���߻����������з�
* �����10��Ա�����䲿�ź͹���
* ͨ��multimap������Ϣ�Ĳ��룬key(���ű��)value(Ա��)
* �ֲ�����ʾԱ����Ϣ
ʵ�ֲ���
1. ����10��Ա�����ŵ�vector��
2. ����vector������ȡ��ÿ��Ա���������������
3. ����󣬽�Ա�����ű����Ϊkey�����幤����Ϊvalue���ŵ�multimap������
4. �ֲ�����ʾԱ����Ϣ
��������
```C++  
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#define  Scheme     0
#define  Fine_arts   1
#define  Research_development  2
using namespace std;
class Employee
{
public:
    Employee(string name, int salary)
    {
        this->m_Name=name;
        this->m_Salary=salary;
    }
    string m_Name;
    int  m_Salary;
};
//����Ա��
void creat_employee(vector<Employee>&v)
{
    string nameSeed="ABCDEFGHJK";
    for (int i = 0; i < 10; i++)
    {
        string name="Ա����";
        name+=nameSeed[i];
        int salary=rand()%5000+10000;   //10000~149999
        Employee e(name,salary);
        v.push_back(e);
    }
}
//����
void setGroup( vector<Employee>&v, multimap<int, Employee>&m)
{
    for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    {
        int depId=rand()%3;   //����������
        m.insert(make_pair(depId, *it));
    }
}
//��ʾԱ��
void showEmployee(multimap<int, Employee>&m)
{
    cout<<"�߻����ţ�"<<endl;
    multimap<int, Employee>::iterator pos=m.find(Scheme); 
    int num=m.count(Scheme);
    int  index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"������"<< pos->second.m_Name;
        cout<<"н�ʣ�"<<pos->second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"�������ţ�"<<endl;
    pos=m.find(Fine_arts); 
    num=m.count(Fine_arts);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"������"<< (*pos).second.m_Name;
        cout<<"н�ʣ�"<<(*pos).second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"�з����ţ�"<<endl;
    pos=m.find(Research_development); 
    num=m.count(Research_development);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"������"<< (*pos).second.m_Name;
        cout<<"н�ʣ�"<<(*pos).second.m_Salary<<endl;
    }
}
int main()
{
    //1. ����Ա��
    vector<Employee>v;
    creat_employee(v);
    // for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"������"<<(*it).m_Name;
    //     cout<<"нˮ��"<<(*it).m_Salary<<endl;
    // }    
    //2. Ա������
    multimap<int, Employee>m;
    setGroup(v, m);
    //������ʾԱ��
    showEmployee(m);
    system("pause");
    return 0;
}
```
## 3. STL-��������
### 3.1 ��������
#### ��������
* ���غ������ò��������࣬������Ϊ��������
* ��������ʹ�����أ���Ϊ���ƺ������ã�Ҳ�зº���
#### ����  
��������(�º���)��һ���࣬����һ������
#### ��������ʹ��  
�ص㣺  
* ����������ʹ�ã���������ͨ�����������ã������в��������Է���ֵ
* �������󳬳���ͨ�����ĸ����������������Լ���״̬
* �������������Ϊ��������
#### ����ʾ��  
```C++
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return  v1+v2;
    }
};
//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01()
{
    MyAdd myadd;
    cout<<myadd(10, 10)<<endl;
}
//2. �������󳬳���ͨ�����ĸ���������Լ���״̬
class myPrint
{
public:
     myPrint()
     {
         this->count=0;
     }
    void operator()(string test)
    {
        cout<<test<<endl;
        this->count++;
    }
    int count;  //�ڲ�״̬
};
void test02()
{
    myPrint myprint;
    myprint("hello world");
    myprint("hello world");
    cout<<"myprint���ô���"<<myprint.count<<endl;
}
//�������������Ϊ��������
void doPrint(myPrint &mp, string test)
{
    mp(test);
}
void test03()
{
    myPrint myprint;
    doPrint(myprint,"hello c++");
}
```
### 3.2 ν��
#### ��������
* ����bool���͵ķº�����Ϊν��
* ���operator()����һ����������ô����һԪν��
* ���operator()����������������ô������Ԫν��
####  һԪν��(ʾ��)
```C++
class GreatFive
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //GreaterFive()   //������������
    vector<int>::iterator it=find_if(v.begin(), v.end(), GreatFive());
    if (it==v.end())
    {
        cout<<"δ�ҵ�"<<endl;
    }
    else
    {
        cout<<"���ҵ�"<<*it<<endl;
    }    
}  
```
####  ��Ԫν��
```C++
//��Ԫν��
class myCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1>val2;
    }
};
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    //GreaterFive()   //������������
   sort(v.begin(), v.end(), myCompare());
   for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
```  
###3.3 �ڽ���������  
#### �ڽ�������������
����  
* STL�ڽ���һЩ��������  
����  
* �����º���
* ��ϵ�º���
* �߼��º���
�÷�  
* �º����������Ķ����÷���һ�㺯����ȫ��ͬ
* ʹ���ڽ�����������Ҫ����ͷ�ļ�#include<functional>
#### �����º���
��������
* ʵ����������
* ����negative��һԪ���㣬�������Ƕ�Ԫ����
�º���ԭ��
* template<class T> T plus<T>          //�ӷ��º���
* template<class T>T minus<T>        //�����º���  
* template<class T>T multiplies<T>  //�˷��º���
* template<class T>T divides<T>      //�����º���
* template<class T>T modulus<T>   //ȡģ�º���
* template<class T>T negate<T>      //ȡ���º���
����ʾ��
```C++
/�ڽ��������������º���
//negate  һԪ�º��� ��ȡ�� �º���
void test()
{
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus ��Ԫ�º���  �ӷ�
void test01()
{
    plus<int>p;
    cout<<p(2, 3)<<endl;
}
```
#### ��ϵ�º���
��������
* ʵ�ֹ�ϵ�Ա�
�º���ԭ��
* template<class T> bool equal_to<T>                         //����
* template<class T>bool note_equal_to<T>                //������
* template<class T>bool greater<T>                           //����
* template<class T>bool greater_equal<T>                //���ڵ���
* template<class T>bool less<T>                                //С��
* template<class T>bool less_equal<T>                    //С�ڵ���
����ʾ��
```C++
//�ڽ���������_�����º���
//���� greater
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }
};
void test()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //����
    //sort(v.begin(), v.end(), MyCompare)��
    //greater<int>() �ڽ�����
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
```
�ܽ᣺��ϵ�º�������õľ���greater<>����
#### �߼��º���
��������
* ʵ���߼�����
��������
* template<class T>bool logical_and<T>    //�߼���
* template<class T>bool logicla_or<T>      //�߼���
* template<class T>bool logical_not<T>    //�߼���
����ʾ��
```C++
void test()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //�����߼��ǡ�������v���˵�����v2�У���ִ��ȡ������
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), v.end(), logical_not<bool>());
    for (vector<bool>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
```
## 4. STL-�����㷨
������
* �㷨��Ҫ����ͷ�ļ�<algorithm>��<functional>��<numeric>
### 4.1 ���ñ����㷨
#### for_each 
����������
* ʵ�ֱ�������
����ԭ�ͣ�
* for_each(iterator beg, iterator end, func)
  //�����㷨 ��������Ԫ��
  //beg ��ʼ������
  //end  ����������
  // _func �������ߺ�������
����ʾ����
```C++
//���ñ����㷨 for_each
//��ͨ����
void print01(int val)
{
    cout<<val<<" ";
}
//�º���
class print02
{
public:
    void operator()(int val)
    {
        cout<<val<<endl;
    }
};
void test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout<<endl;
    for_each(v.begin(), v.end(), print01);
    cout<<endl;
    for_each(v.begin(), v.end(), print02());
}
```
#### transform
��������
* ������������һ��������
����ԭ��
* transform(iterator beg1, iterator end1, iterator beg2, func)
  //beg1 Դ������ʼ������
  //end1 Դ��������������
  //beg2 Ŀ��������ʼ������
  //_func �������ߺ�������
����ʾ��
```C++
class Print
{
public:
    int operator()(int v)
    {
        return v;
    }
};
class Myprint
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};
void test()
{
    vector<int>v;
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    transform(v.begin(),v.end(), v1.begin(), Print());
    for_each(v1.begin(), v1.end(), Myprint());  
}
```
### 4.2 ���ò����㷨
��飺
* find                                       //����Ԫ��
* find_if                                   //����������Ԫ��
* adjacent_find                        //���������ظ�Ԫ��
* binary_serach                        //���ֲ��ҷ�
* count                                    //ͳ��Ԫ�ظ���
* count_if                                // ������ͳ��Ԫ�ظ���
#### find
�㷨���
* ����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()

����ԭ��
* find(iterator beg, iterator end, value);
  //��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
  //beg��ʼ������
  //end����������
  //value ���ҵ�Ԫ��
����ʾ��
```C++
//find
//���� ������������
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //���������У��Ƿ���5���Ԫ��
    vector<int>::iterator it=find(v.begin(), v.end( ), 2 );
    if (it==v.end())
    {
        cout<<"û���ҵ���"<<endl;
    }
    else
    {
        cout<<"�ҵ���"<<*it<<endl;
    }
}
//��
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    //���� ==�ײ�find֪����ζԱ�person��������
    bool operator== (const Person & p)
    {
        if (this->m_Name==p.m_Name&& this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
//���ҡ��Զ�����������
void test02()
{
    vector<Person>v;
    //��������
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    vector<Person>::iterator it=find(v.begin(), v.end(), pp);
    if (it==v.end())
    {
        cout<<"û���ҵ�"<<endl;
    }
    else
    {
        cout<<"�ҵ�Ԫ�� ������"<<it->m_Name<<"���䣺"<<it->m_Age<<endl;
    }
}
```
#### find_if
��������
* ����������Ԫ��  

����ԭ��
* find_if(iterator beg, iterator end, _Pred);
  //��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
  //beg��ʼ������
  //end����������
  // _Pred��������ν��(����bool���Եķº���)

ʾ����
```C++
/find_if
// 1.������������
//ν��
class  sss
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //���������У��Ƿ���5���Ԫ��
    vector<int>::iterator it=find_if(v.begin(), v.end( ), sss() );
    if (it==v.end())
    {
        cout<<"û���ҵ���"<<endl;
    }
    else
    {
        cout<<"�ҵ���"<<*it<<endl;
    }
}
//�Զ�����������
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    string m_Name;
    int m_Age;
};
// 1.������������
//ν��
class  sss20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age>20;
    }
};
//���ҡ��Զ�����������
void test02()
{
    vector<Person>v;
    //��������
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //�ҵ��������20����
    vector<Person>::iterator it=find_if(v.begin(), v.end(), sss20());
    if (it==v.end())
    {
        cout<<"û���ҵ�"<<endl;
    }
    else
    {
        cout<<"�ҵ�Ԫ�� ������"<<it->m_Name<<"���䣺"<<it->m_Age<<endl;
    }
}
```
#### adjacent_find
����������
* ���������ظ�Ԫ��

����ԭ�ͣ�
* adjacent_find(iterator beg, iterrator end);
  //���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
  //beg��ʼ������
  //end ����������
ʾ����
```C++
void test()
{
    vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    vector<int>::iterator it=adjacent_find(v.begin(), v.end());
    if (it==v.end())
    {
        cout<<"û���ҵ�"<<endl;
    }
    else
    {
        cout<<"�ҵ�Ԫ�أ�"<<*it<<endl;
    }
}
```
#### binary_search
��������
* ����ָ��Ԫ���Ƿ����

����ԭ��
* bool binary_search(iterator beg, iterator end, value);
  //����ָ��Ԫ�أ��鵽����true ����false
  //ע�⣺�����������в�����
  //beg��ʼ������
  //end����������
  //value ���ҵ�Ԫ��

ʾ��
```C++
void test()
{
    vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    bool it=binary_search(v.begin(), v.end(), 20);
    if (it)
    {
        cout<<"û���ҵ�"<<endl;
    }
    else
    {
        cout<<"�ҵ�Ԫ�أ�"<<endl;
    }
}
```
#### count
ͳ��Ԫ�ظ���
* (iterator beg, iterator end, value)��
  //ͳ��Ԫ�س��ִ���
  //beg ��ʼ������
  //end ����������
  //value ͳ�Ƶ�Ԫ��

ʾ��
```C++
//count
//ͳ�Ƹ���
//1.������������
void test()
{
    vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count(v.begin(), v.end(), 20);
    cout<<"Ԫ�ظ�����"<<it<<endl;
}
//2. �Զ�����������
//��
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    //���� ==�ײ�find֪����ζԱ�person��������
    bool operator== (const Person & p)
    {
        if (this->m_Name==p.m_Name&& this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
//���ҡ��Զ�����������
void test02()
{
    vector<Person>v;
    //��������
    Person p1("bbb", 20);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    int num=count(v.begin(), v.end(), pp);
    cout<<"Ԫ�ظ�����"<<num<<endl;
}
```
#### count_if
* ������ͳ��Ԫ�ظ���

����ԭ��
* count_if(iterator beg, iterator end, _Pred);
  //������ͳ��Ԫ�س��ִ���
  //beg��ʼ������
  //end����������
  //_Pred ν��

ʾ��
```C++
//���ò����㷨   count_if
//ͳ��������������
class Greater
{
public:
    bool operator()(int val)
    {
        return val>20;
    }
};
void test01()
{
        vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count_if(v.begin(), v.end(), Greater());
    cout<<"Ԫ�ظ�����"<<it<<endl;
}
//ͳ���Զ�����������
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    string m_Name;
    int m_Age;
};
//�º���
class AgeGreat
{
public:
    bool operator() (const Person & p)
    {
        return p.m_Age>20;
    }
}; 
//���ҡ��Զ�����������
void test02()
{
    vector<Person>v;
    //��������
    Person p1("�ܲ�", 30);
    Person p2("���", 20);
    Person p3("��Ȩ", 30);
    Person p4("С��", 18);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    int num=count_if(v.begin(), v.end(), AgeGreat());
    cout<<"Ԫ�ظ�����"<<num<<endl;
}
```
### 4.3 ���������㷨
�㷨���
* sort                                           //��������Ԫ�ؽ�������
* random_shuffle                        //ϴ��   ָ����Χ�ڵ�Ԫ�������������
* merge                                       //����Ԫ�غϲ������洢����һ��������
* reverse                                      //��תָ����Χ�ڵ�Ԫ��

#### sort
* ��������Ԫ�ؽ�������
* sort(iterator beg, iterator end, _Pred)
  //��ֵ�ҵ�Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
  //beg ��ʼ������
  //end ����������
  // _pred ν��

ʾ��
```C++
//���������㷨��sort
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);
    //����sort����
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //����
    sort(v.begin(), v.end(), greater<int>());
}
```
#### random_shuffle
* ϴ�� ָ����Χ�ڵ�Ԫ�������������
* random_shuffle(iterator beg, iterator end);
  //ָ����Χ�ڵ�Ԫ���������
  //beg ��ʼ������
  //end ����������

ʾ��
```C++
//���������㷨��random_shuffle
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    //����ϴ�ơ��㷨������˳��
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //����
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
}
```
#### merge
* ��������Ԫ�غϲ������洢����һ��������
* merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 //����Ԫ�غϲ������洢����һ��������
 //ע�⣺�����������������
 //beg1 ����1��ʼ������
 //end1 ����1����������
 //beg2 ����2��ʼ������
 //end2 ����2����������
 //dest  Ŀ��������ʼ������

ʾ����
```C++
//���������㷨 merge
class myPrint
{
public:
    void operator() (int val)
   {
        cout<<val<<" ";
   }
};
void  test01()
{
    vector<int>v1;
    vector<int>v2;
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    vector<int>vTarget;
    //��ǰ��Ŀ����������ռ�
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint());
}
```
#### reverse
  * ��������Ԫ�ؽ��з�ת

����ԭ�ͣ�
*reverse(iterator beg, iterator end);
 //��תָ����Χ��Ԫ��
 //beg��ʼ������
 //end ����������

ʾ����
```C++
//���������㷨 merge
void myPrint (int val)
{
        cout<<val<<" ";
}
//reverse�㷨
void test01()
{
    vector<int>v1;
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    cout<<"��תǰ��"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<"��ת��"<<endl;
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), myPrint);
}
```
### 4.3 ���ÿ������滻�㷨
* copy     //������ָ����Χ�ڵ�Ԫ�ؿ�������һ��������
* replace  //������ָ����Χ�ڵľ�Ԫ���޸�Ϊ��Ԫ��
* replace_if  //������ָ����Χ������������Ԫ���滻Ϊ��Ԫ��
* swap         //��������������Ԫ��
  
#### copy
* ������ָ����Χ�ڵ�Ԫ�ؿ�������һ��������
* copy(iterator beg, iterator end, iterator dest);
  //��ֵ����Ԫ�أ��ҵ�����λ�õ��������Ҳ������ؽ���������λ��

ʾ��
```C++
using namespace std;
//���ÿ����㷨���滻�㷨
//copy
void myPrint(int val)
{
    cout<<val<<" ";
}
void test()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), myPrint);
}
```
#### replace
* ��������ָ����Χ�ڵľ�Ԫ���޸�Ϊ��Ԫ��
* replace(iterator beg, iterator end, oldvalue, newvalue);
 //��תָ����Χ��Ԫ��
 //beg��ʼ������
 //end ����������
//oldvalue ��Ԫ��
//newvalue ��Ԫ��

ʾ��
```C++
class myPrint
{
public:
    void operator() (int val)
   {
        cout<<val<<" ";
   }
};
void test01()
{
    vector<int>v1;
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(20);
    v1.push_back(10);
    cout<<"�滻ǰ��"<<endl;
    for_each(v1.begin(), v1.end(), myPrint());
    cout<<"�滻��"<<endl;
    replace(v1.begin(), v1.end(), 20, 1000);
    for_each(v1.begin(), v1.end(), myPrint());
}
```
#### replace_if
```C++
//�滻�㷨replace_if
class myPrint
{
public:
    void operator() (int val)
   {
        cout<<val<<" ";
   }
};
class Greater
{
public:
    bool operator()(int val)
    {
        return val>20;
    }
};
void test01()
{
        vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(40);
     cout<<"�滻ǰ��"<<endl;
    for_each(v.begin(), v.end(), myPrint());
    cout<<"�滻��"<<endl;
    replace_if(v.begin(), v.end(), Greater(), 1000);
    for_each(v.begin(), v.end(), myPrint());
}
```
#### swap
* ��������������Ԫ��
* swap(container c1, container c2)
  //��������������Ԫ��
  //c1����1
  //c2����2

ʾ����
```C++
//���ÿ������滻�㷨
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
    }
    cout<<"����ǰ"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<"������"<<endl;
    swap(v1, v2);
    cout<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    for_each(v2.begin(), v2.end(), myPrint);
}
```
### 4.4 �������������㷨
* ���ճ��õ����������㷨
* ����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ #include<number>
* accumulate    //��������Ԫ���ۼ��ܼ�
* fill                   //�����������Ԫ��

#### accumulate
* ���������� ����Ԫ���ۼ��ܺ�
* accumulate(iterator beg, iterator end, value);
  //��������Ԫ���ۼ��ܺ�
  //beg ��ʼ������
  //end ����������
  //value��ʼֵ

ʾ����
```C++
//�������������㷨
void test01()
{
    vector<int>v;
    for (int i = 1; i < 101; i++)
    {
        v.push_back(i);
    }
    int total=accumulate(v.begin(),v.end(), 0);
    cout<<"total="<<total<<endl;
}
```
#### fill
* �����������ָ����Ԫ��
* fill(iterator beg, iterator end, value);
  //�����������Ԫ��
  //beg ��ʼ������
  //end ����������
  //value��ʼֵ

ʾ����
```C++
//�������������㷨 fill
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.resize(10);
    //�����������
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
}
```
### 4.5 ���ü����㷨
* set_intersection       //����������1�Ľ���
* set_union                 //�����������Ĳ���
* set_difference          //�����������Ĳ

#### set_intersection
* �����������Ľ���
* set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
  //���������ϵĽ���

ʾ����
```C++
//���ü����㷨 set_intersection
void myPrint(int val)
{
    cout<<val<<" ";
}
void test()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);   //0~9
        v2.push_back(i+1);  //5~14
    }
    vector<int>vTarget;
    //Ŀ��������Ҫ��ǰ���ٿռ�
    //���������������������С���������ٿռ䣬ȡС������size����
    vTarget.resize(min(v1.size(), v2.size()));
    //��ȡ����
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end
    (),vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout<<endl;
}
```  
�ܽ᣺
* �󽻼����������ϱ�������������
* Ŀ���������ٿռ���Ҫ������������ȡСֵ
* set_intersection����ֵ���ǽ��������һ��Ԫ�ص�λ��

#### set_union
* ���������ϵĲ���

����ԭ�ͣ�
* * set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
  //���������ϵĲ���
 //ע���������ϱ�������������
 ```C++
//���ü����㷨 set_diffence����
void myPrint(int val)
{
    cout<<val<<" ";
}
void test()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);   //0~9
        v2.push_back(i+5);  //5~14
    }
    vector<int>vTarget;
    //Ŀ��������Ҫ��ǰ���ٿռ�
    //������������������޽���������sizeΪ����֮�͡�
    vTarget.resize(max(v1.size(), v2.size()));
    //��ȡ����
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end
    (),vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout<<endl;
}
```

