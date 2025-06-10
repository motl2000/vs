//1426：【例题5】智力大冲浪
//扣款最多的任务要优先做，所以按照扣款金额降序排序，然后填到对应的时间段里，如果没有空闲时间段，就扣款。
#include<bits/stdc++.h>
using namespace std;
int n,m,h[10001],s;
struct action{
    int t,w;
    bool operator > (const action &b)const{
        return w>b.w;
    }
}a[10001];
int main(){
	scanf("%d",&m);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].t);
	}
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].w);
    }
    sort (a+1,a+n+1,greater<action>());
	for(int i=1;i<=n;i++){
		int l=0;                        //判断是否空闲
		for(int j=a[i].t;j>=1;j--){     //判断时间段是否空闲
            if(!h[j]){
                h[j]=1;
                l=1;
                break;
            }
        }
		if(!l){
			s+=a[i].w;
		}
	}
	cout<<max(0,m-s)<<endl;
	return 0;
}
