//1672：游戏通关
//这是相同类型题型最快的解法
#include<bits/stdc++.h>
using namespace std;
struct psx{ int t, v; } a[200010];
priority_queue<int> q;                 //优先队列，保存可以完成游戏的时间
bool mycmp(psx a,psx b){ return a.t > b.t; }
int n, N, ans, y;

int main() {
	scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&a[i].t,&a[i].v);
		N = max(a[i].t, N);             //记录可以最后完成游戏的时间
    }
    sort(a+1, a+1+n, mycmp);            //按照游戏完成时间从大到小排序
	for(int i = N; i; i--) {            //从最后完成游戏的时间开始，依次向前
        while(a[++y].t >= i)            //将允许在当前时间点之后完成的游戏加入优先队列
            q.push(a[y].v); 
        y--;                            //回退一个游戏，因为前面是先加后判断，所以会多走一格
        if(!q.empty()){                 //如果队列不为空，说明当前时间点可以完成队列中奖励最高的那个游戏
            ans += q.top();
            q.pop();
        }
    }
	printf("%d", ans);
	return 0;
}
