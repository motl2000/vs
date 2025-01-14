//The Castle
#include <iostream>
#include <cstring>                      //memset函数需要的头文件
using namespace std;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int a[51][51][4];                       //a[i][j][k]表示(i,j)这个点向k方向是否有墙
int q[5001][3];                         //队列,第一列是行坐标，第二列是列坐标
int n,m,x,y,ans,maxs;                   //n是行数，m是列数，x是行坐标，y是列坐标，ans是房间的个数
bool v[51][51];                         //v[i][j]表示(i,j)这个点是否被访问过
void bfs(int x,int y){                  //bfs
    memset(q,0,sizeof(q));
    ans++;
    int tail=1,head=0,xx,yy;
    q[1][1]=x;
    q[1][2]=y;
    v[x][y]=true;
    while (head<tail){
        head++;
        for (int i=0;i<4;i++){
            xx=q[head][1]+dx[i];
            yy=q[head][2]+dy[i];
            if (xx>0&&xx<=m&&yy>0&&yy<=n&&!a[q[head][1]][q[head][2]][i]&&!v[xx][yy]){//判断是否越界，是否有墙，是否被访问过
                tail++;
                q[tail][1]=xx;              
                q[tail][2]=yy;
                v[xx][yy]=true;
            }
        }
    }
    maxs=max(maxs,tail);
}
int main(){
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++){     //输入墙的信息
            int p;
            cin>>p;
            if (p>=8){
                a[i][j][3]=1;
                p-=8;
            }
            if (p>=4){
                a[i][j][2]=1;
                p-=4;
            }
            if (p>=2){
                a[i][j][1]=1;
                p-=2;
            }
            if (p>=1){
                a[i][j][0]=1;
                p-=1;
            }
        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (!v[i][j])
                bfs(i,j);
    cout<<ans<<endl<<maxs<<endl;
}