//1592：【例 1】国王
#include<bits/stdc++.h>
using namespace std;

long long f[11][155][155]={0},ans;//f[i][j][k]表示第i行状态为j，国王数为k的方案数 
int num[155],s[155],n,k,s0;//num[i]表示第i个状态用掉的国王数，s[i]表示第i个状态，s0表示状态数 

void prepare()
{
    int cnt;
    s0=0,ans=0;
    for(int i=0;i<(1<<n);i++)//枚举每一行的状态，总方案数为2^n
    {
        if(i&(i<<1))//检查当前状态是否冲突（当前状态是否存在两个相邻的国王），如果i中的1都不相邻，结果应为0
            continue;
        cnt=0;
        //统计当前有效状态下可以使用的国王数 
        for(int j=0;j<n;j++)    //遍历当前状态的每一位
            if(i&(1<<j))        //如果当前位是1，则cnt++
                cnt++;          //cnt表示当前状态用掉的国王数 
        s[++s0]=i;      //在s数组中存储当前状态
        num[s0]=cnt;    //在num数组中存储当前状态用掉的国王数
     } 
}

void dp()
{
    f[0][1][0]=1;                   //初始化f[0][1][0]=1，表示第0行状态为1，国王数为0的方案数为1
    for(int i=1;i<=n;i++)           //枚举行
        for(int j=1;j<=s0;j++)      //枚举第i行状态
            for(int kk=0;kk<=k;kk++)//枚举前i行的国王数
            {
                if(kk>=num[j])      //如果国王数量大于等于当前状态用掉的国王数量，则可以继续递推
                    for(int t=1;t<=s0;t++)//t表示前i-1行状态 
                    {
                        //判断冲突
                        if(!(s[t]&s[j])             //如果第i-1行状态和当前状态没有冲突
                            &&!(s[t]&(s[j]<<1))     //如果第i-1行状态的左下方和当前状态没有冲突
                            &&!(s[t]&(s[j]>>1))){   //如果第i-1行状态的右下方和当前状态没有冲突
                                f[i][j][kk]+=f[i-1][t][kk-num[j]]; //第i行状态为j，国王数为kk的方案数等于第i-1行状态为t，国王数为kk-num[j]的方案数
                            }                           
                    } 
             } 
    
    for(int i=1;i<=s0;i++) 
        ans+=f[n][i][k];
    cout<<ans<<'\n';
}

int main()
{
    cin>>n>>k;
    prepare();
    dp();//使用函数更方便 
    return 0;
}