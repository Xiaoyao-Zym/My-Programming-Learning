#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int flag[5]={0};
int *modify()
{
    int t = 1;
    char item[5][10]={0};
    int m = 0, n = 0;
    int num=0, len =0;
    char str[5][20] = { {"����"},{"�Ա�"},{"����"},{"��ַ"},{"��ϵ�绰"} };
    while (t)
    {
        cout << "������Ҫ�޸ĵ���Ŀ��" << "�������Ա����䣬��ַ����ϵ�绰" << endl;
        string s;
        getline(cin, s);
         len = s.size();
        for (int  i = 0; i < len; i++)
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
        for (int j = 0; j < m+1; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(item[j],str[i])==0)
                        {
                             flag[num] = i;
                             num++ ;
                             t=0;
                             break;
                        }
            }
          }              
        if (num==0)
                    {
                    cout << "��������ȷ���޸���" << endl;
                    t=1;
                    }
    }
    return flag;
    system("pause");
}
int main()
{
    int *p=modify();
    int len=sizeof(p)/sizeof(p[0]);
    cout<<len<<endl;
     system("pause");
}