//1385：团伙(group),并查集
#include <iostream>
using namespace std;
int ftree[10001],etree[10001];		//friendtree enemytree
int findParent(int x)
{
	return ftree[x]==x? x: findParent( ftree[x] ); //如果x的结点的根就是自己，直接返回，否则递归找其父结点
}
int main()
{
	int n,m,x,y,p,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		ftree[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>p>>x>>y;
		if(p==0)	//为朋友时，则合并朋友圈
		{
			int left=findParent(x);         
			int right=findParent(y);
			ftree[right]=left;
		}
		else	    //敌人时，则合并敌人的 
		{
			if(etree[x]==0)	//x还没有敌人时，让y为敌人团队首领 
				etree[x]=y;
			else	        //敌人的敌人是朋友，他们是一伙人 
			{
				int left=findParent( etree[x] );    //查找 敌人团队首领 	
				int right=findParent( y );          //查找 另一个敌人首领 
				ftree[right]=left;                  //合并
			}
			
			if(etree[y]==0)  //y还没有敌人时，让x为敌人团队首领 
				etree[y]=x;
			else
			{
				int left=findParent( etree[y] );
				int right=findParent(x);
				ftree[right]=left;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(ftree[i]==i)     //如果i的根是自己，说明i是朋友圈的首领，朋友圈数加一
			ans++;
	cout<<ans;
	return 0;
}
