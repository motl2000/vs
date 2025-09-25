//P1387 最大正方形
/* 求矩阵内元素和当然可以使用二维前缀和啦。 
也就是：sum为前缀和数组，a为矩阵元素。
预处理：sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j]; 
按i，j顺着推一遍就行了。
求（lx,ly）到（rx,ry)这一矩阵中的元素和：sum[rx][ry]-sum[rx][ly-1]-sum[lx-1][ry]+sum[lx-1][ly-1] */
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,ans;
int a[105][105],b[105][105];
int main() {
	cin>>n>>m;
	int size=min(n,m);//正方形最大的边长 
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int l=1;l<=size;l++){
				int rx=i+l-1;
				int ry=j+l-1;
				if (rx>n||ry>m||b[rx][ry]-b[rx][j-1]-b[i-1][ry]+b[i-1][j-1]!=l*l)
					break;
				if (ans<l)
					ans=l;
			}
		}
	}
	cout<<ans;
	return 0;
}