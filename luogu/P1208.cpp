//P1208 [USACO1.3] 混合牛奶 Mixing Milk
#include <iostream>
#include<algorithm>
using namespace std;
int n,m;
struct farmer {
	int p;      //价格
	int a;      //数量
	int sp;     //总价
} far[5001];
bool compare (farmer x,farmer y){
	return x.p<y.p;
}
int main() {
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>far[i].p>>far[i].a;
		far[i].sp=far[i].p*far[i].a;
	}
	sort(far,far+m,compare);    //按价格升序排序
	long long sum=0;
	int i=0,num=0;
	while (num+far[i].a<n){     //拿完当前奶农的奶还有剩余配额
		sum+=far[i].sp;
		n-=far[i].a;
		i++;
	}
	sum+=(far[i].p*(n));        //剩余配额把前面排完的下一个奶农的奶买了
	cout<<sum;
	return 0;
}