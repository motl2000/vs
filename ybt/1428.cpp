//1428：数列分段
#include <bits/stdc++.h>
 
using namespace std;
int main(int argc, char *argv[]) {
	//队列
	queue<int>a;
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		a.push(t);
	}
	int ans = 0;
	//从前向后，先取一个数，判断这个数与下一个数的和，如果和大于m，这个数单独一个组
	while(a.size()){
		int t = a.front();
		ans++;
		a.pop();
		while(t + a.front()<= m && a.size()>0)
		{
			t += a.front();//将下一个数纳入到和里
			a.pop();
		}
	}
	cout << ans;
	return 0;
}