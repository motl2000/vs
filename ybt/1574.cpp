//1574：矩阵取数游戏
#include <bits/stdc++.h>

using namespace std;

const int MAXN=81;

inline void input(__int128 &s)
{
    s=0;
    char c=' ';
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
}

inline void output(__int128 x)
{
    if(x>9)
        output(x/10);
    putchar(x%10+'0');
}

int n, m;
__int128 game[MAXN][MAXN];

__int128 f[MAXN][MAXN];//f[i][j]表示从i到j的最大值 
__int128 solve(__int128 a[])
{
    memset(f,0,sizeof(f));
    for(int len=0;len<=m;++len)//len表示长度 
    	for(int i=1;i+len<=m;++i)//i表示起点 
            f[i][i+len]=max(2*f[i+1][i+len]+2*a[i]// 取a[i]，剩下的区间[i+1,i+len]中每个数都翻倍
                ,2*f[i][i+len-1]+2*a[i+len]);// 取a[i+len]，剩下的区间[i+len-1]中每个数都翻倍
            
    return f[1][m];
}

__int128 ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            input(game[i][j]);
    for(int i=1;i<=n;i++)
        ans+=solve(game[i]);
    output(ans);
    return 0;
}