//寻找平面上的极大点
#include <iostream>
#include <cstdio>
using namespace std;
int n,a[101][101],ans[101][3];
int main(){
    int mx=0,my=0;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;              //标记点
        mx=max(mx,x);           //找到最大的x和y
        my=max(my,y);
    }
    int t=0,m=0;                //t是极大点的个数，m是当前列的y值
    for (int i=mx;i>=0;i--){    //x轴方向从右往左找
        for (int j=my;j>m;j--){ //y轴方向从上往下找，且当前列的y值应该大于右边的极大点的y值，碰到的第一个点就是极大点
            if (a[i][j]==1){
                m=j;
                t++;                
                ans[t][0]=i;
                ans[t][1]=j;

            }
        }
    }
    for (int i=t;i>=1;i--)
        if (i==1)
            cout<<'('<<ans[i][0]<<','<<ans[i][1]<<')';
        else
            cout<<'('<<ans[i][0]<<','<<ans[i][1]<<"),";

    return 0;
}