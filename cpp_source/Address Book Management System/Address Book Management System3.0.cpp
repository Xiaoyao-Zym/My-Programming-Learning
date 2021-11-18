#include<iostream>
#include<string>
#include<string.h>
#define max 1000
using namespace std;
int flag[5] = { 0 };
//创建联系人结构体
struct Person
{
    string   m_Name;          //姓名
    int        m_Gender;        //性别，1：男，2：女
    int        m_Age;             //年龄
    string   m_Address;       //住址
    string   m_Phone;          //联系电话
};
//创建通讯录结构体
struct Address_Books
{
    //创建通讯录中保存的联系人数组
    struct Person  person_Array[max];
    //通讯录中保存的人数
    int m_Size;
};

//添加联系人
void addPerson(struct Address_Books* abs)
{
	//判断通讯录已存在人数
	if (abs->m_Size < max)
	{
		//输入姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->person_Array[abs->m_Size].m_Name = name;
		//输入性别
		while (true)
		{
			int sex = 0;
			cout << "请输入联系人性别：" << "1：男，2：女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_Array[abs->m_Size].m_Gender = sex;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				continue;
			}
		}
		//输入年龄
		int age = 0;
		cout << "请输入联系人年龄：" << endl;
		cin >> age;
		abs->person_Array[abs->m_Size].m_Age = age;
		//输入地址
		string address;
		cout << "请输入联系人地址：" << endl;
		cin >> address;
		abs->person_Array[abs->m_Size].m_Address = address;
		//输入联系电话
		string phone;
		cout << "请输入联系人电话：" << endl;
		cin >> phone;
		abs->person_Array[abs->m_Size].m_Phone = phone;
		//更新通讯录人数
		abs->m_Size++;
		cout << "新建联系人成功" << endl;
		system("pause");
		system("cls");   //清屏操作
	}
	else
	{
		cout << "抱歉，通讯录已满，无法新建联系人" << endl;
		return;
	}
}

//菜单栏显示
void showMenu()
{
    cout << "****************************************"<< endl;
    cout << "******" << "1. 添加联系人" << "******" << endl;
    cout << "******" << "2. 显示联系人" << "******" << endl;
    cout << "******" << "3. 删除联系人" << "******" << endl;
    cout << "******" << "4. 查找联系人" << "******" << endl;
    cout << "******" << "5. 修改联系人" << "******" << endl;
    cout << "******" << "6. 清空联系人" << "******" << endl;
    cout << "******" << "0. 退出通讯录" << "******" << endl;
    cout << "****************************************"<< endl;
}

//显示联系人
void showPerson(struct Address_Books* abs)
{
	if (abs->m_Size!=0)
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->person_Array[i].m_Name << '\t';
			cout << "性别：" <<( abs->person_Array[i].m_Gender ==1 ?"男" :"女")<<'\t';
			cout << "年龄：" << abs->person_Array[i].m_Age << '\t';
			cout << "地址：" << abs->person_Array[i].m_Address << '\t';
			cout << "联系电话：" << abs->person_Array[i].m_Phone << endl;
		}
	}
	else
	{
		cout << "通讯录中无联系人，请添加联系人" << endl;
	}
	system("pause");
	system("cls");
}
int is_existPerson(struct Address_Books * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if ( abs->person_Array[i].m_Name==name )
			 return i ;
    }
	return -1;
}

//删除联系人
void deletePerson(struct Address_Books* abs)
{
    cout << "请输入要删除的联系人姓名" << endl;
    string name;
    cin >> name;
    if (is_existPerson(abs, name) != -1)
    {
        for (int i = is_existPerson(abs, name); i < abs->m_Size; i++)
        {
            abs->person_Array[i].m_Name    =  abs->person_Array[i + 1].m_Name;
            abs->person_Array[i].m_Gender  =  abs->person_Array[i + 1].m_Gender;
            abs->person_Array[i].m_Age       =  abs->person_Array[i + 1].m_Age;
            abs->person_Array[i].m_Address =  abs->person_Array[i + 1].m_Address;
            abs->person_Array[i].m_Phone    =  abs->person_Array[i + 1].m_Phone;
            abs->m_Size--;
            cout << "联系人删除成功" << endl;
        }
    }
    else
    {
        cout << "未找到该联系人" << endl;
    }
    system("pause");
    system("cls");   //清屏操作
}

//查找联系人
void searchPerson(struct Address_Books* abs)
{
    cout << "请输入要查找的联系人姓名" << endl;
    string name;
    cin >> name;
    int i = is_existPerson(abs, name);
    if (is_existPerson(abs, name) != -1)
    {
        cout << "姓名：" << abs->person_Array[i].m_Name << '\t';
        cout << "性别：" << (abs->person_Array[i].m_Gender == 1 ? "男" : "女") << '\t';
        cout << "年龄：" << abs->person_Array[i].m_Age << '\t';
        cout << "地址：" << abs->person_Array[i].m_Address << '\t';
        cout << "联系电话：" << abs->person_Array[i].m_Phone << endl;
    }
    else
    {
        cout << "查无此人";
    }
    system("pause");
    system("cls");   //清屏操作
}

//判断修改项
int* modify_Num()
{
    int m = 0, num = 0;
    string str[5] = { {"姓名"},{"性别"},{"年龄"},{"地址"},{"联系电话"} };
    string s[5];
    cout << "请输入要修改的项目：" << "姓名，性别，年龄，地址，联系电话" << endl;
    while (true)
    {
        for (int i = 0; ; i++)       //输入修改项，空格隔开，回车结束
        {
            cin >> s[i];
            num++;                //记录有效输入的次数
            if (getchar() == '\n')
                break;
        }
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (s[i]==str[j])
                {
                    flag[m]=j;
                    m++;
                }
            }
        }
        if (m != 0)
        {
            break;
        }
        else
        {
            cout << "输入项错误！！请重新输入："<<endl;
        }
    }
    return flag;
    system("pause");
}
//修改联系人各项信息
void modify(struct Address_Books* abs, int i, string name_Old)
{
    int* p = modify_Num();
    int len = sizeof(p) / sizeof(p[0]);
    for (int j = 0; j <len ; j++)
    {
       if (p[j]==0&&p[j+1]==0)
       {
          j=len;
       }
       else
       {
            switch (p[j])
            {  
                case 0:   //修改姓名
                {
                    cout << "请输入新姓名" << endl;
                    string name_New;
                    cin >> name_New;
                    abs->person_Array[i].m_Name = name_New;
                    cout << name_Old << "的姓名：" << name_New << "修改成功" << endl;
                    break;
                }
                case 1:   //修改性别
                {
                    cout << "请输入" << name_Old << "的性别，1：男，2：女" << endl;
                    int gender_New;
                    cin >> gender_New;
                    abs->person_Array[i].m_Gender = gender_New;
                    cout << name_Old << "的性别：" << (gender_New == 1 ? "男" : "女") << "修改成功" << endl;
                    break;
                }
                case 2:    //修改年龄
                {
                    cout << "请输入新的年龄" << endl;
                    int age_New;
                    cin >> age_New;
                    abs->person_Array[i].m_Age = age_New;
                    cout << name_Old << "的年龄：" << age_New << "修改成功" << endl;
                    break;
                }
                case 3:    //修改地址
                {
                    cout << "请输入新的地址" << endl;
                    string address_New;
                    cin >> address_New;
                    abs->person_Array[i].m_Address = address_New;
                    cout << name_Old << "的地址：" << address_New << "修改成功" << endl;
                    break;
                }
                case 4:    //修改联系电话
                {
                   cout << "请输入新的联系电话" << endl;
                   string phone_New;
                   cin >> phone_New;
                   abs->person_Array[i].m_Phone = phone_New;
                   cout << name_Old << "的联系电话：" << phone_New << "修改成功" << endl;
                   break;
                }
                default:    break;
            }
        }
    }
}
//修改联系人
void modifyPerson(struct Address_Books* abs)
{
    cout << "请输入要修改的联系人姓名" << endl;
    string name_Old;
    cin >> name_Old;
    int i = is_existPerson(abs, name_Old);
    if (i != -1)
    {
        modify(abs, i, name_Old);
    }
    else
    {
        cout << "查无此人";
    }
    system("pause");
    system("cls");   //清屏操作
}

//清空联系人
void cleanPerson(Address_Books* abs)
{ 
	cout << "请再次确认是否清空联系人, 1：清空，0：不清空" << endl;
    int i;
    cin >> i;
    if (i !=0)
    {
        abs->m_Size = 0;
        cout << "通讯录已空" << endl;
    }
    system("pause");
    system("cls");
}

//主函数
int main()
{
    //创建通讯录结构体变量
    struct Address_Books abs;
    //初始化通讯录结构体变量abs
    abs.m_Size = 0;
    while (true)
    {
        int slect = 0;      //用户选择
        showMenu();//菜单调用加载
        cin >> slect;
        switch (slect)
        {
            case 1:   addPerson(&abs);       break;  //添加联系人
            case 2:   showPerson(&abs);     break;  //显示联系人
            case 3:   deletePerson(&abs);   break;  //删除联系人
            case 4:   searchPerson(&abs);   break;  //查找联系人
            case 5:   modifyPerson(&abs);  break;  //修改联系人
            case 6:   cleanPerson(&abs);     break;  //清空联系人
            case 0:
            {
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break; //退出通讯录
            }
            default:   break;
        }
    }
    system("pause");
    return 0;
}