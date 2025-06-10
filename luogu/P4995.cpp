//P4995 跳跳！
//选取最大高度差，所以从最高往最低跳，然后最低跳到最高
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int h[301];
int main() {
	cin>>n;
	if (n==0)
		return 0;
	for (int i=0;i<n;i++){
		cin>>h[i];
	}
	
	sort (h,h+n);           //从低到高排序
	int i=n-1,j=0;
	long long sum=0;
	bool towards=true;//true往上 
	sum=h[i]*h[i];          //先跳到最高
	while (i>j){
		towards=!towards;   //折返
		int t=(h[i]-h[j]);
		t*=t;
		sum+=t;
		if (towards)        
			j++;
		else
			i--; 
	}
	cout<<sum;
	return 0;
}