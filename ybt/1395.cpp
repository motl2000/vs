//1395：烦人的幻灯片(slides)
//参考：https://blog.csdn.net/lq1990717/article/details/143581482
#include<bits/stdc++.h>
using namespace std;
#define N 30
struct Rect
{
	int xmin, xmax, ymin, ymax;
	bool isIn(int x, int y)
	{
		return x >= xmin && x <= xmax && y >= ymin && y <= ymax;		
	}
} slide[N];             //slide[i]:字母编号为i的幻灯片 
bool edge[N][N];        //edge[i][j]:字母编号为i的幻灯片是否压着数字j 
int n, deg[N], rec[N];  //rec[i]:字母编号为i的幻灯片对应的数字
int find(int u)         //对于入度只有1的数字顶点u，寻找与其对应的唯一字母顶点 
{
	for(int k = 0; k < n; ++k)
		if(edge[k][u])  //从字母k到数字u有边 
			return k; 
}
bool topoSort()         //返回是否成功完成类拓扑排序（删除数字结点数量是否为n） 
{
	int num = 0;        //成功删除的数字结点数量 
	queue<int> que;
	for(int i = 1; i <= n; ++i)//开始进行类拓扑排序，删除入度为1的数字顶点 
		if(deg[i] == 1)
			que.push(i);
	while(que.empty() == false)
	{
		int u = que.front(), k = find(u);//字母k指向数字u
		que.pop();
		rec[k] = u;     //字母k与数字u对应
		num++;
		for(int i = 1; i <= n; ++i) if(edge[k][i])//删除从字母k到数字i的边 
		{
			edge[k][i] = false;
			if(--deg[i] == 1)//如果数字i入度为1，则入队 
				que.push(i);
		} 
	}
	return num == n;
}
int main()
{
	int x, y;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> slide[i].xmin >> slide[i].xmax >> slide[i].ymin >> slide[i].ymax;
	for(int i = 1; i <= n; ++i)
	{
		cin >> x >> y;
		for(int j = 0; j < n; ++j) if(slide[j].isIn(x, y))//如果x,y在幻灯片字母编号j的范围内
		{
			edge[j][i] = true;  //幻灯片j压着数字i
			deg[i]++;           //数字编号i的入度增加 
		} 
	}
	bool res = topoSort();
	if(res)                     //配对成功 
	{
		for(int i = 0; i < n; ++i)
			cout << char('A'+i) << ' ' << rec[i] << endl; 
	}
	else
		cout << "None";
	return 0;
}
