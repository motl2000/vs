//山区建小学
#include <iostream>
using namespace std;
int n,m;
int a[501][501];                            //a[i][j]表示第i个城市到第j个城市的距离
int b[501][501];                            //b[i][j]表示i和j之间建1个学校时i和j之间所有村庄到学校的最短距离和
int c[501][501];                            //c[i][j]表示i个村庄建立j个学校，各个村庄到学校的最短距离和
const int maxN=0x7fffffff;
int main(){
    cin>>m>>n;
    for (int i=1;i<m;i++){
        cin>>a[i][i+1];                     //读入数据，初始化，表示第i个城市到第i+1个城市的距离
    }
    for (int i=1;i<=m;i++){
        for (int j=i+1;j<=m;j++){
            a[i][j]=a[i][j-1]+a[j-1][j];    //求出第i个城市到第j个城市的距离
            a[j][i]=a[i][j];                //对称性
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=i+1;j<=m;j++){
            int mid=(i+j)/2;                //求出i和j的中点，两地的中间建学校距离最短
            b[i][j]=0;
            for (int k=i;k<=j;k++){
                b[i][j]+=a[k][mid];        //求出i和j之间所有村庄到学校的距离和
            }
        }
    }
    for (int i=1;i<=m;i++){
        c[i][1]=b[1][i];                    //初始化，i个村庄建一个学校的最短距离和，就是1到i间建一个学校的距离和
    }
    for (int i=1;i<=m;i++){                 //i个村庄
        for (int j=2;j<=n;j++){             //j个学校
            c[i][j]=maxN;
            for (int k=j-1;k<=i;k++){       //在1到i之间分割成1到k和k+1到i两部分
                c[i][j]=min(c[i][j],c[k][j-1]+b[k+1][i]);    //动态规划，求出i个村庄建j个学校的最短距离和
                //c[k][j-1]+b[k+1][i]表示前K个村庄建j-1个学校的最短距离和加上K+1到i的村庄间建1个学校的距离和
            }
        }
    }
    cout<<c[m][n];
    return 0;
}