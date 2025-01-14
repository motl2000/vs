//走迷宫
#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int q[1001][4];
bool v[41][41];
int main(){
    //初始化
    int r,c;
    cin>>r>>c;
    char ch;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++){
            cin>>ch;
            if (ch=='.')
                v[i][j]=true;
        }
    q[1][1]=1;
    q[1][2]=1;
    q[1][3]=1;
    //下面开始就是广搜的模板了
    int head=0,tail=1;
    while (head<tail){
        head++;
        for (int i=0;i<4;i++){
            int x=q[head][1]+dx[i];
            int y=q[head][2]+dy[i];
            if (x>0&&x<=r&&y>0&&y<=c&&v[x][y]){
                tail++;
                q[tail][1]=x;
                q[tail][2]=y;
                q[tail][3]=q[head][3]+1;
                v[x][y]=false;
                if (x==r&&y==c){
                    cout<<q[tail][3]<<endl;
                    return 0;
                }            
            }

        }
    }
    return 0;
}