//1224：最大子矩阵
#include <bits/stdc++.h>
using namespace std;
int n,a[101][101],maxn=-1000000000;
int main() {
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			a[i][j]+=a[i][j-1];//得出每列在该行的前缀和 
		}
	}
	for (int i=0;i<n;i++) {//从左向右排查 
		for (int j=i+1;j<=n;j++) {//遍历从左向右的每一个区间 
			int sum=0;
			for (int k=1;k<=n;k++){//遍历与该区间相交叉的行所围成的子矩阵的数字和 
				sum+=a[k][j]-a[k][i];
				maxn=max(maxn,sum);
				if (sum<0)//如果前面行的合计值小于0，再去加上后面的行，只能使得后面行的值更小，此时需要舍弃当前行 
					sum=0;
			}
		}
	}
	cout<<maxn; 
	return 0;
}