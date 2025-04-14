//1388：家谱(gen)
#include <bits/stdc++.h>
using namespace std;
#define N 50005
map<string, string> fa;//fa[儿子]：父亲，用map实现的目的是可以直接处理字符串，因为按照题意，不存在重名
string find(string x)
{
	if(fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}   
int main()
{
	char c;
	string father, child;
	while(cin >> c && c != '$')
	{
		if(c == '#')
		{
			cin >> father;
			if(fa.count(father) == 0)   //fa.count(father)：判断fa中是否包含father这个键，即fa中是否已经存在father这个父亲
				fa[father] = father;
		}
		else if(c == '+')
		{
			cin >> child;
			fa[child] = father;         //上一个循环必定有一个父亲，所以fa[child] = father
		}
		else if(c == '?')
		{
			cin >> child;
			cout << child << ' ' << find(child) << endl;
		}
	}
	return 0;
}
 