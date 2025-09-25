#include <iostream>

/* 如果两个数相减的差mod7==0，那么这两个数分别mod7的余数相等，因此只要求出相同的一个余数第一次和最后一次之间的长度即是最长长度 */

using namespace std;
int n,a[50001],mx;
int first[7],last[7];//%7的余数为0~6,所以开7的数组就可以了； 
int main() {
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=(a[i]+a[i-1])%7;
	}
	for (int i=n;i>0;i--) 
		first[a[i]]=i;//第一次出现a[i]这个余数的时候的位置为i 
	first[0]=0;//从头加到i是7的倍数的情况下，需要把0的第一次出现设为0，即把整个区间[1,i]选上了。
	for (int i=1;i<=n;i++)
		last[a[i]]=i;//最后一次出现a[i]这个余数时位置为i； 
		
	for (int i=0;i<7;i++){
		mx=max(last[i]-first[i],mx);
	}
	
	cout<<mx;
	return 0;
}