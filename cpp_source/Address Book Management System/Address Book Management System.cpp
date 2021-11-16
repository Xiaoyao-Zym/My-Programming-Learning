#include<iostream>
#include<string>
#include<string.h>
#define max 1000
using namespace std;
int flag[5] = { 0 };
//������ϵ�˽ṹ��
struct Person
{
    string   m_Name;          //����
    int        m_Gender;        //�Ա�1���У�2��Ů
    int        m_Age;             //����
    string   m_Address;       //סַ
    string   m_Phone;          //��ϵ�绰
};
//����ͨѶ¼�ṹ��
struct Address_Books
{
    //����ͨѶ¼�б������ϵ������
    struct Person  person_Array[max];
    //ͨѶ¼�б��������
    int m_Size;
};
void addPerson(struct Address_Books* abs)
{
	//�ж�ͨѶ¼�Ѵ�������
	if (abs->m_Size < max)
	{
		//��������
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->person_Array[abs->m_Size].m_Name = name;
		//�����Ա�
		while (true)
		{
			int sex = 0;
			cout << "��������ϵ���Ա�" << "1���У�2��Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_Array[abs->m_Size].m_Gender = sex;
				break;
			}
			else
			{
				cout << "�����������������" << endl;
				continue;
			}
		}
		//��������
		int age = 0;
		cout << "��������ϵ�����䣺" << endl;
		cin >> age;
		abs->person_Array[abs->m_Size].m_Age = age;
		//�����ַ
		string address;
		cout << "��������ϵ�˵�ַ��" << endl;
		cin >> address;
		abs->person_Array[abs->m_Size].m_Address = address;
		//������ϵ�绰
		string phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phone;
		abs->person_Array[abs->m_Size].m_Phone = phone;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "�½���ϵ�˳ɹ�" << endl;
		system("pause");
		system("cls");   //��������
	}
	else
	{
		cout << "��Ǹ��ͨѶ¼�������޷��½���ϵ��" << endl;
		return;
	}
}
int* modify_Num()
{
    int t = 1;
    char item[5][10] = { 0 };
    int m = 0, n = 0;
    int num = 0, len = 0;
    char str[5][20] = { {"����"},{"�Ա�"},{"����"},{"��ַ"},{"��ϵ�绰"} };
    while (t)
    {
        cout << "������Ҫ�޸ĵ���Ŀ��" << "�������Ա����䣬��ַ����ϵ�绰" << endl;
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
            cout << "��������ȷ���޸���" << endl;
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
                case 0:   //�޸�����
                {
                    cout << "������������" << endl;
                    string name_New;
                    cin >> name_New;
                    abs->person_Array[i].m_Name = name_New;
                    cout << name_Old << "��������" << name_New << "�޸ĳɹ�" << endl;
                    break;
                }
                case 1:   //�޸��Ա�
                {
                    cout << "������" << name_Old << "���Ա�1���У�2��Ů" << endl;
                    int gender_New;
                    cin >> gender_New;
                    abs->person_Array[i].m_Gender = gender_New;
                    cout << name_Old << "���Ա�" << (gender_New == 1 ? "��" : "Ů") << "�޸ĳɹ�" << endl;
                    break;
                }
                case 2:    //�޸�����
                {
                    cout << "�������µ�����" << endl;
                    int age_New;
                    cin >> age_New;
                    abs->person_Array[i].m_Age = age_New;
                    cout << name_Old << "�����䣺" << age_New << "�޸ĳɹ�" << endl;
                    break;
                }
                case 3:    //�޸ĵ�ַ
                {
                    cout << "�������µĵ�ַ" << endl;
                    string address_New;
                    cin >> address_New;
                    abs->person_Array[i].m_Address = address_New;
                    cout << name_Old << "�ĵ�ַ��" << address_New << "�޸ĳɹ�" << endl;
                    break;
                }
                case 4:    //�޸���ϵ�绰
                {
                   cout << "�������µ���ϵ�绰" << endl;
                   string phone_New;
                   cin >> phone_New;
                   abs->person_Array[i].m_Phone = phone_New;
                   cout << name_Old << "����ϵ�绰��" << phone_New << "�޸ĳɹ�" << endl;
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
    cout << "������Ҫ�޸ĵ���ϵ������" << endl;
    string name_Old;
    cin >> name_Old;
    int i = is_existPerson(abs, name_Old);
    if (i != -1)
    {
        modify(abs, i, name_Old);
    }
    else
    {
        cout << "���޴���";
    }
    system("pause");
    system("cls");   //��������
}
void showMenu()
{
    cout << "****************************************"<< endl;
    cout << "******" << "1. �����ϵ��" << "******" << endl;
    cout << "******" << "2. ��ʾ��ϵ��" << "******" << endl;
    cout << "******" << "3. ɾ����ϵ��" << "******" << endl;
    cout << "******" << "4. ������ϵ��" << "******" << endl;
    cout << "******" << "5. �޸���ϵ��" << "******" << endl;
    cout << "******" << "6. �����ϵ��" << "******" << endl;
    cout << "******" << "0. �˳�ͨѶ¼" << "******" << endl;
    cout << "****************************************"<< endl;
}
int main()
{
    //����ͨѶ¼�ṹ�����
    struct Address_Books abs;
    //��ʼ��ͨѶ¼�ṹ�����abs
    abs.m_Size = 0;
    while (true)
    {
        int slect = 0;      //�û�ѡ��
        showMenu();//�˵����ü���
        cin >> slect;
        switch (slect)
        {
          case 1:   addPerson(&abs);       break;  //�����ϵ��
          case 5:   modifyPerson(&abs);  break;  //�޸���ϵ��
          case 6:
             break; //�����ϵ��
          case 0:
            {
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;
                break; //�˳�ͨѶ¼
            }
            default:
                break;
        }
    }
    system("pause");
    return 0;
}