//1350：【例4-11】最短网络(agrinet)
//kruskal算法
//输入：第一行：农场的个数，N（3≤N≤100）
    //第二行..结尾:后来的行包含了一个N×N的矩阵,表示每个农场之间的距离。
    //理论上，他们是N行，每行由N个字符，因此，某些行会紧接着另一些行。
    //当然，对角线将会是0，因为不会有线路从第i个农场到它本身。
//输出：只有一个输出，其中包含连接到每个农场的光纤的最小长度。

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int n;
int fa[maxn];
struct node{
    int u,v,w;
}a[maxn*maxn];
bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int x){
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    int i,j,k;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            fa[i]=i;
        k=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                scanf("%d",&a[k].w);
                if(a[k].w!=0){
                    a[k].u=i;
                    a[k].v=j;
                    k++;
                }
            }
        sort(a,a+k,cmp);
        int ans=0;
        for(i=0;i<k;i++){
            int x=find(a[i].u);
            int y=find(a[i].v);
            if(x!=y){
                fa[x]=y;
                ans+=a[i].w;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

