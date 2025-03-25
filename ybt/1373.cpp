//1373：鱼塘钓鱼(fishing）
//这题可以用动态规划，但我们先用贪心算法来解决这个问题。
//这题的关键是要认识到，无论最多钓多少，都至少走到第i个鱼塘，这样就最少要消耗掉走完1到i-1鱼塘的时间。
#include <bits/stdc++.h>
using namespace std;
#define N 105
int fish[N], de[N], st[N], f[N];        //fish[i]:第1分钟第i鱼塘可以钓到的鱼的数量
                                        //de[i]:第i鱼塘每分钟钓鱼数量减少的数量
                                        //st[i]:从第1鱼塘走到第i鱼塘的时间
                                        //f[i]:第i鱼塘当前剩余的鱼的数量
int n, te, endT, mxFish;
struct Cmp
{
	bool operator () (int a, int b)
	{
		return f[b] > f[a];             //鱼塘每分钟钓鱼数量更高的鱼塘更优先 
	}
}; 
int main()
{
	cin >> n;                           //n:鱼塘数量 
	for(int i = 1; i <= n; ++i)
		cin >> fish[i];                 //fish[i]:第1分钟第i鱼塘可以钓到的鱼的数量
	for(int i = 1; i <= n; ++i)
		cin >> de[i];                   //dec[i]:每过一分钟鱼可以钓到的鱼减少的数量
	for(int i = 1; i <= n-1; ++i)
	{
		cin >> te;                      //te:从第i鱼塘走到第i+1鱼塘的时间
		st[i+1] = st[i] + te;           //st[i]:从第1鱼塘走到第i鱼塘的时间 
	}
	cin >> endT;                        //endT:截止时间
	for(int i = 1; i <= n; ++i)         //最远走到第i鱼塘
	{
		memcpy(f, fish, sizeof(fish));  //将fish数组的内容复制到f数组中 
		priority_queue<int, vector<int>, Cmp> pq;//优先队列中保存的是鱼塘编号，每分钟钓鱼数量更高的更优先 
		for(int j = 1; j <= i; ++j)
			pq.push(j);
		int fishNum = 0;                //可分配时间为总时间减去走到鱼塘i的时间  fishNum:钓到的鱼数量 
		for(int t = 1; t <= endT-st[i]; ++t)    //endT-st[i]是到达i鱼塘后还剩余的钓鱼时间
		{
			if(pq.empty())
				break;
			int mxi = pq.top();         //当前每分钟钓鱼数量最大的鱼塘编号 
			pq.pop();
			fishNum += f[mxi];          //总钓鱼数量增加f[mxi]
			f[mxi] -= de[mxi];          //该鱼塘每分钟钓鱼数量减少
			if(f[mxi] > 0)              //如果在该鱼塘还能钓鱼 
				pq.push(mxi);           //把该鱼塘加入到优先队列 
		}
		mxFish = max(mxFish, fishNum);  //更新最大钓鱼数量 
	}
	cout << mxFish;
	return 0;
}

//动态规划做法
// #include <bits/stdc++.h>
// using namespace std;
// #define N 105
// #define T 1005
// int dp[N][T];//dp[i][j]:在前i个鱼塘中钓鱼，消耗时间j，可以钓到鱼的最大数量。
// int fish[N], de[N], f[N][T], t[N], st[N], mxTime[N];
// int n, endT, mxFish;
// int main()
// {
// 	cin >> n;//n:鱼塘数量 
// 	for(int i = 1; i <= n; ++i)
// 		cin >> fish[i];//fish[i]:第1分钟第i鱼塘可以钓到的鱼的数量
// 	for(int i = 1; i <= n; ++i)
// 		cin >> de[i];//dec[i]:每过一分钟鱼可以钓到的鱼减少的数量
// 	for(int i = 1; i <= n; ++i)
// 		for(int j = 1; fish[i] > 0; ++j)
// 		{
// 			f[i][j] = f[i][j-1] + fish[i];//f[i][j]:在第i鱼塘钓鱼j分钟能钓到的鱼
// 			fish[i] -= de[i];
// 			mxTime[i] = j;//mxTime[i]:在第i鱼塘能钓到鱼的最大时间（超过这一时间就钓不到鱼了） 
// 		}
// 	for(int i = 1; i <= n-1; ++i)
// 	{
// 		cin >> t[i];//t[i]:从第i鱼塘走到第i+1鱼塘的时间
// 		st[i+1] = st[i] + t[i];//st[i]:从第1鱼塘走到第i鱼塘的时间 
// 	}
// 	cin >> endT;//endT:截止时间 
// 	for(int i = 1; i <= n; ++i)//i:鱼塘号 
// 		for(int j = 1; j <= endT; ++j)//j:消耗时间 
// 			for(int k = 0; k <= mxTime[i] && k <= j-st[i]; ++k)//k：在第j鱼塘钓鱼k分钟 
// 				dp[i][j] = max(dp[i][j], dp[i-1][j-t[i-1]-k] + f[i][k]);
// 	for(int i = 1; i <= n; ++i)
// 		mxFish = max(mxFish, dp[i][endT]);
// 	cout << mxFish;
// 	return 0;
// }