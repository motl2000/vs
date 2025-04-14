//1352：【例4-13】奖金
#include <iostream>
using namespace std;
int a[10001][301]={0},into[10001],ans[10001],m,n,money;//money记录奖金，ans记录拓扑排序的结果
void init(){
    int i,x,y;
    cin>>n>>m;
    for (i=1;i<=m;i++){
        cin>>x>>y;
        a[y][0]++;          //记录从y引出的边的数目
        a[y][a[y][0]]=x;    //记录从y引出的边的顶点
        into[x]++;          //记录x的入度
    }
}
bool topsort(){
    int t,tot,k,i,j;
    tot=0;
    k=0;                                    //拓扑的层次
    while(tot<n){
        t=0;                                //用来判断是否有循环
        for (int i=1;i<=n;i++){
            if (into[i]==0){
                tot++;                      //记录拓扑排序的个数
                t++;                        //记录入度为0的点数量
                money+=100;                 //至少有100的奖金
                ans[t]=i;                   //记录本次拓扑排序的结果
                into[i]=0xffffffff;         //将入度置为无穷大，防止重复
            }
        }
        if (t==0)                       //如果所有点都入度都不为0，说明有循环
            return false;
        money+=k*t;                     //最少多t个节点乘以k的金额
        k++;                            //增加一层
        for (int i=1;i<=t;i++)          //去掉相连的边
            for (j=1;j<=a[ans[i]][0];j++)
                into[a[ans[i]][j]]--;   //边对应
    }
    return true;
}
int main(){
    init();
    if (topsort())
        cout<<money<<endl;
    else
        cout<<"Poor Xed"<<endl;
    return 0;
}