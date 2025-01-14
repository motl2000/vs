//仙岛求药
#include <iostream>
#include <cstring>                  //memset函数需要的头文件
using namespace std;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int n,m,ans,q[10001][4];            //队列，q[i][1]是行坐标，q[i][2]是列坐标，q[i][3]是步数
bool v[101][101];
int endx,endy;
void bfs(){
    int head=0,tail=1;
    
    while (head<tail){
        head++;
        for(int i=0;i<4;i++){
            int x=q[head][1]+dx[i];
            int y=q[head][2]+dy[i];
            if (x>0&&x<=m&&y>0&&y<=n&&!v[x][y]){
                tail++;
                q[tail][1]=x;
                q[tail][2]=y;
                q[tail][3]=q[head][3]+1;        //步数加一，某个点的步数等于上一个点的步数加一
                v[x][y]=true;
            }
            if (x==endx&&y==endy){
                cout<<q[tail][3]<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}
int main(){
    while (cin>>m>>n){
        if (m==0&&n==0)
            break;
        memset(q,0,sizeof(q));
        memset(v,false,sizeof(v));
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++){
                char c;
                cin>>c;
                if (c=='#')
                    v[i][j]=true;
                if (c=='@'){
                    q[1][1]=i;
                    q[1][2]=j;
                    q[1][3]=0;
                    v[i][j]=true;
                }
                if (c=='*'){
                    endx=i;
                    endy=j;
                }
            }
        bfs();
    }
}