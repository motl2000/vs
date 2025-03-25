//我要写一个通过按键盘输入然后电脑发声的程序
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
int main()
{
    //判断一个数是否为完全平方数
    int n;
    int t=int (sqrt(n));
    if(t*t==n)
    {
        //n是完全平方数
    }

    char ch;
    while (1)
    {
        ch = _getch();
        cout << ch << endl;
        Beep(1000, 100);
    }
    return 0;
}