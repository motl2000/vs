//移动路线
#include <iostream>
using namespace std;
int n,m,a[21][21];
int main(){
    cin>>n>>m;
    //初始化,第一行和第一列都是1
    for (int i=1;i<=n;i++){
        a[i][1]=1;
    }
    for (int i=1;i<=m;i++){
        a[1][i]=1;
    }
    //此外，每个位置的值等于其上方和左方的值之和
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            a[i][j]=a[i-1][j]+a[i][j-1];    
        }
    }
    cout<<a[n][m];
    return 0;
}