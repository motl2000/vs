//4046：【GESP2403三级】完全平方数
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;          
int a[N];                    // 存储输入的数字数组

int main(){
    int n;                   // n表示数字的个数
    cin >> n;                // 读取n
    
    // 循环读取n个数字，存入数组a[1]到a[n]
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    int ans=0;               
    
    // 双重循环枚举所有不同的数对(i,j)，其中i<j，避免重复计算
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){    // j从i+1开始，确保每对只算一次
            int m = a[i] + a[j];     // m为两个数之和
            
            // 计算m的平方根，加1e-7是为了避免浮点数精度误差
            // 例如sqrt(25)可能因为精度问题得到4.9999999，加小量修正
            int t = sqrt(m + 1e-7);
            
            // 判断t的平方是否等于m，即判断m是否是完全平方数
            if(t * t == m)
                ans++;               // 如果是完全平方数，答案加1
        }
    }
    
    cout<<ans<<"\n";         // 输出满足条件的数对总数
}
