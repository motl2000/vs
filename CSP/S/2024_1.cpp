//P11231 [CSP-S 2024] 决斗
//贪心，最少情况就是升序排序以后大的吃小的，可以想象一下，一个沿着横轴延伸的柱状图，最后吃下来，其实剩下的就是最高的那个柱子
#include <iostream>
#include <algorithm>
using namespace std;
//最高效率
// int n,a[100000],ans;
// int main(){
//     cin>>n;
//     for (int i=1;i<=n;i++){
//         int k;
//         cin>>k;
//         a[k]++;
//         ans=max(ans,a[k]);
//     }
//     cout<<ans;
//     return 0;
// }
//最朴素，双指针
int n,a[100000],ans;
int main(){
    cin>>n;
    //输入
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    //排序
    sort(a,a+n);
    //双指针比较
    int i=0;
    for (int j=1;j<n;j++){
        if (a[j]>a[i]){
            i++;
            ans++;
        }
    }
    cout<<n-ans;
    return 0;
}


