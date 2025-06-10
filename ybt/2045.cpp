// 2045：【例5.13】蛇形填数
#include <iostream>
using namespace std;
int a[100][100];
int main()
{
    int n;
    cin >> n;
    int x = 0, y = n-1;
    int t = 1;
    a[x][y] = 1;
    while (t < n * n)
    {
        while (x+1 < n && a[x + 1][y] == 0)
            a[++x][y] = ++t;
        while (y-1 >= 0 && a[x][y - 1] == 0)
            a[x][--y] = ++t;
        while (x-1 >= 0 && a[x - 1][y] == 0)
            a[--x][y] = ++t;
        while (y+1 < n && a[x][y + 1] == 0)            
            a[x][++y] = ++t;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}