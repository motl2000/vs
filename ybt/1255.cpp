//迷宫问题,一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。输出左上角到右下角的最短路径。
#include <iostream>
using namespace std;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int q[37][3],a[26];                 //q[i][0]用来保存前驱
bool v[6][6];
int main(){
    for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++){
            cin>>v[i][j];
        }
    q[1][1]=1;
    q[1][2]=1;
    v[1][1]=true;
    int head=0,tail=1;
    while (head<tail){
        head++;
        for (int i=0;i<4;i++){
            int x=q[head][1]+dx[i];
            int y=q[head][2]+dy[i];
            if (x>0&&x<=5&&y>0&&y<=5&&!v[x][y]){
                tail++;
                q[tail][1]=x;
                q[tail][2]=y;
                q[tail][0]=head;                //保存前驱
                v[x][y]=true;
                if (x==5&&y==5){
                    int t=tail;
                    int k=0;
                    while (t>=1){               //从终点开始回溯
                        k++;
                        a[k]=t;                 //保存路径
                        t=q[t][0];              //找前驱
                    }
                    for (int i=k;i>=1;i--){
                        cout<<"("<<q[a[i]][1]-1<<", "<<q[a[i]][2]-1<<")"<<endl;//由于是从1到5，所以要减1
                    }
                    return 0;
                }            
            }

        }
    }
}


