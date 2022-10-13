#include<iostream>
#include<string>
#include<string.h>
#define max 1000

using namespace std;
int new_len = 0;

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

//去除数组中的0
int* delete_zero(int arr[],int len)
{
    for (int i = 0;; i++)
    {
        if (arr[i] == 0)
        {
            break;
        }
        new_len++;
    }
    //cout << "new_len 的值为："<<new_len << endl;
    int* new_arr = new int[new_len];
    for (int j = 0; j < new_len; j++)
    {
        if (arr[j] == 0)
        {
            break;
        }
        new_arr[j] = arr[j];
    }
   /* cout << "new_arr[]内容为：";
    for (int j = 0; j < new_len; j++)
    {
        cout << new_arr[j] << "\t";
    }
    cout << endl;*/

    return new_arr;
    delete [new_len] new_arr;
}

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

//输入要修改的项目，返回一个数组，数组中存放修改项目的序号
int* modify_Num()
{
    int m = 0;
    int count = 0;
    int flag1[5] = { 0 };  //数组中有0
    int* flag;  //用于接收不含0的新数组
    string str[5] = { "姓名","性别","年龄","地址","联系电话"};
    cout << "请输入要修改的项目：" << "姓名，性别，年龄，地址，联系电话" << endl;
    cout << "（要修改的项目之间用空格隔开，回车开始修改）" << endl;
    string s[5];//输入修改项的数组
    while (true)
    {
        string s[5];//输入修改项的数组
        for (int i = 0;; i++)       //输入修改项，空格隔开，回车结束
        {
            cin >> s[i];
            count++;                //记录有效输入的次数
            if (getchar() == '\n')
                break;
        }
        for (int i = 0; i < 5; i++)  //将有效的序号放入数组flag1中
        {
            for (int j = 0; j < count; j++)
            {
                if (s[j] == str[i])
                {
                    flag1[m] = i+1;    //输入序号数组
                    m++;
                }
            }
        }

      /*  cout << "您输入的修改序号为：";
        for (int j = 0; j < 5; j++)
        {
            cout << flag1[j] << "\t";
        }
        cout << endl;*/

        int len = sizeof(flag1) / sizeof(flag1[0]);

        flag = delete_zero(flag1, len);       //将flag1数组中的0去掉，返回一个新的数组

       /* cout << "flag数组的长度为：" << new_len << endl;
        cout << "您输入的修改序号222为：";
        for (int j = 0; j < new_len; j++)
        {
            cout << flag[j] << "\t";
        }
        cout << endl;*/

        if (m != 0)    
        {
            break;
        }
        else
        {
            cout << "选项有误！！请重新输入：";
        }

        /*
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
        }*/
      /*  if (num == 0)
        {
            cout << "请输入正确的修改项" << endl;
            t = 1;
        }*/
    }
    return flag;
    system("pause");
}
void modify(struct Address_Books* abs, int i, string name_Old)
{
    int* p = modify_Num();
    for (int j = 0; j < new_len ; j++)
    {
        switch (p[j])
        {  
            case 1:   //修改姓名
            {
                cout << "请输入新姓名" << endl;
                string name_New;
                cin >> name_New;
                abs->person_Array[i].m_Name = name_New;
                cout << name_Old << "的姓名：" << name_New << endl;
                break;
            }
            case 2:   //修改性别
            {
                cout << "请输入" << name_Old << "的性别，1：男，2：女" << endl;
                int gender_New;
                cin >> gender_New;
                abs->person_Array[i].m_Gender = gender_New;
                cout << name_Old << "的性别：" << (gender_New == 1 ? "男" : "女") << endl;
                break;
            }
            case 3:    //修改年龄
            {
                cout << "请输入新的年龄" << endl;
                int age_New;
                cin >> age_New;
                abs->person_Array[i].m_Age = age_New;
                cout << name_Old << "的年龄：" << age_New << endl;
                break;
            }
            case 4:    //修改地址
            {
                cout << "请输入新的地址" << endl;
                string address_New;
                cin >> address_New;
                abs->person_Array[i].m_Address = address_New;
                cout << name_Old << "的地址：" << address_New << endl;
                break;
            }
            case 5:    //修改联系电话
            {
                cout << "请输入新的联系电话" << endl;
                string phone_New;
                cin >> phone_New;
                abs->person_Array[i].m_Phone = phone_New;
                cout << name_Old << "的联系电话：" << phone_New << endl;
                break;
            }
            default:    
                break;
        }
        cout << "修改成功！！" << endl;
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