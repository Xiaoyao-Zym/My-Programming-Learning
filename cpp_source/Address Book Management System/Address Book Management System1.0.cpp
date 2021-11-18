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
int* modify_Num()
{
    int t = 1;
    char item[5][10] = { 0 };
    int m = 0, n = 0;
    int num = 0, len = 0;
    char str[5][20] = { {"姓名"},{"性别"},{"年龄"},{"地址"},{"联系电话"} };
    while (t)
    {
        cout << "请输入要修改的项目：" << "姓名，性别，年龄，地址，联系电话" << endl;
        string s;
        getline(cin, s);
        len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] != ' ')
            {
                item[m][n] = s[i];
                n++;
            }
            else
            {
                m++;
                n = 0;
            }
        }
        for (int j = 0; j < m + 1; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(item[j], str[i]) == 0)
                {
                    flag[num] = i;
                    num++;
                    t = 0;
                    break;
                }
            }
        }
        if (num == 0)
        {
            cout << "请输入正确的修改项" << endl;
            t = 1;
        }
    }
    return flag;
    system("pause");
}
void modify(struct Address_Books* abs, int i, string name_Old)
{
    int* p = modify_Num();
    int len = sizeof(p) / sizeof(p[0]);
    for (int j = 0; j <len ; j++)
    {
       if (p[j]==0||p[j+1]==0)
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
int is_existPerson(struct Address_Books * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if ( abs->person_Array[i].m_Name==name )
			 return i ;
    }
	return -1;
}
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
          case 5:   modifyPerson(&abs);  break;  //修改联系人
          case 6:
             break; //清空联系人
          case 0:
            {
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break; //退出通讯录
            }
            default:
                break;
        }
    }
    system("pause");
    return 0;
}