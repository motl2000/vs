//1361：产生数(Produce),队列
#include<bits/stdc++.h>
using namespace std;
#define K 20
int n, k, ct, x[K], y[K], arr[5], ai;
bool vis[10001];
void toArr(int num)//将整数num进行数字拆分，结果保存在数字数组arr中。（包括num为0的情况） 
{
    ai = 0;
    int a = num;
    do
    {
        arr[++ai] = a % 10;
        a /= 10;
    }while(a > 0);    
}
int toNum()//将数字数组arr保存的数字转为整型数字 
{
    int num = 0;
    for(int i = ai; i >= 1; --i)
        num = num * 10 + arr[i];
    return num;
}
void bfs()
{
	queue<int> que;
	vis[n] = true;
	ct = 1;
	que.push(n);
	while(que.empty() == false)//遍历所有转换的数字，直到没有新的数字产生
	{
		int u = que.front();
		que.pop();
		toArr(u);//将u转为数字数组arr 
		for(int i = 1; i <= ai; ++i)//遍历arr中的每一位 
		{
			for(int j = 1; j <= k; ++j)
			{
				if(arr[i] == x[j])
				{
					arr[i] = y[j];
					int newNum = toNum();       //按规则转换数字
					if(vis[newNum] == false)    //如果数字没有出现过就入队且标记为已出现
					{
						vis[newNum] = true;
						ct++;
						que.push(newNum);
					}
					arr[i] = x[j];//还原 
				}
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= k; ++i)
		cin >> x[i] >> y[i];
	bfs();
	cout << ct;
	return 0;
}