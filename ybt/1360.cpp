//1360：奇怪的电梯(lift),队列
//思路：广搜，每一步记录从上一步过来时走过的次数+1，直到到达目标楼层
#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct st{
	int x;              //当前楼层
	int z;              //走了多少步
};
queue<st> q;
int a[300];             //a[i]表示从i楼层可以走到的楼层
int b[300];             //b[i]表示i楼层是否走过
int n,m,k;              //n表示楼层总数，m表示起始楼层，k表示目标楼层
void bfs(int x)
{
	b[x]=1;
	st b1;
	b1.x=x;
	b1.z=0;
	q.push(b1);
	while(!q.empty())
	{
		st b2;                  //b2表示当前楼层
		b2=q.front();
		q.pop();
		if(b2.x==k)             //到达目标楼层
		{
			cout<<b2.z<<endl;
			return ;
		}
		if(b[b2.x+a[b2.x]]==0&&a[b2.x]+b2.x<=n) //向上走，a[b2.x]表示从b2.x楼层可以走到的楼层
        {
            b[b2.x+a[b2.x]]=1;
            st b3;                              //b3表示下一层楼
            b3.x=b2.x+a[b2.x];
            b3.z=b2.z+1;                        //走了一步
            q.push(b3);
        }
		if(b[b2.x+a[b2.x]]==0&&b2.x-a[b2.x]>0)  //向下走
		{
			b[b2.x-a[b2.x]]=1;
			st b4;
			b4.x=b2.x-a[b2.x];
			b4.z=b2.z+1;
			q.push(b4);
		}
	}
	cout<<"-1";
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bfs(m);
    return 0;
}
