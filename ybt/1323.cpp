//1323：【例6.5】活动选择
#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
struct act{
	int start;
	int end;
} a[1001];
//前面的活动越早结束，能容纳越多的活动。
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
	for (int i=0;i<n-ans;i++){	//如果在前面所有可能得区间段里已经找到了最多个数目的区间段，且剩余未判定的数量小于找到的最大数量，后面的区间就不用判定了
		if (i==n-1)
			break;
		int et=a[i].end;		//区间开始时间就是当前区间结束时间
		int num=1;
		for (int j=i+1;j<n;j++){
			if (a[j].start>=et){//如果区间起点时间比上一段区间结束时间晚
				et=a[j].end;	//区间终点时间设置为当前区间段终点时间
				num++;			//区间数量加1
				ans=max(ans,num);
			}
		}
	}
	cout<<ans;

	return 0;
}