//1423：【例题2】种树
#include<bits/stdc++.h>
using namespace std;
struct cyy{
	int b,e,t;
}a[5010];
bool f[30010];                              //记录区间是否种树
bool cmp(cyy x,cyy y)                       //按结束区间排序
    {
        return x.e<y.e;
    } 
int main()
{
	int n,m,ans=0;
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].t);
	sort(a+1,a+m+1,cmp);                    //按结束区间排序，使得区间可以重叠，使重复利用率最大
	
	for(int i=1;i<=m;i++){                  //枚举每个区间
		int k=0;
		for(int j=a[i].b;j<=a[i].e;j++)
			if(f[j]) 
                k++;                        //已经种过的树，累加
		if(k>=a[i].t) 
            continue;                       //如果本区间已经种过树的数量达到或超过要求，就不用再种树了
		for(int j=a[i].e;j>=a[i].b;j--)
			if(!f[j]){                      //补种（从尾部开始） 
				f[j]=1;                     //种树
                k++;                        //本区间已经种过的树数量加一
                ans++;                      //所有区间已经种过的树数量加一
				if(k==a[i].t)
                    break;                  //达标 
			} 
	}
	printf("%d\n",ans);
	return 0;
}

