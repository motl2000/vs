// 1377：最优乘车(travel)
//书上用的floyd算法，我用的dijkstra算法，结果一样，但是dijkstra算法更简洁，更高效，更不容易出错
#include <stdio.h>
#include <string.h>
int n, m, i, j, k, x, y;
int s[505], vis[505], mp[505][505];               // s[]存储从1到i的最少乘车次数，vis[]标记是否已访问，mp[][]存储图，站到站的乘车次数
char c;
int main()
{
    scanf("%d%d", &m, &n);
    memset(mp, 1, sizeof(mp));
    for (i = 1; i <= n; i++)                    // 初始化图，所有点之间的距离为无穷大，自己到自己的乘车次数为1
        mp[i][i] = 1;
    for (i = 1; i <= m; i++)                    // 读入m行数据
    {
        k = scanf("%d%c", &s[++j], &c);                     
        if (c == 32 && k == 2)                  // 读入空格
            i--;                                // 重新读入，不算入m，继续读入这一行
        else                                    // 读入回车
        {
            for (x = 1; x < j; x++)             
            {
                for (y = x + 1; y <= j; y++)
                {
                    mp[s[x]][s[y]] = 1;         // 同一条线路两站之间的乘车次数为1
                }
            }
            j = 0;
        }
    }
    memcpy(s, mp[1], sizeof(s));                // 初始化s[]，存储1号站到各站的乘车次数
    for (i = 2; i <= n; i++)                    // Dijkstra算法
    {
        k = 0;
        for (j = 2; j <= n; j++)
        {
            if (s[j] < s[k] && vis[j] == 0) 
                k = j;
        }
        if (k == 0)
            break;
        vis[k] = 1;
        for (j = 2; j <= n; j++)
        {
            if (s[k] + mp[k][j] < s[j])         // 如果两个站可以连通，且乘车次数更少
            {
                s[j] = s[k] + mp[k][j];
            }
        }
    }

    if (s[n] == s[0])                           // 如果终点不可达
        printf("NO\n");

    else
        printf("%d\n", s[n] - 1);               //由于s[1]为1，所以输出第n站的乘车次数减1

    return 0;
}
