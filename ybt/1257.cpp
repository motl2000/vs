//Knight Moves
//输入n代表有个n×n的棋盘，输入开始位置的坐标和结束位置的坐标，问一个骑士朝棋盘的八个方向走马字步，从开始坐标到结束坐标可以经过多少步。
#include <bits/stdc++.h>
using namespace std;
int n,dx[8]={-2,-1,1,2,2,1,-1,-2},dy[8]={1,2,2,1,-1,-2,-2,-1};
int q[90001][4];
bool v[301][301];
int main(){
    //初始化
    cin>>n;
    for (int i=0;i<n;i++){
        memset(q,0,sizeof(q));
        //把v数组清空，这个是重点，不然会出现错误
        for (int j=0;j<301;j++)
            memset(v[j],0,sizeof(v[j]));
        int l;
        cin>>l;
        int sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;
        q[1][1]=sx;
        q[1][2]=sy;
        q[1][3]=0;
        v[sx][sy]=true;
        //如果开始位置和结束位置相同，直接输出0
        if (sx==tx&&sy==ty){
            cout<<0<<endl;
            continue;
        }
        //下面开始就是广搜的模板了
        bool flag=false;
        int head=0,tail=1;
        while (head<tail&&!flag){
            head++;
            for (int i=0;i<8;i++){
                int x=q[head][1]+dx[i];
                int y=q[head][2]+dy[i];
                if (x>=0&&x<l&&y>=0&&y<l&&!v[x][y]){
                    tail++;
                    q[tail][1]=x;
                    q[tail][2]=y;
                    q[tail][3]=q[head][3]+1;
                    v[x][y]=true;
                    if (x==tx&&y==ty){
                        cout<<q[tail][3]<<endl;
                        flag=true;
                        break;
                    }            
                }
            }
        }
    }
    return 0;
}