#include<iostream>
#include<string>
using namespace std;
/*****************通用的数组类*******************************
 * 可以对内置数据类型以及自定义数据类型的数据进行存储
 * 将数组中的数据存储到堆区
 * 构造函数中可以传入数组的容量
 * 提供对应的拷贝函数以及 operator=防止浅拷贝问题
 * 提供尾插法和尾删法对数组中的数据进行增加和删除
 * 可以通过下标的方式访问数组中元素
 * 可以获取数组中当前元素个数和数组容量
 ************************************************************/
template<class T>
class MyArray
{
public:
     //有参构造，参数，容量
    MyArray(int capacity)
    {
        cout<<"MyArray有参构造"<<endl;
        this->m_Capacity=capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }
    //拷贝构造
    MyArray(const MyArray &arr)
    {
        cout<<"MyArray拷贝构造"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        //深拷贝
        this->pAddress=new T[arr.m_Capacity];
        //将arr中的数据都拷贝过来
        for (int i = 0; i < this->m_Size;  i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
    }
    //operator=防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {
        //先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress !=NULL)
        {
            delete[] this->pAddress;
            this->pAddress=NULL;
            this->m_Capacity=0;
            this->m_Size=0;
        }
        //深拷贝
         cout<<"MyArray operator=赋值调用 "<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size;  i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
        return *this;
    }
    //尾插法
    void Push_Back(const T&val)
    {
        //判断容量是否等于大小
        if (this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val; //在数组末尾插入数据；
        this->m_Size++; //更新数组大小        
    }
    //尾删除 
    void Pop_Back()
    {
    //让用户访问到最后一个大元素，即为尾删，逻辑删除
         if (this->m_Size==0)
        {
            return;
        }
        this->m_Size--;
    }
    //通过下标方式访问数组中的元素  arr[0]=100
    T& operator[] (int index)
    {
        return this->pAddress[index];
    }
    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }
     //析构函数
    ~MyArray()
    {
        if (this->pAddress!=NULL)
        {
             cout<<"MyArray析构函数调用"<<endl;
            delete []this->pAddress;
            this->pAddress=NULL;
        }
    }
private:
    T *pAddress;   //指针指向堆区开辟的真实数组
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
//测试内置数据类型
void test01()
{
    MyArray<int>arr1(5);
    // MyArray<int>arr3(100);
    // arr3=arr1;
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    cout<<"arr1的打印输出："<<endl;
    printIntArray(arr1);
    cout<<"arr1的大小为："<<arr1.getSize()<<endl;
    cout<<"arr1的容量为："<<arr1.getCapacity()<<endl;
    MyArray<int>arr2(arr1);
    cout<<"arr2的打印输出："<<endl;
    printIntArray(arr2);
    arr2.Pop_Back();
    cout<<"arr2尾删后的大小为："<<arr2.getSize()<<endl;
    cout<<"arr2尾删后的容量为："<<arr2.getCapacity()<<endl;
}
//测试自定义数据类型
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
        cout<<"姓名："<<arr[i].m_Name<<"年龄："<<arr[i].m_Age<<endl;
    }
}
void test02()
{
    MyArray<Person>arr(10);
    Person p1("孙悟空", 500);
    Person p2("猪八戒", 500);
    Person p3("沙和尚", 500);
    Person p4("唐  僧", 500);
    Person p5("白龙马", 500);
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);
    //打印数组
    printPersonArray(arr);
    cout<<"arr1的大小为："<<arr.getSize()<<endl;
    cout<<"arr1的容量为："<<arr.getCapacity()<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
}
