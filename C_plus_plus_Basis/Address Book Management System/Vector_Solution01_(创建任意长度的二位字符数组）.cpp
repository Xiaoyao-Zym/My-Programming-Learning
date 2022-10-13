#include<iostream>
#include<string>
# include<vector>
#include<sstream>
using namespace std;
int main()
{
	string str;
	string num;
	vector<string> v;
	vector<vector<string> >strs;
	while (getline(cin,str))
	{		
		if (str.size() == 0) break;
		istringstream iss(str);
		while (iss >> num)
		{
			v.push_back(num);
		}
		strs.push_back(v);
		v.clear();
	}
	for (int i = 0; i < strs.size(); ++i)
	{
		for (int j = 0; j < strs[i].size(); ++j)
		{
			cout << strs[i][j] << " ";
		}
		cout << endl;
	}
    system("pause");
}