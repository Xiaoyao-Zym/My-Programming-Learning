#include <iostream>
using namespace std;
int main()
{
    long long M = 0, num;  
    cout << "����������";
    cin >> num;
    int i = 0;  
    while (num != 0) 
    {
        M = M * 10 + num % 10;
        i++;  
        num /= 10;
    }
    cout << "�任���������" << M << endl;
    system("pause");
    return 0;
}
