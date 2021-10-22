#include <iostream>
using namespace std;
int main()
{
    long long M = 0, num;  
    cout << "请输入数字";
    cin >> num;
    int i = 0;  
    while (num != 0) 
    {
        M = M * 10 + num % 10;
        i++;  
        num /= 10;
    }
    cout << "变换后的数字是" << M << endl;
    system("pause");
    return 0;
}
