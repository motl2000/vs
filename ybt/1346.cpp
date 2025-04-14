//1346：【例4-7】亲戚(relation)
//写法1：递归查询+路径压缩，简单合并
// #include<bits/stdc++.h>
// using namespace std;
// #define N 20005
// int fa[N];
// void initFa(int n)                  //初始化并查集
// {
// 	for(int i = 1; i <= n; ++i)
// 		fa[i] = i;
// }
// int find(int x)                     //查找根节点
// {
// 	if(x == fa[x])
// 		return x;
// 	else
// 		return fa[x] = find(fa[x]);
// }
// void merge(int x, int y)            //合并两个集合
// {
// 	fa[find(x)] = find(y);
// }
// int main()
// { 
// 	ios::sync_with_stdio(false);            //关同步,目的提高效率
// 	cin.tie(nullptr);                       //关cin与cout的绑定，目的提高效率
// 	int n, m, q, a, b, c, d;
// 	cin >> n >> m;
// 	initFa(n);                              //初始化并查集
// 	for(int i = 1; i <= m; ++i)
// 	{
// 		cin >> a >> b;
// 		merge(a, b);                        //合并两个集合
// 	}
// 	cin >> q;
// 	while(q--)
// 	{
// 		cin >> c >> d;
// 		cout << (find(c) == find(d) ? "Yes" : "No") << '\n';
// 	}
// 	return 0;
// }

//写法2：非递归查询，按秩合并
#include<bits/stdc++.h>
using namespace std;
#define N 20005
int fa[N], rk[N];                   //fa[i]:结点i的父结点 rk[i]:以结点i为根结点的树的秩 
void initFa(int n)                  //初始化并查集
{
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}
int find(int x)                     //非递归查询与路径压缩 
{
    int k, t, r;                    //r:根结点  
    k = r = x;
    while(r != fa[r])               //查找根结点
        r = fa[r];                  //找到根结点，用r记录        
    while(k != r)                   //路径压缩：将从x到r的整条路径上的结点的父结点都设为r
    {
        t = fa[k];                  //用t暂存k的父结点
        fa[k] = r;                  //fa[k]指向根结点
        k = t;                      //k指向暂存的父结点 
    }
    return r;                       //返回根结点            
}
void merge(int i, int j)            //按秩合并i结点和j结点所在的集合
{
    int x = find(i), y = find(j);   //先找到两个根结点
    if(x == y) return;              //根结点相同，就不用合并了 
    if(rk[x] < rk[y])               //高度低的树作为高度高的树的子树
        fa[x] = y;
    else if(rk[x] > rk[y])
        fa[y] = x;
    else                            //如果高度相同，则新的树的高度+1
    {
        fa[x] = y;
        rk[y]++;
    }
}
int main()
{ 
	int n, m, q, a, b, c, d;
	scanf("%d%d", &n, &m); 
	initFa(n);                        //初始化并查集
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		merge(a, b);                  //合并两个集合
	}
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d", &c, &d);
		if(find(c) == find(d))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
