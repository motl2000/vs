//1370：最小函数值(minval)
#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	priority_queue<int> q;              //优先队列，大根堆，用来保存前m个最小值
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		for(int j=1;j<=m;j++){
			int num=a*j*j+b*j+c;
			if(i==1) 
                q.push(num); 
			else{
				if(num<q.top())         //如果当前数比堆顶小，弹出堆顶，插入当前数
                {				
					q.pop();
					q.push(num);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		a[i]=q.top();
		q.pop();
	}
	for(int i=m;i>=1;i--) 
        cout<<a[i]<<" ";
 return 0;
}
 