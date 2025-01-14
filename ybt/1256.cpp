//献给阿尔吉侬的花束
#include <bits/stdc++.h>
using namespace std;
int t,q[40001][3],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
    cin>>t;
    for (int i=1;i<=t;i++){
        int r,c;
        cin>>r>>c;
        char a[r][c];
        for (int j=1;j<=r;j++)
            for (int k=1;k<=c;k++){
                cin>>a[j][k];
                if (a[j][k]=='S'){
                    q[1][0]=j;
                    q[1][1]=k;
                    q[1][2]=0;
                    a[j][k]='#';
                }
            }
        //广搜
        int head=0,tail=1;
        bool flag=false;
        while (head<tail&&!flag){
            head++;
            for (int j=0;j<4;j++){
                int x=q[head][0]+dx[j],y=q[head][1]+dy[j];
                if (x>0&&x<=r&&y>0&&y<=c&&a[x][y]!='#'){
                    if (a[x][y]=='E'){
                        cout<<q[head][2]+1<<endl;
                        flag=true;
                        break;
                    }
                    tail++;
                    q[tail][0]=x;
                    q[tail][1]=y;
                    q[tail][2]=q[head][2]+1;
                    a[x][y]='#';
                }

            }
        }
        if (flag==false)
            cout<<"oop!"<<endl;   
    }
    return 0;      
}