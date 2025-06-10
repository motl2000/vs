//1323：【例6.5】活动选择
#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
struct act{
	int start;
	int end;
} a[1001];
bool compare(act x,act y){
	if (x.end<y.end)
		return true;
	if (x.end==y.end&&x.start<y.start)
		return true;
	return false;
}
int main() {
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].start>>a[i].end;
	}
	sort (a,a+n,compare);
	for (int i=0;i<n-ans;i++){
		int et=a[i].end;
		int num=1;
		for (int j=i+1;j<n;j++){
			if (a[j].start>=et){
				et=a[j].end;
				num++;
				ans=max(ans,num);
			}
		}
	}
	cout<<ans;

	return 0;
}