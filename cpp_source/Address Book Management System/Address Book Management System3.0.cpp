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

//�����ϵ��
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

//�˵�����ʾ
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

//��ʾ��ϵ��
void showPerson(struct Address_Books* abs)
{
	if (abs->m_Size!=0)
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->person_Array[i].m_Name << '\t';
			cout << "�Ա�" <<( abs->person_Array[i].m_Gender ==1 ?"��" :"Ů")<<'\t';
			cout << "���䣺" << abs->person_Array[i].m_Age << '\t';
			cout << "��ַ��" << abs->person_Array[i].m_Address << '\t';
			cout << "��ϵ�绰��" << abs->person_Array[i].m_Phone << endl;
		}
	}
	else
	{
		cout << "ͨѶ¼������ϵ�ˣ��������ϵ��" << endl;
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

//ɾ����ϵ��
void deletePerson(struct Address_Books* abs)
{
    cout << "������Ҫɾ������ϵ������" << endl;
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
            cout << "��ϵ��ɾ���ɹ�" << endl;
        }
    }
    else
    {
        cout << "δ�ҵ�����ϵ��" << endl;
    }
    system("pause");
    system("cls");   //��������
}

//������ϵ��
void searchPerson(struct Address_Books* abs)
{
    cout << "������Ҫ���ҵ���ϵ������" << endl;
    string name;
    cin >> name;
    int i = is_existPerson(abs, name);
    if (is_existPerson(abs, name) != -1)
    {
        cout << "������" << abs->person_Array[i].m_Name << '\t';
        cout << "�Ա�" << (abs->person_Array[i].m_Gender == 1 ? "��" : "Ů") << '\t';
        cout << "���䣺" << abs->person_Array[i].m_Age << '\t';
        cout << "��ַ��" << abs->person_Array[i].m_Address << '\t';
        cout << "��ϵ�绰��" << abs->person_Array[i].m_Phone << endl;
    }
    else
    {
        cout << "���޴���";
    }
    system("pause");
    system("cls");   //��������
}

//�ж��޸���
int* modify_Num()
{
    int m = 0, num = 0;
    string str[5] = { {"����"},{"�Ա�"},{"����"},{"��ַ"},{"��ϵ�绰"} };
    string s[5];
    cout << "������Ҫ�޸ĵ���Ŀ��" << "�������Ա����䣬��ַ����ϵ�绰" << endl;
    while (true)
    {
        for (int i = 0; ; i++)       //�����޸���ո�������س�����
        {
            cin >> s[i];
            num++;                //��¼��Ч����Ĵ���
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
            cout << "��������󣡣����������룺"<<endl;
        }
    }
    return flag;
    system("pause");
}
//�޸���ϵ�˸�����Ϣ
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
//�޸���ϵ��
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

//�����ϵ��
void cleanPerson(Address_Books* abs)
{ 
	cout << "���ٴ�ȷ���Ƿ������ϵ��, 1����գ�0�������" << endl;
    int i;
    cin >> i;
    if (i !=0)
    {
        abs->m_Size = 0;
        cout << "ͨѶ¼�ѿ�" << endl;
    }
    system("pause");
    system("cls");
}

//������
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
            case 2:   showPerson(&abs);     break;  //��ʾ��ϵ��
            case 3:   deletePerson(&abs);   break;  //ɾ����ϵ��
            case 4:   searchPerson(&abs);   break;  //������ϵ��
            case 5:   modifyPerson(&abs);  break;  //�޸���ϵ��
            case 6:   cleanPerson(&abs);     break;  //�����ϵ��
            case 0:
            {
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;
                break; //�˳�ͨѶ¼
            }
            default:   break;
        }
    }
    system("pause");
    return 0;
}