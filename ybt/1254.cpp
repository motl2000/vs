//走出迷宫
#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int q[10001][4];
bool v[101][101];
int main(){
    //初始化
    int n,m,s,t;
    cin>>n>>m;
    char ch;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            cin>>ch;
            if (ch=='#')
                v[i][j]=true;
            else if (ch=='S'){
                q[1][1]=i;
                q[1][2]=j;
                q[1][3]=0;
                v[i][j]=true;
            }
            else if (ch=='T'){
                s=i;
                t=j;
            }
        }
    //下面开始就是广搜的模板了
    int head=0,tail=1;
    while (head<tail){
        head++;
        for (int i=0;i<4;i++){
            int x=q[head][1]+dx[i];
            int y=q[head][2]+dy[i];
            if (x>0&&x<=n&&y>0&&y<=m&&!v[x][y]){
                tail++;
                q[tail][1]=x;
                q[tail][2]=y;
                q[tail][3]=q[head][3]+1;
                v[x][y]=true;
                if (x==s&&y==t){
                    cout<<q[tail][3]<<endl;
                    return 0;
                }            
            }

        }
    }
    return 0;
}