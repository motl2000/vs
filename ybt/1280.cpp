//【例9.24】滑雪，深搜于动态规划结合
#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},a[101][101],dp[101][101],r,c;   //dx和dy数组表示四个方向，a为地图，dp[i][j]表示到达第i行第j列的最长路径
int dfs(int x,int y){                                                 //深度优先搜索，返回到达第x行第y列的最长路径
    if (dp[x][y]) return dp[x][y];                                    //如果已经搜索过，直接返回
    dp[x][y]=1;                                                       //初始化为1
    for (int i=0;i<4;i++){                                            //枚举四个方向
        int nx=x+dx[i],ny=y+dy[i];                                    //计算下一个位置
        if (nx>=1&&nx<=r&&ny>=1&&ny<=c&&a[nx][ny]<a[x][y])           //如果下一个位置在地图内且高度小于当前位置
            dp[x][y]=max(dp[x][y],dfs(nx,ny)+1);                      //更新最长路径
    }
    return dp[x][y];                                                  //返回最长路径
}
int main(){
    cin>>r>>c;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
            cin>>a[i][j];
    int ans=0;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
            ans=max(ans,dfs(i,j));                                    //枚举每个位置，找到最长路径
    cout<<ans<<endl;                                                  //输出最长路径
    return 0;
}
