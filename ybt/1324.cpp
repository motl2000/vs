//【例6.6】整数区间
#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
struct act{
	int start;
	int end;
} a[1001];
bool compare(act x,act y){
	if (x.start<y.start)
		return true;
	if (x.start==y.start&&x.end<y.end)
		return true;
	return false;
}
int main() {
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].start>>a[i].end;
	}
	sort (a,a+n,compare);
	int s,e;
	s=a[0].start;
	e=a[0].end;
	for (int i=1;i<n;i++){
		if (a[i].start>e){          //如果下一个区间开始大于现有区间，那么就需要新的区间
			ans++;                  
			s=a[i].start;
			e=a[i].end;
		}
		else{                       //否则就更新现有区间
			s=a[i].start;
			if (a[i].end<e){
				e=a[i].end;
			}
		}
	}
	cout<<ans;

	return 0;
}