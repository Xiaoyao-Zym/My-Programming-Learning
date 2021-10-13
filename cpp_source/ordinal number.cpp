#include <iostream>
using namespace std;
int main()
{
    long long M = 0, num;  //用int的话可能很有数据溢出问题，当数字过大则程序出错
    cout << "请输入一个若干位的整数：";
    cin >> num;
    int i = 0;  //一定要初始化，这里初始化为1是因为循环一开始就将num去掉了一位数
    while (num != 0)  //数完一位数就去掉一位
    {
        M = M * 10 + num % 10;
        i++;  //计数
        num /= 10;
    }
    cout << "逆序数是：" << M << endl;
    system("pause");
    return 0;
}
