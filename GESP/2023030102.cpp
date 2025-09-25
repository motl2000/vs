//4002：【GESP2303一级】长方形面积
#include <iostream>
#include <cmath>
using namespace std;
    
int main()
{
    int n;
    cin >> n;
    int count = 0;
    //枚举i, i*i <= n
    for (int i = 1; i * i <= n; i++)
    {
        //如果 n 能被 i 整除，说明 i 可以是长方形的长(宽)，n/i 是宽（长）
        if (n % i == 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}