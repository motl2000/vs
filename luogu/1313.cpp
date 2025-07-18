//1313：【例3.5】位数问题
//在所有的N位数中，有多少个数中有偶数个数字3?由于结果可能很大，你只需要输出这个答案对12345取余的值。
//注意0个3也偶数个3
//这题还需要掌握加法原理和乘法原理
#include <bits/stdc++.h>
using namespace std;
int n,a[1001],b[1001];
int main() {
	cin>>n;
	a[0]=9;                         //a[i]表示i位数中，有偶数个3的数的个数   
	b[0]=1;                         //b[i]表示i位数中，有奇数个3的数的个数
	int x=9;                        //默认1位数有9个不是3的数，所以有9个偶数数个3
	for (int i=1;i<n;i++){          //从十位数开始遍历
		if (i==n-1)                 //如果是最高位，那么x=8，因为最高位不能为0，所以x=8
			x=8;                    
		a[i]=(a[i-1]*x+b[i-1])%12345;//当前偶数个3的个数等于上一位的偶数个数*x+上一位的奇数个数，因为当前位有一个3，加上前面位数的奇数个3的个数就是偶数个3
		b[i]=(a[i-1]+b[i-1]*x)%12345;//当前奇数个3的个数等于上一位的偶数个数+上一位的奇数个数*x，因为当前位有一个3，加上前面位数的偶数个3的个数就是奇数个3
	}
	cout<<a[n-1];
	return 0;
}