//1359：围成面积
//思路：从0,0开始，以原图中的1为边界，把所有0都标记为1，最后统计没有被标记的0的个数
#include<iostream>
#include<queue>
using namespace std;
int n=10,ans,maxx;
struct node{
    int x,y;
};
queue<node> que;
int a[101][101];
int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};

void bfs(int x,int y){
    que.push({x,y});
    a[x][y]=1;
    while(!que.empty()){
        for(int i=1;i<=4;i++)
        {
            int nx=que.front().x+dx[i];
            int ny=que.front().y+dy[i];
            if(nx<0||nx>n+1||ny<0||ny>n+1)  //越界
                continue;
            if(a[nx][ny]==1)                //已经走过
                continue;
            que.push({nx,ny});
            a[nx][ny]=1;
        }
        que.pop();
    }
    return;
}

int main(){
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            cin>>a[i][j];
    bfs(0,0);
    for(int i=0;i<=n+1;i++) 
        for(int j=0;j<=n+1;j++) 
            if(a[i][j]==0) 
                ans++;
    cout<<ans;
    return 0;
}