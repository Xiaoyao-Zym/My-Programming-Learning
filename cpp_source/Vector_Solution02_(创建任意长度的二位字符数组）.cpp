#include <iostream>
#include <string>
# include<vector>
#include<sstream>
using namespace std;
int main()
{
 vector<int> input;
 string temp;
 vector<vector<int>> matrix;
 while ((getline(cin, temp)) && temp != "") 
 {
     for (int i = 0; i<temp.size(); ++i) 
   {
       int num = 0;
       while (temp[i] != ' '&&temp[i] != '\0')
       {
           num = num * 10 + (temp[i] - '0');
           ++i;
       }
       input.push_back(num);
   }
  matrix.push_back(input);
  input.clear(); //ÿ��ѭ����Ҫ��input�������
 }
 system("pause");
}

