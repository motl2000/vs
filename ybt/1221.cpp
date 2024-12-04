//分成互质组
//给定n个正整数，将它们分组，使得每组中任意两个数互质。至少要分成多少个组？
#include<bits/stdc++.h>
using namespace std;
int n,ans=INT_MAX;
int a[20];
long long vis[20];
long long gcd(long long x,long long y){
    return y==0?x:gcd(y,x%y);
}
void dfs(int k,int step){                   //k表示当前组数，step表示当前处理的数
    if (step==n+1){                         //处理完所有数
        ans=min(ans,k);
        return;
    }
    for (int i=1;i<=k;i++){
        if(gcd(vis[i],a[step])==1){
            vis[i]*=a[step];                //如果选择的这个数与当前组中的数互质，那么就将这个数加入到当前组中
            dfs(k,step+1);                  //递归处理下一个数
            vis[i]/=a[step];                //回溯
        }
    }
    vis[k+1]*=a[step];                      //如果当前数与当前组中的数都不互质，那么就将这个数加入到新的组中
    dfs(k+1,step+1);                        //增加一组，并递归处理下一个数
    vis[k+1]/=a[step];                      //回溯
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=1;                           //初始化，为了使互质的数可以累乘
    }
        
    //sort (a+1,a+n+1);                     //排序，方便后面的处理，排序不是必须
    dfs(1,1);
    cout<<ans;
    return 0;
}
