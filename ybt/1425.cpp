//1425：【例题4】加工生产调度
//总用时最短，即让机器空闲时间最短。一旦A机器开始，其将进行作业直到最后。
//B机器则在加工过程中可能会在等待A机器，显然A机器加工第一个产品时，B机器必须等待，而最后一个产品在B机器上加工时，A机器则一停止并等待B机器完工。
//1.使机器空闲时间最短，把A机器上加工时间最短的产品最先加工，可使得B机器在最短的等待时间后开始加工；
//  把B机器加工时间最短的产品放在最后，使得A机器用最短的时间等待B机器完工。
//2.同一个产品在A上加工时间短于B上加工时间的应该优先在A上加工，这样B机器的等待时间最短。
//1、2结合。

#include<bits/stdc++.h>
using namespace std;
 
struct stu{
	int a,b,m,i;    //m为a,b的最小值，i为序号
}s[10001];
 
int res[10001];
 
bool cmp(stu x,stu y){
	return x.m<y.m;//从小到大排序 
}
 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i].a;
	}
	for(int i=1;i<=n;++i){
		cin>>s[i].b;
		s[i].i = i;
		s[i].m = min(s[i].a,s[i].b);		
	}
	sort(s+1,s+n+1,cmp);
	int front = 1;
	int back = n;
	for(int i=1;i<=n;++i){
		if(s[i].a==s[i].m){     //A工厂的时间较短 
			res[front++] = i;   //记住当前序号，从前往后，左侧以A较短的升序排序
		}else{
			res[back--] = i;    //记住当前序号 ，从后往前，右侧以B较短的降序排序
		}
	}
	int t1=0,t2=0;
    //计算总时间,A厂先加工完，B厂再加工完
    //两种可能性
    //1. 加工完A的总时长小于已经加工完的B的总时长，此时总时长是加工完B的总时长
    //2. 加工完A的总时长大于已经加工完的B的总时长，此时总时长是加工完A的总时长+下一个B的时长
	for(int i=1;i<=n;++i){
		t1 += s[res[i]].a;      //累加A厂的加工时间
		t2 = max(t1,t2);        //当前累加最大时间
		t2 += s[res[i]].b;      //获取最长加工时间后，累加B厂的加工时间 
	}
	cout<<t2<<endl;
	for(int i=1;i<=n;++i)cout<<s[res[i]].i<<" "; 
	return 0;
}