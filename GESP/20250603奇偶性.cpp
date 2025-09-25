#include <cstdio>
using namespace std;
int n, v;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int c;
        scanf("%d", &c);
        while (c)
        {
            v += c & 1;         //如果是奇数，就加一
            c >>= 1;            //右移一位
        }
    }
    printf("%d %d\n", v, v & 1);//如果是奇数，就输出1，否则输出0
    return 0;
}