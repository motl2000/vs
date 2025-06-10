//1673：楼间跳跃
//这题有个噱头，因为每个楼可以上下，还可以从顶楼到底楼，所以走完一栋楼就是楼层高度的次数
//所以这不是那种下降取最大值的问题，就可以把楼看成一个有n个货物的背包，每到达一个楼，就至少获取一个货物，然后还剩n-1个货物可以获取
//题解1
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,m;
struct node
{
	long long h,v;
	bool operator < (node b) const             
	{
		return v>b.v;
	}
}lou[maxn];
priority_queue< node > q;
long long q_cnt,q_sum;
long long sm[maxn];
long long ans,cur;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&lou[i].h,&lou[i].v);
		sm[i]=sm[i-1]+lou[i].v;                 //要到达i楼，就至少已经获得了前面每个楼的一个物品
	}
	for(int i=1;i<=min(m+1,n);++i)
	{
		cur=sm[i];								//最远走到当前楼最少可以获得的价值
		if(lou[i].h>1)                          //如果楼的高度大于1
		{
			q_cnt+=lou[i].h-1;                 	//当前楼可以拿到剩余物品，因为到达该楼的时候自动拿了一个，所以还剩h-1个物品     
			q_sum+=1LL*(lou[i].h-1)*lou[i].v;	//当前楼可以拿到剩余物品的总价值
			q.push((node){lou[i].h-1,lou[i].v});//放入堆，最小的在前面
		}
		while(m-i+1<=q_cnt-q.top().h)           //如果剩余的步数不够走完当前价值最小的楼
		{
			q_cnt-=q.top().h;					//排除调当前价值最小的楼
			q_sum-=1LL*q.top().v*q.top().h;
			q.pop();
		}
		if(q_cnt<=m-i+1)						//如果走完当前选择的所有楼的步数小于等于剩余的步数
			cur+=q_sum;							//当前总价值就等于走到当前楼的初始价值+走完所有已选楼的总价值
		else 									//如果走完当前选择的所有楼的步数大于剩余的步数
			cur+=q_sum-1LL*(q_cnt-(m-i+1))*q.top().v;//排除掉当前价值最小的楼里缺少的步数可以获得的价值
		ans=max(cur,ans);
	}
	cout<<ans<<endl;
	return 0;
} 

//题解2
// #include<bits/stdc++.h>
// using namespace std;
// char frd[1048576],*ihead(frd+1048576);const char *itail(ihead);
// inline char nxtChar(void){
// 	if(ihead==itail)fread(frd,1,1048576,stdin),ihead=frd;
// 	return *ihead++;
// }
// //此程序仅适用于整型
// template<typename T>
// inline void get(T &res){
// 	T f(1);char c;res=0;
// 	while(!isdigit(c=nxtChar()))if(c=='-')f=-1;
// 	res=c&15;
// 	while(isdigit(c=nxtChar()))res=(res<<1)+(res<<3)+(c&15);
// 	res*=f;
// }
// //以上为快读
// class value{
// 	public:
// 		long long h;
// 		long long v;
// 		value(){return;}
// 		value(const long long &h,const long long &v):h(h),v(v){return;}
// 		bool operator>(const value &a)const{return this->v>a.v;}
// };
// priority_queue<value,vector<value>,greater<value> > heap;///heap里放着已经经过的价值从低到高的楼
// //以上为数据结构
// int main(){
// 	long long n,k,ans(0),res(0),tot_v(0),tot_h(0);
// 	get(n),get(k),++k;
// 	for(register int i(1);i<=n;++i){        //枚举最远可以到达的楼
// 		long long h,v;
// 		get(h),get(v),--k,res+=v;           //如果最远到达当前楼，就至少可以多获得一个当前楼的物品，k-1可以移动的次数减一
// 		if(!k)break;                        //如果k已经为0，就退出循环
// 		if(h>1){
// 			value tmp(h-1,v);               //由于已经拿走一个当前楼物品，所以高度减一
// 			heap.push(tmp);
// 			tot_h+=tmp.h;                   //先默认爬完当前楼，获得当前楼的价值
// 			tot_v+=tmp.h*tmp.v;             
// 			while(!heap.empty()&&tot_h-heap.top().h>=k){//排除当前剩余步数下那些价值最小的已经爬过的楼
// 				tot_h-=heap.top().h;
//                 tot_v-=heap.top().v*heap.top().h;
// 				heap.pop();
// 			}//可以捞到的总油水。

// 		}
//         //tot_h>=k表示已经爬完的完整楼楼层数比剩余步数多
//         //res+tot_v+(k-tot_h)*heap.top().v 表示：最远到达当前楼至少可以获得的价值+当前算出的额外可以获得价值-走完全部需要的楼还缺的步数*当前最小价值楼的价值
// 		if(ans<(tot_h>=k?res+tot_v+(k-tot_h)*heap.top().v:tot_v+res))
// 			ans=tot_h>=k?res+tot_v+(k-tot_h)*heap.top().v:tot_v+res;
// 	}
// 	printf("%lld\n",ans);
// 	return 0;
// }
