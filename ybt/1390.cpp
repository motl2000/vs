//1390：食物链【NOI2001】
#include<bits/stdc++.h>
using namespace std;
#define N 50005
//共有n个动物，对于动物i ii，假设i + n是i的一个天敌
//，假设i + 2n是i的一个猎物。（i + n和i + 2n是我们人为假设出来的并非1~n中任何动物的其他动物）
int fa[3*N], ans;               //fa[i]：i的双亲，下标1~3*n。 

void initFa(int n)
{
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	fa[find(x)] = find(y);
}
int main()
{
	int n, k, op, x, y;
	cin >> n >> k;
	initFa(3*n);
	while(k--)
	{
		cin >> op >> x >> y;
		if(x > n || y > n)      //x或y大于N,假话+1
		{
			ans++;
			continue;
		}
		if(op == 1)//x和y同类 
		{
			if(find(x) == find(y+n) || find(x) == find(y+2*n))//如果y是x的天敌或猎物
				ans++;
			else
			{
				merge(x, y);            //x和y同类
				merge(x+n, y+n);        //x和y的天敌同类
				merge(x+2*n, y+2*n);    //x和y的猎物同类
			}
		}
		else//op == 2 x吃y 
		{
			if(find(x) == find(y+2*n) || find(x) == find(y))//如果y是x的猎物或x和y同类
				ans++;
			else
			{
				merge(x, y+n);            //x和y的天敌同类
				merge(x+n, y+2*n);        //x的天敌和y的猎物同类
				merge(x+2*n, y);          //x的猎物和y同类
			}
		}
	}
	cout << ans;
	return 0;
}
