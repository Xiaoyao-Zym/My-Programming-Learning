# STL

## 1. STL的基本概念

* STL(Standard Templae Library)标准模板库
* STL从广义分为：**容器(container)**、**算法(algorithm)**、**迭代器(iterator)**
* **容器**和**算法**之间通过**迭代器**进行无缝连接
* STL几乎所有的代码都采用了模板或者模板函数

### 1.2 STL的六大组件

STL大体分为六大组件：容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器

1. 容器：各种数据结构，如vector、list、deque、set、set、map等，用来存防数据
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂
4. 仿函数：行为类似函数，可作为算法的某种策略
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
6. 空间配置器：负责空间的配置与管理

### 1.3 STL中容器、算法、迭代器

STL容器就是将运用最广泛的一些数据实现出来
常用的数据结构：数组、链表、树、栈、队列、集合、映射表
这些容器分为**序列式容器**和**关联式容器**两种：
**序列式容器**：强调值的排序，序列式容器中每个元素均有固定的位置
**关联式容器**：二叉树结构，各元素之间没有严格的物理上的顺序关系

**算法**：有限的步骤，解决逻辑或数学上的问题，分为质变算法和非质变算法
质变算法：是指运算过程中会更改区间内的元素的内容，例如拷贝、替换、删除等
非质变算法：指运算过程中不会更改区间内的元素内容，例如查找、技术、遍历、寻找极值

**迭代器**：容器和算法之间粘合剂
提供一种方法，使之能够依序寻访某个容器所包含的各个元素，而又无需暴露该容器的内部表示方式
每个容器都有自己专属的迭代器
迭代器使用非常类似指针

迭代器种类：


| 种类           | 功能                                                       | 支持运算              |
| ---------------- | ------------------------------------------------------------ | ----------------------- |
| 输入迭代器     | 对数据只读访问                                             | 只读，支持++、==、！= |
| 输出迭代器     | 对数据的只写访问                                           | 只写，支持++          |
| 前向迭代器     | 读写操作，并能向前推进迭代器                               | 读写，支持++、==、！= |
| 双向迭代器     | 读写操作，并能向前和向后操作                               | 读写，支持++、==、！= |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，  功能最强的迭代器 | 读写，支持++、==、！= |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器。

### 1.4 容器算法迭代器初识

STL中最常用的容器为Vector，可以理解为数组，向这个容器中插入数据，并遍历这个容器

####  Vector存放内置数据类型

容器：  `vector`
算法：`for_each`
迭代器：`vector<int> :: iterator`

代码示例

```C++
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//自定义数据类型
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
   Person p1("孙悟空", 500);
   Person p2("猪八戒", 500);
   Person p3("沙和尚", 500);
   Person p4("唐  僧", 500);
   Person p5("白龙马", 500);
   //向容器中添加数据
   v.push_back(p1);
   v.push_back(p2);
   v.push_back(p3);
   v.push_back(p4);
   v.push_back(p5);
   //遍历容器中的数据
   for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<"姓名： "<<(*it).mName<<"  年龄："<<(*it).mAge<<endl;
   }
}
//存放自定义数据的指针
void test02()
{
   vector<Person*>v;
   Person p1("孙悟空", 500);
   Person p2("猪八戒", 500);
   Person p3("沙和尚", 500);
   Person p4("唐  僧", 500);
   Person p5("白龙马", 500);
   //向容器中添加数据
   v.push_back(&p1);
   v.push_back(&p2);
   v.push_back(&p3);
   v.push_back(&p4);
   v.push_back(&p5);
    //遍历容器中的数据
   for (vector<Person*>:: iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<"姓名： "<<(*it)->mName<<"  年龄："<<(*it)->mAge<<endl;
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

## 2 STL常用容器
### 2.1 string容器

#### 基本概念

本质：string是C++风格的字符串，本质是一个类**string和char**区别：

* char是一个指针
* string是一个类，类内部封装了char*，管理这个字符串，是一个char*类型的容器
  **特点：**
  string类内部封装了很多成员方法
  例如：查找find，拷贝copy，删除delete 替换replace，插入insert
  string管理char*所分配的内存，不用担心复制越界和取值越界，由类内部管理

#### string构造函数

构造函数原型：

* char();                        //创建一个空的字符串，例如  string str
* string(const char* s);     //使用字符串s初始化
* string(const string &str);   //使用一个string对象初始化另一个string对象
* string(int n, char c);  //使用n个字符c 初始化

#### string赋值操作

功能描述
* 给string字符串进行赋值
  赋值的函数原型：
* string& operator=(const char* s);         //char*类型字符串，赋值给当前的字符串
* string& operator=(const string &s);       //把字符串s赋值给当前字符串
* string& operator=(char c);                      //字符c赋值给当前字符串
* string& assign(const char *s, int n);        //把字符串s的前n个字符赋值给当前字符串
* string& assign(const string &s);             //把字符串赋值给当前字符串
* string& aasign(int n, char c);                 //用n个字符c赋值给当前字符串

代码示例
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

总结：string赋值方式很多，operator-方式较好。

#### string字符串的拼接

功能描述：

* 实现在字符串末尾拼接字符串

函数原型：

* string& operator+= (const char* str);        //重载+=操作符
* string& operator+= (const char c);           //重载+=操作符
* string& operator+= (const string& str);     //重载+=操作符
* string& append (const char *s);                 //把字符串s连接到当前字符串结尾
* string& append (const char *s, int n);         //把字符串s的前n个字符串连接到当前字符串结尾
* string& append (const string &s);              //同operator+=(const string& str)
* string& append(const string &s, int pos, int n);   //字符串s中从pos开始的n个字符连接到字符串结尾

代码示例

```C++
#include<iostream>
#include<string>
using namespace std;
/**************
*字符串拼接
*string& operator+= (const char* str);                    //重载+=操作符
*string& operator+= (const char c);                       //重载+=操作符
*string& operator+= (const string& str);               //重载+=操作符
*string& append (const char *s);                            //把字符串s连接到当前字符串结尾
*string& append (const char *s, int n);                  //把字符串s的前n个字符串连接到当前字符串结尾
*string& append (const string &s);                        //同operator+=(const string& str)
*string& append(const string &s, int pos, int n);   //字符串s中从pos开始的n个字符连接到字符串结尾
**************/
void test01()
{
    string str1="我";
    str1+="爱你";
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

#### string查找和替换

功能描述：

* 查找：查找指定字符串是否存在
* 替换：在指定的位置替换字符串

函数原型：

* int find (const string& str, int pos=0) const;     //查找str第一次出现位置从pos开始查找
* int find (const char* s, int pos=0) const;     //查找s第一次出现位置从pos开始查找
* int find (const char* s, int pos, int n) const;   //从pos位置查找s的前n个字符第一次位置
* int find (const char c，int pos=0)const;     //查找字符c第一次出现位置
* int rfind(const string& str, int pos=nops)const;  //查找str最后一次位置，从pos开始查找
* int rfind (const char* s, int pos=npos)const;       //查看s最后一次出现位置，从pos开始查收
* int rfind(const char *s, int pos, int n) const;   //从pos查找s的前n个字符最后一次位置
* int rfind(const char c, int pos=0) const;    //查找字符c最后一次出现位置
* string& replace(int pos, int n, const string& str);  //替换从pos开始n个字符串str
* string& repalce(int pos, int n, const char* s);   //替换从pos开始的n个字符为字符串s

代码示例

```C++
#include<string>
#include<iostream>
using namespace std;
//查找
void test01()
{
   string str1="abcdefg";
   //find查找从左往右；
   int pos =str1.find("cd");
   if (pos==-1)
   {
       cout<<"未找到字符串";
   }
   else
   {
       cout<<"找到子串位置："<<pos<<endl;
   }
   //rfind从右往左找
   pos=str1.rfind("cd");
   cout<<"pos="<<pos<<endl; 
}
//替换
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

#### string字符串比较

功能描述：

* 字符串之间的比较

比较方式：

* 字符串比较是按照字符ASCII码进行比较

等于，返回    0;大于，返回    1;小于，返回   -1;函数原型：

* int compare(const string&s) const;    //与字符串s比较
* int compare(const char *s)const;        //与字符串s比较

代码示例

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
       cout<<"str1等于str2"<<endl;
   }
   else if (str1.compare(str2)>0)
   {
       cout<<"str1大于str2"<<endl;
   }
   else
   {
       cout<<"str1小于str2"<<endl;
   }
}
int main()
{
   test01();
   system("pause");
   return 0;
}
```

#### string字符存取

string中单个字符存取方式有两种

* char& operator[](int n);      //通过[]方式取字符
* char& at(int n);                   //通过at方法获取字符

代码示例

```C++
#include<iostream>
#include<string>
using namespace std;
//string 字符存取
void test01()
{
  //通过[]方式取字符
  string str1="hello";
  for (int i = 0; i < str1.size(); i++)
  {
      cout<<str1[i]<<" ";
  }
  cout<<endl;
  //通过at方法获取字符
  for (int i = 0; i < str1.size(); i++)
  {
      cout<<str1.at(i)<<" ";
  }
  cout<<endl;
  //修改单个字符
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

#### string字符串插入和删除

功能描述：

* 对string字符串进行插入和删除字符操作

函数原型：

* string& insert(int pos, const char* s);   //插入字符串
* string& insert(int pos, const string& str);  //插入字符串
* string& insert(int pos, int n, cha c);       //在指定位置插入n个字符c
* string& erase(int pos, int n=nops);       //删除从Pos开始的n个字符

代码示例

```C++
#include<iostream>
#include<string>
using namespace std;
//string 字符
void test01()
{
  //通过[]方式取字符
  string str1="hello";
  str1.insert(2,"xxx");
  cout<<"str1="<<str1<<endl;
  //删除
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

#### string子串

功能描述：从字符串中选取所需要的子串

* string substr (int pos=0, int  n=npos)   //返回有pos组成的n个字符组成的字符串。

代码示例

```C++
#include<iostream>
#include<string>
using namespace std;
//string 求子串
void test01()
{
   string str="abcdef";
   string subStr=str.substr(1, 2);
   cout<<"subStr="<<subStr<<endl;
}
void test02()
{
    string email="zym@qq.com";
    //获取用户名
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

### 2.2vector容器

#### vector 基本概念

功能：

* vector数据结构和数组非常相似，也称为单端数组

vector与普通函数组区别：

* 不同之处在于数组是静态空间，而vector可以动态扩展

动态扩展：

* 并不是在原空间之后续接空间，而是找更好的内存空间，然后将原数据拷贝新空间，释放原空间。
* vector容器迭代器支持随机访问的迭代器

#### vector构造函数

功能描述：

* 创建vector容器

函数类型：

* vector<T>v;                            //实现模板实现类实现，默认构造函数
* vector (v.begin(), v.end());       //将[beg, end]区间中的元素拷贝给本身
* vector (n, elem);                     //构造函数将n个elem拷贝给本身
* vector (const vector &vec);    //拷贝构造函数

代码示例

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
//构造vector容器构造
void test()
{
   vector<int>v1;                 //默认构造
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   printVector(v1);
   //通过区间方式构造
   vector<int>v2(v1.begin(), v1.end());
    printVector(v2);
    //通过n个elem形式构造
    vector<int>v3(10, 100);
    printVector(v3);
    //拷贝构造
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

#### vector容器赋值

功能描述：

* 给vector容器进行赋值

函数原型：

* vector& operator=(const vector &vec);  //重载等号操作符
* assign(beg, end);         //将(beg, end)区间中的数据拷贝给赋值本身
* assign(n, elem);           //将n个elem拷贝赋值给本身。

代码示例：

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
//vector容器f赋值
void test()
{
   vector<int>v1;                 //默认构造
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   printVector(v1);
   //operator=赋值
   vector<int>v2=v1;
    printVector(v2);
    //通过assign形式赋值
    vector<int>v3;
    v3.assign(v2.begin(), v2.end());       //为左闭右开区间
    printVector(v3);
    //拷贝构造
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

#### vector容量和大小

功能描述：

* 对vector容器的容量和大小操作

函数原型：

* empty();                                  //判断容器是否为空
* capacity();                                //容器的容量
* size();                         //返回容器中元素的个数
* resize(int num);                //重新指定容器的长度为num，若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出容器容量的元素删除
* resize(int num, elem);       //重新指定容器的长度为num，若容器变长，则以elem填充新位置，若容器变短，则末尾超出容器长度的元素会被删除

代码示例

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
//vector容器f容量和大小
void test()
{
   vector<int>v1;                 //默认构造
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   //判断容器是否为空
   if (v1.empty())
   {
       cout<<"v1容器为空"<<endl;
   }
   else
   {
       cout<<"v1不为空"
              <<"v1的容量为："<<v1.capacity()
              <<"  v1的大小为"<<v1.size()<<endl;
   }
   v1.resize(18, 10);  //如果重新指定过长，默认用0填充，也可指定替换对象
   v1.resize(9);       //如果重新指定过短，则删除超出部分
   printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

#### vector容器的插入与删除
功能描述：
* 对vector容器进行插入、删除操作
函数原型：
* push_back(else);       //尾部插入元素ele
* pop_back();              //删除最后一个元素
* insert(const_itrerator pos, ele);     //迭代器指向位置pos插入元素ele
* insert(const_iterator pos, int count,ele);    //迭代器指向位置pos插入count个元素ele
* errase(const_iterator pos);      //删除迭代器的元素
* erase(const_iterrator start, const_iterator end);     //删除迭代器从start到end之间的元素
* clear();
  代码示例：
```C++
#include<iostream>
#include<vector>
using namespace std;
//vector 容器的插入与删除
/*
*push_back(else);                           //尾部插入元素ele
*pop_back();                                  //删除最后一个元素
*insert(const_itrerator pos, ele);   //迭代器指向位置pos插入元素ele
*insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele
*errase(const_iterator pos);        //删除迭代器的元素
*erase(const_iterrator start, const_iterator end); //删除迭代器从start到end之间的元素
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
    //尾插法初始化容器
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //尾删法
    v1.pop_back();
    printVector(v1);
    //尾插入  第一个参数是迭代器
    v1.insert(v1.begin(), 2, 100);
    printVector(v1);
    //删除   参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);
    //清空容器
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

总结

* 尾插--push_back
* 尾删--pop_back
* 插入--insert(位置迭代器)
* 删除--erase(位置迭代器)
* 清空--clear

#### vector数据存取
功能描述
* 对vector中的数据的存取操作  

函数原型：
* at(int idx);          //返回索引idx所指的数据
* operator[];         //返回索引idx所指的数据
* front();               //返回容器中第一个数据元素
* back();                //返回容器中最后一个数据元素

代码示例：
```C++
#include<iostream>
#include<vector>
using namespace std;
//vector容器数据存取
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
    //利用[]方式访问数组元素
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //利用at方式访问元素
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    //访问第一个元素
    cout<<"第一个元素为："<<v.front()<<endl;
    //获取最后一个元素
    cout<<"最后一个元素为："<<v.front()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

#### vector互换容器

功能描述：

* 实现两个容器内元素进行互换

函数原型：

* swap(vec);   //将vec与本身的元素互换

代码示例

```C++
#include<vector>
#include<iostream>
using namespace std;
//容器互换
void printVector(vector<int>v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//1.基本使用
void test01()
{
    cout<<"交换前："<<endl;
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
    cout<<"交换后："<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2.实际用途
//巧用swap可以收缩内存空间
void test02()
{
    vector<int>v3;
    for (int i = 0; i < 10000; i++)
    {
        v3.push_back(i);
    }
    cout<<"v3的容量为："<<v3.capacity()<<endl;
    cout<<"v3的大小为："<<v3.size()<<endl;
    //重新指定大小
    v3.resize(3);
    cout<<"v3的容量为："<<v3.capacity()<<endl;
    cout<<"v3的大小为："<<v3.size()<<endl;
    //巧用swap收缩内存
    vector<int>(v3).swap(v3);
    cout<<"v3的容量为："<<v3.capacity()<<endl;
    cout<<"v3的大小为："<<v3.size()<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
```

#### vector预留空间

功能描述：

* 减少vector在动态扩展容量时的扩展次数

函数原型：

* reserve(int len);      //容器预留len个元素长度，预留位置不初始化，元素不可访问

代码示例：
```C++
#include<iostream>
#include<vector>
using namespace std;

void test01()
{
    vector<int> v;
    //预留空间
    v.reserve(10000);
    int num=0;    //统计空间开辟次数
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

### 2.3 deque容器

#### 基本概念

功能：

* 双端数组，可以对头端进行删除操作

**deque**与**vector**区别：

* vector对于头部的插入删除效率低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度会比vector快
* vector访问元素时的速度会比deque快，这和两者内部实现有关

deque 内部工作原理deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据中控器维护的是每个缓冲区的地址，使得使用的deque时像一片连续的内存空间

* deque容器的迭代器也是支持随机访问

####  deque构造函数

功能描述：

* deque容器构造

函数原型：

* deque<T>deqT;                    //实现模板实现类实现，默认构造函数
* deque(beg, end());                //将[beg, end]区间中的元素拷贝给本身
* deque(n, elem);                     //构造函数将n个elem拷贝给本身
* deque(const deque &vec);     //拷贝构造函数

代码示例：

```C++
#include<iostream>
#include<deque>
using namespace std;
void printDeque(const deque<int>d)    //限定容器为只读状态
{
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//deque 构造函数
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

#### deque赋值操作

功能描述：

* 给deque容器进行赋值

函数原型：

* deque& operator=(const deque &deq);      //重载等号操作
* assign(beg, end);                                          //将[beg,end]区间中的数据拷贝赋值给本身
* assign(n, elem)                                           //将n个elem拷贝赋值给本身。

代码示例：

```C++
void test01()
{
    deque<int>d1;
    for (int i = 0; i <10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    //operator=赋值
    deque<int>d2;
    d2=d1;
    printDeque(d2);
    //assign赋值
    deque<int>d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);
    deque<int>d4;
    d4.assign(10, 9);
    printDeque(d4);
}
```

#### deque大小操作

功能描述：

* 对deque容器的大小进行操作

函数原型：

* deque.empty();            //判断容器是否为空
* deque.size();                //返回容器中元素的个数
* deque.resize(num);     //重新指定容器的长度为num，若容器变长，则以默认值填充新位置，                    //如果容器变短，则末尾超出长度的元素被删除
* deque.resize(num, elem);    //重新指定容器的长度为num，若容器变长，则以elem填充新位置，如果容器变短，则末尾超出容器长度的元素被删除。

代码示例：

```C++
//deque容器大小
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
        cout<<"d1为空"<<endl;
    }
    else
    {
         cout<<"d1不为空"
              <<"  d1的大小为"<<d1.size()<<endl;
              //deque没有容量概念
    }
    //重新指定大小
    d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);
    d1.resize(5);
    printDeque(d1);
}
```

总结：

* deque没有容量概念
* 判断是否为空----empty
* 返回元素个数----size
* 重新制定个数----resize

#### deque插入和删除

功能描述：

* 向deque容器中插入和删除数据

函数原型：

两端插入操作：

* push_back(elem);       //在容器尾部添加一个数据
* push_front(elem);       //在容器头部插入一个数据
* pop_back();                 //删除容器最后一个数据
* pop_front();                 //删除容器第一个数据

指定位置操作：

* insert(pos, elem);         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* insert(pos, n, elem);      //在pos位置插入n个elem数据，无返回值。
* insert(pos, beg, end);    //在pos位置插入[beg, end]区间的数据，无返回值。
* insert(pos, beg, end);    //在pos位置插入[beg, end]区间的数据，无返回值
* clear();                           //清空容器的所有位置
* erase(beg, end);            //删除[beg, end]区间的数据，返回下一个数据的位置
* erase(pos);                    //删除pos位置的数据，返回下一个数据的位置

代码示例：

```C++
void test01()
{
    deque<int>d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    //尾删
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
    //insert插入
    d1.insert(d1.begin(),1000);
    //1000  200 100  10  20
    printDeque(d1);
    d1.insert(d1.begin(), 2, 1000);
    //1000  10000  1000  200  100  10  20
    printDeque(d1);
    //按照区间进行插入
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
    //删除
    deque<int>::iterator it=d1.begin();
    it++;
    d1.erase(it);
    //200 10 20
    printDeque(d1);
    //按照区间方式删除
    d1.erase(d1.begin(), d1.end());
    printDeque(d1);
    //清空
    d1.clear();
    printDeque(d1);
}
```

总结：

* 插入和删除提供的位置是迭代器！
* 尾插   ---push_back
* 尾删   ---pop_back
* 头插   ---push_front
* 头删   ---pop_front

#### deque 数据存取

功能描述：

* 对deque中的数据的存取操作

 函数原型：

* at(int idx);       //返回索引idx所指的数据
* operator[];      //返回索引idx所指的数据
* front();            //返回容器中第一个数据元素
* back();            //返回容器中最后一个数据元素

代码示例：

```C++
//deque容器数据存取
void test01()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //通过[]方式访问元素
    //300  200  100  10  20 30
    for (int i = 0; i < d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    //通过at方式访问元素
    for (int i = 0; i < d.size(); i++)
    {
        cout<<d.at(i)<<" ";
    }
    cout<<"第一个元素为："<<d.front()<<endl;
    cout<<"最后一个元素："<<d.back()<<endl;
}
```

总结：

* 除了用迭代器获取deque容器中元素，[]和at也可以
* front返回容器第一个元素
* back返回容器最后一个元素

#### deque排序

功能描述：

* 利用算法实现对deque容器进行排序

算法：

* sort(iterator beg, iterator end)    //对beg和end区间内元素进行排序

代码示例：

```C++
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//deque排序
void printDeque(const deque<int>d)    //限定容器为只读状态
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
    cout<<"排序前"<<endl;;
    printDeque(d);
    //排序，默认升序规则
    //对于支持随机访问的迭代器的容器，都可以利用sort算法
    sort(d.begin(), d.end());
    cout<<"排序后"<<endl;
    printDeque(d);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

#### 案例-评委打分
 案例描述

* 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

实现步骤

* 创建五名选手，放到vector中
* 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器
* sort算法对deque容器中分数排序，去除最高分和最低分
* deque容器遍历一遍，累加总分
* 获取平均分

示例代码：

```C++
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//选手类
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
        string name="选手：";
        name+=nameSeed[i];
        int score=0;
        //将创建的person对象，放入到容器中
        Person p(name, score);
        v.push_back(p);
    }
}
//打分
void setScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        //将评委的打分放入deque容器中
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score=rand()%41+60; //60~100
            d.push_back(score);
        }
        // cout<<it->m_Name<<"打分："<<endl;
        // for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        // {
        //     cout<<*dit<<" ";   
        // }
        // cout<<endl;
        //排序
        sort(d.begin(), d.end());
        //去除最高分和最低分
        d.pop_back();
        d.pop_front();
        //取平均分
        int sum=0;
        for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        {
            sum+=*dit;   //累加每个分数
        }
        int avg=sum/d.size();
        //将平均分 赋值给选手身上
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        cout<<it->m_Name<<"   平均得分："<<it->m_Score<<endl;
    }
}
int main()
{
    //1. 创建5名选手
    vector<Person>v;  //存放选手的容器
    creatPerson(v);
    // for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"姓名："<<(*it).m_Name;
    //     cout<<"分数："<<(*it).m_Score<<endl;
    // }  
    //选手打分
    setScore(v);  
    //输出分数
    showScore(v);
    system("pause");
    return 0;
}
```

###2.4 stack容器

基本概念

* stack是一种先进后出(First In Last Out，FILO)的数据结构，它只有一个出口
* 栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
* 栈可以判断是否为空，empty()
* 栈可以返回元素个数：size()
* 进栈：push()，出栈：pop()

常用接口

功能描述：栈容器常用的对外接口构造函数：

* stack<T>stk;      //stack采用模板实现，stack对象的默认构造形式
* stack(const stack &stk);   //拷贝构造函数

赋值操作：

* stack& operator=(const stack &stk);     //重载等号操作符

数据存放：

* push(elem);       //向栈顶添加元素
* pop();                //从栈顶移除第一个元素
* top();                 //返回栈顶元素

大小操作

* empty();            //判断堆栈是否为空
* size();                //返回栈的大小

代码示例

```C++
#include<iostream>
#include<stack>
using namespace std;
//栈stack容器
void test()
{
    stack<int>s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    //只要栈不为空，查看栈顶，并且执行栈操作
    while (!s.empty())
    {
        //查看栈顶元素
        cout<<"栈顶元素为："<<s.top()<<endl;
        //出栈
        s.pop();
    }
    cout<<"栈的大小："<<s.size()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

### 2.5 queue容器

基本概念

* Queue是一种先进先出(First In First Out，FIFO)的数据结构，它有两个出口
* 队头：front()，队尾：back()，入队：push()，出队：pop()
* 只有两端可以被访问，不允许有遍历行为

常用接口

功能描述：栈容器常用的对外接口构造函数：

* queue<T>que;      //queue采用模板实现，queue对象的默认构造形式
* queue(const queue &stk);   //拷贝构造函数

赋值操作：

* queue& operator=(const stack &stk);     //重载等号操作符

数据存放：

* push(elem);       //向队尾添加元素
* pop();                //从队头移除第一个元素
* back();               //返回最后一个元素
* front();               //返回第一个元素

大小操作

* empty();            //判断堆栈是否为空
* size();                //返回栈的大小

代码示例

```C++
#include<iostream>
#include<queue>
using namespace std;
//队列queue容器
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
    //创建队列
    queue<Person>q;
    //入栈
    Person p1("唐三藏", 100);
    Person p2("孙悟空", 500);
    Person p3("猪八戒", 400);
    Person p4("沙和尚", 300);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"队列的大小："<<q.size()<<endl;
    //只要队列不为空，查看队头和队尾，并且执行出队操作
    while (!q.empty())
    {
        //查看队头元素
        cout<<"队头元素为--姓名："<<q.front().m_Name
               <<"--年龄："<<q.front().m_Age<<endl
               <<"队尾元素为--姓名："<<q.back().m_Name
               <<"--年龄："<<q.back().m_Age<<endl;
        //出队
        q.pop();
    }
    cout<<"队列的大小："<<q.size()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

### 2.6 list容器

基本概念

* 功能：将数据进行链式存储
* 链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
* 链表的组成：链表由一系列结点组成
* 结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
* STL中的链表是一个双向循环链表
* 优点：可以对任意的位置进行快速插入或删除元素
* 缺点：容器的遍历速度不如数组，占用空间比数组大
* 由于链表的存储方式不是连续的内存，属于双向迭代器

list的优点

* 采用动态存储分配，不会造成内存浪费和溢出
* 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点

* 链表灵活，但是空间(指针域)和时间(遍历)额外耗费较大
  list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的

总结

STL中list和vector是两个最常被使用的容器，各有优缺点

#### list构造函数

功能描述

* 创建list容器

函数原型

* list<T>lst;                   //list采用模板类实现，对象的默认构造形式
* list(beg, end);             //构造函数将[beg, end]区间中的元素拷贝给本身
* list(n, elem);               //构造函数将n个elem拷贝给本身
* list(const list &lst);    //拷贝构造函数

代码示例

```C++
//list容器构造函数
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
   //创建list容器，默认构造
   list<int>L1;
   //添加数据
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   //遍历容器
   printList(L1);
   //区间方式构造
   list<int>L2(L1.begin(), L1.end());
   printList(L2);
   //拷贝构造
   list<int>L3(L2);
   printList(L3);
   //n个elem
   list<int>L4(10, 1000);
   printList(L4);
}
```

#### list 容器赋值和交换

###功能描述：

* 给list容器进行赋值，以及交换list容器

函数原型

* assign(beg, end);                               //将[beg, end]区间中的数据拷贝赋值给本身
* assign(n, elem);                                 //将n个elem拷贝赋值给本身
* list&  operator=(const list &lst);      //重载等号操作符
* swap(lst);                                          //将lst与本身的元素互换

代码示例

```C++
   

void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list容器赋值和交换
void assignment()
{
    list<int>L1;
    //添加数据
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
//交换
void exchange()
{
   list<int>L1;
    //添加数据
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   list<int>L2;
   L2.assign(10,100);
   printList(L1);
   printList(L2);
   cout<<"交换后"<<endl;
   L1.swap(L2);
   printList(L1);
   printList(L2);
}
```

#### List大小操作

功能描述

* 对list容器的大小进行操作

函数原型

* size();                            //返回容器中元素的个数
* empty();                        //判断容器是否为空
* resize(num);                 //重新指定容器的长度为num，若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
* resize(num, elem);       //重新指定容器的长度为num，若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除

代码示例

```C++
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//list容器大小操作
void size()
{
    list<int>L1;
   L1.push_back(10);
   L1.push_back(20);
   L1.push_back(30);
   L1.push_back(40);
   printList(L1);
   //判断容器是否为空
   if (L1.empty())
   {
       cout<<"L1为空"<<endl;
   }
   else
   {
       cout<<"L1不为空"<<endl;
       cout<<"L1的大小："<<L1.size()<<endl;
   }
   //重新指定大小
   L1.resize(10, 1000);
   printList(L1);
}
```

#### List插入和删除

功能描述

* 对list容器进行数据的插入和删除

函数原型

* push_back(elem);                  //在容器尾部加入一个元素
* pop_back();                          //删除容器中最后一个元素
* push_front(elem);                //在容器开头插入一个元素
* pop_front();                         //从容器开头移除第一个元素
* insert(pos, elem);               //在pos位置插elem元素的拷贝，返回新数据的位置
* insert(pos, n, elem);           //在pos位置插入n个elem数据，无返回值
* insert(pos, beg, end);        //在pos位置插入[beg, end]区间的数据，无返回值
* clear();                               //移除容器的所有数据
* erase(beg, end);                //删除[beg, end]区间的数据，返回下一个数据的位置
* erase(pos);                        //删除[beg, end]区间的数据，返回下一个数据的位置
* remove(elem);                 //删除容器中所有与elem值匹配的元素

代码示例

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
    //尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //尾插
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);
    L1.push_front(400);
    printList(L1);
    //尾删
    L1.pop_back();
    //300, 200, 100, 10, 20
    printList(L1);
    //头删
    L1.pop_front();
    printList(L1);
    //insert插入
    list<int>:: iterator  it=L1.begin();
    L1.insert(++it, 1000);
    L1.insert(L1.begin(), 1000);
    //1000  200  100  10  20
    printList(L1);
    //删除
    it=L1.begin();
    L1.erase(it);
    //200 100 10  20
    printList(L1);
    //移除
    L1.push_back(10000);
    printList(L1);
    L1.remove(1000);
    //清空
    L1.clear();
    printList(L1);
}
```

#### list数据存取

功能描述

* 对list容器中数据进行存取

函数原型

* front();                                          //返回第一个元素
* back();                                          //返回最后一个元素

代码示例

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
    //L1(0)   不可以用[]访问list容器中的元素
    //L1.at(0);   不可以用at方式访问list容器中的元素
    //原因是list本质链表，不是用连续性空间存储数据，迭代器也是不支持随机访问的
    cout<<"第一个元素为："<<L1.front()<<endl;
    cout<<"最后一个元素为："<<L1.back()<<endl;
    //验证迭代器是不支持随机访问
    list<int>::iterator it=L1.begin();
    //it=it+2;  报错
    it++;      //正确
    it--;       //不支持随机访问
}
```

#### list 反转和排序
功能描述

* 将容器中的元素反转，以及将容器中的数据进行排序

函数原型

* reverse()     //反转链表
* sort()          //链表排序

代码示例

```C++
#include<iostream>
#include<list>
using namespace std;
//list 反转和排序
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
    //降序
    return v1>v2;
}
void test()
{
    //反转
    list<int> L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);
    cout<<"反转前："<<endl;
    L1.reverse();
    cout<<"反转后："<<endl; 
    printList(L1);
    //排序
    cout<<"排序前："<<endl;
    printList(L1);
    L1.sort();   //默认升序
    cout<<"排序后："<<endl;
    printList(L1);
    //所有不支持随机访问迭代器的容器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会提供对应一些算法
    L1.sort(myCompare);
    cout<<"排序后："<<endl;
    printList(L1);
}
int main()
{
    test();
    system("pause");
    return 0;
}
```

#### 排序案例

案例描述

* 将Perosn自定义数据类型进行排序，Person中属性有姓名、年龄、身高
* 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

代码示例

```C++
#include<iostream>
#include<list>
using namespace std;
//list容器  排序案例  对于自定义数据类型  做排序
//按照年龄进行升序，如果年龄相同按照身高进行降序
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
    //降序
    return v1>v2;
}
//指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    //按照年龄，升序
    if (p1.m_Age==p2.m_Age)
    {
        return p1.m_Height<<p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}
void test()
{
    //反转
    list<Person> L;
   //数据填入
   Person p1("刘备", 35, 163);
   Person p2("张飞", 39, 168); 
   Person p3("关羽", 34, 176);
   Person p4("曹操", 41, 170);
   Person p5("周瑜", 43, 180);
   Person p6("赵云", 35, 178);
   //弹入容器
   L.push_back(p1);
   L.push_back(p2);
   L.push_back(p3);
   L.push_back(p4);
   L.push_back(p5);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"姓名："<<(*it).m_Name
              <<" 年龄 ："<<it->m_Age
              <<" 身高 ："<<it->m_Height<<endl;
   }
   //排序
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------排序后---------------"<<endl;
   L.sort(comparePerson);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"姓名："<<(*it).m_Name
              <<" 年龄 ："<<it->m_Age
              <<" 身高 ："<<it->m_Height<<endl;
   }
}
int main()
{
    test();
    system("pause");
    return 0;
}   
```

### 2.7 set/multiset容器

基本概念

* 所有元素都会在插入时自动被排序

本质

* set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别

* set 不允许容器中有重复的元素
* multiset允许容器中有重复的元素

#### set构造和赋值

代码示例

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
//set容器构造和赋值
void test()
{
    set<int>s;
    //插入数据，只能用insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //遍历容器
    //set容器特点，所有元素插入时候自动排序
    //set容器不允许插入重复值
    printSet(s);
    //拷贝构造
    set<int>s2(s);
    printSet(s2);
    //赋值
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

#### set大小和交换

功能描述

* 统计set容器以及交换set容器

函数原型

* size();     //返回容器中元素的数目
* empty();    //判断容器是否为空
* swap();      //交换两个集合容器

代码示例

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
//set容器大小和交换
//大小
void size()
{
    set<int>s;
    //插入数据，只能用insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //打印容器
    printSet(s);
    //判断是否为空
    if (s.empty())
    {
        cout<<"s为空"<<endl;
    }
    else
    {
        cout<<"s不为空"<<endl;
        cout<<"s的大小"<<s.size()<<endl;
    }
}
//交换
void exchange()
{
    set<int>s;
    //插入数据，只能用insert方式
    set<int>s1;
    //插入数据，只能用 insert方式
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
    cout<<"交换前："<<endl;
    printSet(s);
    printSet(s1);
    s1.swap(s);
    cout<<"交换后："<<endl;
    printSet(s);
    printSet(s1);
}
```

#### set插入和删除

功能描述

* set容器进行插入数据和删除数据

函数原型

* insert(elem);             //在容器中插入元素
* clean();                     //清除所有元素
* erase(pos);               //删除pos迭代器所指的元素，返回下一个元素的迭代器
* erase(beg, end);       //删除区间[beg, end]的所有元素，返回下一个元素的迭代器
* erase(elem);             //删除容器中值为elem的元素

代码示例

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
    //插入
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    //遍历
    printSet(s);
    //删除
    s.erase(s.begin());
    printSet(s);
    //删除重载版本
    s.erase(30);
    printSet(s);
    //清空
    //s.erase(s.begin(), s.end());
    s.clear();
    printSet(s);
}
```

* 插入  ---insert
* 删除  ---erase
* 清空  ---clear

####set查找和统计

功能描述

* 对set容器进行查找数据以及统计数据

函数原型

* find(key);    //查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回set.end();
* count(key);   //统计key的元素个数

代码示例

```C++
//set容器查找和统计
void test01()
{
    set<int>s;
    //插入数据，只能用insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //查找
    set<int>:: iterator pos =s.find(30);
    if (pos!=s.end())
    {
        cout<<"找到元素："<<endl;
    }
}
void test02()
{
    //查找
    set<int>s;
    //插入数据
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //统计30的个数
    int num=s.count(30);
    cout<<"个数："<<num<<endl;
}
```  
#### set和multiset区别
学习目标
* 掌握set和multiset的区别
区别
* set不可以插入重复数据，而multiset可以
* set插入数据的同时会返回插入结果，因此可以插入重复数据
代码示例
```C++
//set和mutiset区别
void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret=s.insert(10);
    if (ret.second)
    {
        cout<<"第一次插入成功"<<endl;
    }
    else
    {
        cout<<"第一次插入失败"<<endl;
    }
    ret=s.insert(10);
     if (ret.second)
    {
        cout<<"第一次插入成功"<<endl;
    }
    else
    {
        cout<<"第一次插入失败"<<endl;
    }
    multiset<int>ms;
    //允许插入重复值
    ms.insert(10);
    ms.insert(10);
    for (set<int>::iterator it=ms.begin(); it!=ms.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
```  
#### pair对组创建  
 功能描述  
* 成对出现的数据，利用对组可以返回两个数据
两种创建方式
* pair<type, type>p(valuel, value);
* pair<type, type>p=make_pair(value1, value2);
代码示例
```C++
void test()
{
    //第一种方式
    pair<string,int>p1("Ton", 20);
    cout<<"姓名："<<p1.first<<"年龄："<<p1.second<<endl;
    //第二种方式
    pair<string, int>p2=make_pair("jenrry", 10);
    cout<<"姓名："<<p2.first<<"年龄："<<p2.second<<endl;
}
```
#### set容器排序
* set容器默认排序规则为从小到大，掌握如何改变排序规则
* 利用仿函数，可以改变排序规则
代码示例
```C++
/定义set容器排序规则
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        //降序
        return v1>v2;
    }
};
//set容器  排序案例  对于内置数据类型  做排序
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
//set 容器自定义数据类型进行排序，按照年龄进行升序，如果年龄相同按照身高进行降序
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
        //按照年龄，升序
        return p1.m_Height>p2.m_Height;
    }
};
void test02()
{
   set<Person, ComparePerosn> s;
   //数据填入
   Person p1("刘备", 35, 163);
   Person p2("张飞", 39, 168); 
   Person p3("关羽", 34, 176);
   Person p4("曹操", 41, 170);
   Person p5("周瑜", 43, 180);
   Person p6("赵云", 35, 178);
   //弹入容器
   s.insert(p1);
   s.insert(p2);
   s.insert(p3);
   s.insert(p4);
   s.insert(p5);
      //排序
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------排序后---------------"<<endl;
   for (set<Person, ComparePerosn>:: iterator it=s.begin(); it!=s.end(); it++)
   {
       cout<<"姓名："<<(*it).m_Name
              <<" 年龄 ："<<it->m_Age
              <<" 身高 ："<<it->m_Height<<endl;
   }
}
```  
### 2.8map容器
#### map基本概念  
简介
* map中所有元素是pair
* pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
* 所有元素都会根据元素的键值自动排序
 本质  
* map/multimap属于关联式容器，底层结构是用二叉树实现。
优点  
* 可以根据key值快速找到value值，map和multimap区别：map不允许容器中有重复key值元素
* multimap允许容器中有重复key值元素
####12.2 map构造和赋值
功能描述
* 对map容器进行构造和赋值操作
函数原型
* map<T1, T2>mp;     //map构造函数
* map(const map &mp);  //拷贝构造函数
 赋值
* map& operator=(const, map&mp);   //重载等号操作符
代码示例
```C++
void test01()
{
    //创建map容器
    map<int, int>m;
    m.insert(pair<int, int>(90, 80));
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(30, 40));
    m.insert(pair<int, int>(50, 60));
    printMap(m);
    //拷贝构造
    map<int, int>m2(m);
    printMap(m2);
    //赋值
    map<int, int>m3;
    m3=m2;
    printMap(m3);
}
```
#### map大小和交换  
功能描述  
* 统计map容器大小以及交换map容器
函数原型
* size();       //返回容器中元素的数目
* empty();   //判断容器是否为空
* swap(st);  //交换两个容器
代码示例
```C++
//map容器大小和交换
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(10, 20));
    m.insert(pair<int, int>(30, 40));
    m.insert(pair<int, int>(50, 60));
    if (m.empty())
    {
        cout<<"m容器为空";
    }
    else
    {
        cout<<"m容器不为空"<<m.size()<<endl;
    }
    printMap(m);
    map<int, int>m1;
    m1.insert(pair<int, int>(12, 13));
    m1.insert(pair<int, int>(14, 15));
    m1.insert(pair<int, int>(16, 17));
    m1.insert(pair<int, int>(18, 19));
    cout<<"交换前"<<endl;
    m1.swap(m);
    printMap(m);
    printMap(m1);
}
```
#### map插入和删除  
功能描述  
* map容器进行插入数据和删除数据  
函数原型  
* insert(elem);            //在容器中插入元素
* clean();                    //清除所有元素
* erasre(pos);             //删除pos迭代器所指的元素，返回下一个元素的迭代器
* erase(beg, end);      //删除区间[beg, end]的所有元素，返回下一个元素的迭代器
* erase(key);               //删除容器中值为key的元素
代码示例
```C++
//map容器  插入和删除
void test()
{
    map<int, int>m;
    //插入1
    m.insert(pair<int, int>(1,10));
    //插入2
    m.insert(make_pair(2,10));
    //插入3
    m.insert(map<int, int>::value_type(3,10));
    //插入4
    m[2]=40;     //不建议使用
    //删除
    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);
    //清空
    m.erase(m.begin(), m.end());
    m.clear();
}
```  
#### map查找和统计  
功能描述
* 对map容器进行查找数据以及统计数据
函数原型
* find(key);         //查找key是否存在，若存在，返回改键的元素的迭代器；若不存在，返回set.end();
* count(key);      //统计key的元素
代码示例
```C++
void test()
{
    map<int, int>m;
    m.insert(pair<int, int>(12, 13));
    m.insert(pair<int, int>(14, 15));
    m.insert(pair<int, int>(16, 17));
    m.insert(pair<int, int>(18, 19));
    //查找
    map<int, int>::iterator pos=m.find(3);
    if (pos!=m.end())
    {
        cout<<"查到了元素key= "<<(*pos).first<<"value="<<pos->second<<endl;
    }
    else
    {
        cout<<"未找到元素"<<endl;
    }
    //统计
    //map不允许插入重复key元素，count统计而言，结果要么是0，要么是1
    //mutimap的count统计可能大于1
    int num=m.count(13);
    cout<<"num="<<num<<endl;
}
```   
总结
* 查找---find（返回的是迭代器）
* 统计---count（对于map，结果为0或者1）  
#### map容器排序  
* map容器默认排序规则为按照key值进行从小到大排序，掌握如何改变排序规则
主要技术点
* 利用仿函数，可以改变排序规则

代码示例
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
//map容器  排序
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
总结
* 利用仿函数可以指定map容器的排序规则
* 对于自定义数据类型， map必须指定排序规则，同set容器  
#### 案例-员工分组  
案例描述  
* 公司今天招聘了10个员工(ABCDEFGHI)，10名员工进入公司之后，需要指派员工在那个部门工作
* 员工信息：姓名、工资组成；部门分为：策划、美术、研发
* 随机给10名员工分配部门和工资
* 通过multimap进行信息的插入，key(部门编号)value(员工)
* 分部门显示员工信息
实现步骤
1. 创建10名员工，放到vector中
2. 遍历vector容器，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体工作作为value，放到multimap容器中
4. 分部门显示员工信息
案例代码
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
//创建员工
void creat_employee(vector<Employee>&v)
{
    string nameSeed="ABCDEFGHJK";
    for (int i = 0; i < 10; i++)
    {
        string name="员工：";
        name+=nameSeed[i];
        int salary=rand()%5000+10000;   //10000~149999
        Employee e(name,salary);
        v.push_back(e);
    }
}
//分组
void setGroup( vector<Employee>&v, multimap<int, Employee>&m)
{
    for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    {
        int depId=rand()%3;   //产生随机编号
        m.insert(make_pair(depId, *it));
    }
}
//显示员工
void showEmployee(multimap<int, Employee>&m)
{
    cout<<"策划部门："<<endl;
    multimap<int, Employee>::iterator pos=m.find(Scheme); 
    int num=m.count(Scheme);
    int  index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"姓名："<< pos->second.m_Name;
        cout<<"薪资："<<pos->second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"美术部门："<<endl;
    pos=m.find(Fine_arts); 
    num=m.count(Fine_arts);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"姓名："<< (*pos).second.m_Name;
        cout<<"薪资："<<(*pos).second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"研发部门："<<endl;
    pos=m.find(Research_development); 
    num=m.count(Research_development);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"姓名："<< (*pos).second.m_Name;
        cout<<"薪资："<<(*pos).second.m_Salary<<endl;
    }
}
int main()
{
    //1. 创建员工
    vector<Employee>v;
    creat_employee(v);
    // for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"姓名："<<(*it).m_Name;
    //     cout<<"薪水："<<(*it).m_Salary<<endl;
    // }    
    //2. 员工分组
    multimap<int, Employee>m;
    setGroup(v, m);
    //分组显示员工
    showEmployee(m);
    system("pause");
    return 0;
}
```
## 3. STL-函数对象
### 3.1 函数对象
#### 基本概念
* 重载函数调用操作符的类，其对象称为函数对象
* 函数对象使用重载，行为类似函数调用，也叫仿函数
#### 本质  
函数对象(仿函数)是一个类，不是一个函数
#### 函数对象使用  
特点：  
* 函数对象在使用，可以像普通函数那样调用，可以有参数，可以返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递
#### 代码示例  
```C++
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return  v1+v2;
    }
};
//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
    MyAdd myadd;
    cout<<myadd(10, 10)<<endl;
}
//2. 函数对象超出普通函数的概念，可以有自己的状态
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
    int count;  //内部状态
};
void test02()
{
    myPrint myprint;
    myprint("hello world");
    myprint("hello world");
    cout<<"myprint调用次数"<<myprint.count<<endl;
}
//函数对象可以作为参数传递
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
### 3.2 谓词
#### 基本概念
* 返回bool类型的仿函数称为谓词
* 如果operator()接受一个参数，那么叫做一元谓词
* 如果operator()接受两个参数，那么叫做二元谓词
####  一元谓词(示例)
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
    //GreaterFive()   //匿名函数对象
    vector<int>::iterator it=find_if(v.begin(), v.end(), GreatFive());
    if (it==v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"已找到"<<*it<<endl;
    }    
}  
```
####  二元谓词
```C++
//二元谓词
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
    //GreaterFive()   //匿名函数对象
   sort(v.begin(), v.end(), myCompare());
   for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
```  
###3.3 内建函数对象  
#### 内建函数对象意义
概念  
* STL内建了一些函数对象  
分类  
* 算数仿函数
* 关系仿函数
* 逻辑仿函数
用法  
* 仿函数所产生的对象，用法和一般函数完全相同
* 使用内建函数对象，需要引入头文件#include<functional>
#### 算数仿函数
功能描述
* 实现四则运算
* 其中negative是一元运算，其他都是二元运算
仿函数原型
* template<class T> T plus<T>          //加法仿函数
* template<class T>T minus<T>        //减法仿函数  
* template<class T>T multiplies<T>  //乘法仿函数
* template<class T>T divides<T>      //除法仿函数
* template<class T>T modulus<T>   //取模仿函数
* template<class T>T negate<T>      //取反仿函数
代码示例
```C++
/内建函数对象，算术仿函数
//negate  一元仿函数 ，取反 仿函数
void test()
{
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus 二元仿函数  加法
void test01()
{
    plus<int>p;
    cout<<p(2, 3)<<endl;
}
```
#### 关系仿函数
功能描述
* 实现关系对比
仿函数原型
* template<class T> bool equal_to<T>                         //等于
* template<class T>bool note_equal_to<T>                //不等于
* template<class T>bool greater<T>                           //大于
* template<class T>bool greater_equal<T>                //大于等于
* template<class T>bool less<T>                                //小于
* template<class T>bool less_equal<T>                    //小于等于
代码示例
```C++
//内建函数对象，_算术仿函数
//大于 greater
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
    //降序
    //sort(v.begin(), v.end(), MyCompare)；
    //greater<int>() 内建函数
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
```
总结：关系仿函数中最常用的就是greater<>大于
#### 逻辑仿函数
功能描述
* 实现逻辑运算
函数运算
* template<class T>bool logical_and<T>    //逻辑与
* template<class T>bool logicla_or<T>      //逻辑或
* template<class T>bool logical_not<T>    //逻辑非
代码示例
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
    //利用逻辑非、将容器v搬运到容器v2中，并执行取反操作
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
## 4. STL-常用算法
概述：
* 算法主要是由头文件<algorithm>、<functional>、<numeric>
### 4.1 常用遍历算法
#### for_each 
功能描述：
* 实现遍历容器
函数原型：
* for_each(iterator beg, iterator end, func)
  //遍历算法 遍历容器元素
  //beg 开始迭代器
  //end  结束迭代器
  // _func 函数或者函数对象
代码示例：
```C++
//常用遍历算法 for_each
//普通函数
void print01(int val)
{
    cout<<val<<" ";
}
//仿函数
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
功能描述
* 搬运容器到另一个容器中
函数原型
* transform(iterator beg1, iterator end1, iterator beg2, func)
  //beg1 源容器开始迭代器
  //end1 源容器结束迭代器
  //beg2 目标容器开始迭代器
  //_func 函数或者函数对象
代码示例
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
### 4.2 常用查找算法
简介：
* find                                       //查找元素
* find_if                                   //按条件查找元素
* adjacent_find                        //查找相邻重复元素
* binary_serach                        //二分查找法
* count                                    //统计元素个数
* count_if                                // 按条件统计元素个数
#### find
算法简介
* 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

函数原型
* find(iterator beg, iterator end, value);
  //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  //beg开始迭代器
  //end结束迭代器
  //value 查找的元素
代码示例
```C++
//find
//查找 内置数据类型
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找容器中，是否有5这个元素
    vector<int>::iterator it=find(v.begin(), v.end( ), 2 );
    if (it==v.end())
    {
        cout<<"没有找到！"<<endl;
    }
    else
    {
        cout<<"找到："<<*it<<endl;
    }
}
//类
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    //重载 ==底层find知道如何对比person数据类型
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
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    vector<Person>::iterator it=find(v.begin(), v.end(), pp);
    if (it==v.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素 姓名："<<it->m_Name<<"年龄："<<it->m_Age<<endl;
    }
}
```
#### find_if
功能描述
* 按条件查找元素  

函数原型
* find_if(iterator beg, iterator end, _Pred);
  //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  //beg开始迭代器
  //end结束迭代器
  // _Pred函数或者谓词(返回bool类性的仿函数)

示例：
```C++
/find_if
// 1.内置数据类型
//谓词
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
    //查找容器中，是否有5这个元素
    vector<int>::iterator it=find_if(v.begin(), v.end( ), sss() );
    if (it==v.end())
    {
        cout<<"没有找到！"<<endl;
    }
    else
    {
        cout<<"找到："<<*it<<endl;
    }
}
//自定义数据类型
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
// 1.内置数据类型
//谓词
class  sss20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age>20;
    }
};
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //找到年龄大于20的人
    vector<Person>::iterator it=find_if(v.begin(), v.end(), sss20());
    if (it==v.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素 姓名："<<it->m_Name<<"年龄："<<it->m_Age<<endl;
    }
}
```
#### adjacent_find
功能描述：
* 查找相邻重复元素

函数原型：
* adjacent_find(iterator beg, iterrator end);
  //查找相邻重复元素，返回相邻元素的第一个位置的迭代器
  //beg开始迭代器
  //end 结束迭代器
示例：
```C++
void test()
{
    vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    vector<int>::iterator it=adjacent_find(v.begin(), v.end());
    if (it==v.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素："<<*it<<endl;
    }
}
```
#### binary_search
功能描述
* 查找指定元素是否存在

函数原型
* bool binary_search(iterator beg, iterator end, value);
  //查找指定元素，查到返回true 否则false
  //注意：在无序序列中不可用
  //beg开始迭代器
  //end结束迭代器
  //value 查找的元素

示例
```C++
void test()
{
    vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    bool it=binary_search(v.begin(), v.end(), 20);
    if (it)
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素："<<endl;
    }
}
```
#### count
统计元素个数
* (iterator beg, iterator end, value)；
  //统计元素出现次数
  //beg 开始迭代器
  //end 结束迭代器
  //value 统计的元素

示例
```C++
//count
//统计个数
//1.内置数据类型
void test()
{
    vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count(v.begin(), v.end(), 20);
    cout<<"元素个数："<<it<<endl;
}
//2. 自定义数据类型
//类
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    //重载 ==底层find知道如何对比person数据类型
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
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("bbb", 20);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    int num=count(v.begin(), v.end(), pp);
    cout<<"元素个数："<<num<<endl;
}
```
#### count_if
* 按条件统计元素个数

函数原型
* count_if(iterator beg, iterator end, _Pred);
  //按条件统计元素出现次数
  //beg开始迭代器
  //end结束迭代器
  //_Pred 谓词

示例
```C++
//常用查找算法   count_if
//统计内置数据类型
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
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count_if(v.begin(), v.end(), Greater());
    cout<<"元素个数："<<it<<endl;
}
//统计自定义数据类型
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
//仿函数
class AgeGreat
{
public:
    bool operator() (const Person & p)
    {
        return p.m_Age>20;
    }
}; 
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("曹操", 30);
    Person p2("周瑜", 20);
    Person p3("孙权", 30);
    Person p4("小乔", 18);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    int num=count_if(v.begin(), v.end(), AgeGreat());
    cout<<"元素个数："<<num<<endl;
}
```
### 4.3 常用排序算法
算法简介
* sort                                           //对容器内元素进行排序
* random_shuffle                        //洗掉   指定范围内的元素随机调整次序
* merge                                       //容器元素合并，并存储到另一个容器内
* reverse                                      //反转指定范围内的元素

#### sort
* 对容器内元素进行排序
* sort(iterator beg, iterator end, _Pred)
  //按值找到元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
  //beg 开始迭代器
  //end 结束迭代器
  // _pred 谓词

示例
```C++
//常用排序算法：sort
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
    //利用sort升序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //降序
    sort(v.begin(), v.end(), greater<int>());
}
```
#### random_shuffle
* 洗牌 指定范围内的元素随机调整次序
* random_shuffle(iterator beg, iterator end);
  //指定范围内的元素随机次序
  //beg 开始迭代器
  //end 结束迭代器

示例
```C++
//常用排序算法：random_shuffle
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
    //利用洗牌、算法、打乱顺序
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //降序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
}
```
#### merge
* 两个容器元素合并，并存储到另一个容器中
* merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 //容器元素合并，并存储到另一个容器中
 //注意：两个容器必须有序的
 //beg1 容器1开始迭代器
 //end1 容器1结束迭代器
 //beg2 容器2开始迭代器
 //end2 容器2结束迭代器
 //dest  目标容器开始迭代器

示例：
```C++
//常用排序算法 merge
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
    //提前给目标容器分配空间
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint());
}
```
#### reverse
  * 将容器内元素进行反转

函数原型：
*reverse(iterator beg, iterator end);
 //反转指定范围的元素
 //beg开始迭代器
 //end 结束迭代器

示例：
```C++
//常用排序算法 merge
void myPrint (int val)
{
        cout<<val<<" ";
}
//reverse算法
void test01()
{
    vector<int>v1;
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    cout<<"反转前："<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<"反转后："<<endl;
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), myPrint);
}
```
### 4.3 常用拷贝和替换算法
* copy     //容器内指定范围内的元素拷贝到另一个容器中
* replace  //将容器指定范围内的旧元素修改为新元素
* replace_if  //容器内指定范围内满足条件的元素替换为新元素
* swap         //互换两个容器的元素
  
#### copy
* 容器内指定范围内的元素拷贝到另一个容器中
* copy(iterator beg, iterator end, iterator dest);
  //按值查找元素，找到返回位置迭代器，找不到返回结束迭代器位置

示例
```C++
using namespace std;
//常用拷贝算法和替换算法
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
* 将容器内指定范围内的旧元素修改为新元素
* replace(iterator beg, iterator end, oldvalue, newvalue);
 //反转指定范围的元素
 //beg开始迭代器
 //end 结束迭代器
//oldvalue 旧元素
//newvalue 新元素

示例
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
    cout<<"替换前："<<endl;
    for_each(v1.begin(), v1.end(), myPrint());
    cout<<"替换后："<<endl;
    replace(v1.begin(), v1.end(), 20, 1000);
    for_each(v1.begin(), v1.end(), myPrint());
}
```
#### replace_if
```C++
//替换算法replace_if
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
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(40);
     cout<<"替换前："<<endl;
    for_each(v.begin(), v.end(), myPrint());
    cout<<"替换后："<<endl;
    replace_if(v.begin(), v.end(), Greater(), 1000);
    for_each(v.begin(), v.end(), myPrint());
}
```
#### swap
* 互换两个容器的元素
* swap(container c1, container c2)
  //互换两个容器的元素
  //c1容器1
  //c2容器2

示例：
```C++
//常用拷贝和替换算法
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
    cout<<"交换前"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<"交换后"<<endl;
    swap(v1, v2);
    cout<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    for_each(v2.begin(), v2.end(), myPrint);
}
```
### 4.4 常用算术生成算法
* 掌握常用的算术生成算法
* 属于小型算法，使用时包含的头文件为 #include<number>
* accumulate    //计算容器元素累计总计
* fill                   //向容器中添加元素

#### accumulate
* 计算区间内 容器元素累计总和
* accumulate(iterator beg, iterator end, value);
  //计算容器元素累计总和
  //beg 开始迭代器
  //end 结束迭代器
  //value起始值

示例：
```C++
//常用算术生成算法
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
* 向容器中填充指定的元素
* fill(iterator beg, iterator end, value);
  //向容器中填充元素
  //beg 开始迭代器
  //end 结束迭代器
  //value起始值

示例：
```C++
//常用算术生成算法 fill
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.resize(10);
    //后期重新填充
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
}
```
### 4.5 常用集合算法
* set_intersection       //求两个容器1的交集
* set_union                 //求两个容器的并集
* set_difference          //求两个容器的差集

#### set_intersection
* 求两个容器的交集
* set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
  //求两个集合的交集

示例：
```C++
//常用集合算法 set_intersection
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
    //目标容器需要提前开辟空间
    //最特殊情况，大容器包含小容器，开辟空间，取小容器的size即可
    vTarget.resize(min(v1.size(), v2.size()));
    //获取交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end
    (),vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout<<endl;
}
```  
总结：
* 求交集的两个集合必须是有序序列
* 目标容器开辟空间需要从两个容器中取小值
* set_intersection返回值既是交集中最后一个元素的位置

#### set_union
* 求两个集合的并集

函数原型：
* * set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
  //求两个集合的并集
 //注意两个集合必须是有序序列
 ```C++
//常用集合算法 set_diffence，求差集
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
    //目标容器需要提前开辟空间
    //最特殊情况，两容器无交集，容器size为两者之和。
    vTarget.resize(max(v1.size(), v2.size()));
    //获取交集
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end
    (),vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout<<endl;
}
```

