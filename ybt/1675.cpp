//1675：塔
//以下代码部分正确
// #include <iostream>
// #include <stack>

// using namespace std;
// int n,ans;
// long long a[3002];
// int main() {
//     cin >> n;
//     int m=0;
//     for (int i = 0; i <n; i++) {
//         cin >> a[i];
//     }
//     for (int i = 0; i <n; i++) {
//         if (a[i]>=m){
//             m=a[i];
//         }
//         else{
//             if (a[i]+a[i+1]<m){
//                 if (i<n-2){
//                     if (a[i]+m<=a[i+1]+a[i+2]){
//                         m+=a[i];
//                         a[i+2]+=a[i+1];

//                     }
//                     else{
//                         a[i+2]=a[i+2]+a[i+1]+a[i];
//                     }
//                     i++;
//                     ans+=2;
//                 }
//                 else if (i==n-1){
//                     ans+=1;
//                     break;
//                 }
//                 else{
//                     ans+=2;
//                     break;
//                 }
//             }
//             else{
//                 a[i+1]+=a[i];
//                 ans++;
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }

//贪心+动态规划
#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
long long n,a[3001],f[3001],s[53001010];
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i) 
        cin>>a[i];
    for (int i=1;i<=n;++i) 
        s[i]=a[i]+s[i-1];                   //前缀和
    for (int i=1;i<=n;++i) 
        a[i]=f[i]=inf;                      //a[i]表示第i个塔的最小高度，f[i]表示第i个塔获得最小高度要合并的最小代价
    for (int i=1;i<=n;++i) 
        for (int j=0;j<i;++j)
            if (a[j]<=s[i]-s[j])            //如果a[j+1]到a[i]的和大于a[j]，即合并a[j+1]到a[i]后a[j]和a[i]是非降的
            {
                f[i]=min(f[i],f[j]+i-j-1);  //第i个塔得到最小高度的最小代价就是第j个塔得到最小高度的最小代价加上i-j-1，就是j+1到i的距离    
                if (a[i]>s[i]-s[j])         //a[i]取i到j中合并后最小的高度
                    a[i]=s[i]-s[j];
            }
    cout<<f[n];
    return 0;
}