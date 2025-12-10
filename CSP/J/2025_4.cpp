//2025 CSP J 4.多边形（polygon）
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5000 + 5, V = 5000 + 1;
const int MOD = 998244353;

int n, a[N], f[V], sum[N];          

int quick_pow(int b) {                     //快速幂，默认底数为2
    if(!b) return 1;
    int res = quick_pow(b >> 1);
    res = (1ll * res * res) % MOD;
    if(b & 1) (res <<= 1) %= MOD;
    return res;
}

int main() {
    cin >> n; 
    for(int i = 1; i <= n; ++i) 
        cin >> a[i]; 
    sort(a + 1, a + n + 1);                 //排序，使得a[i]是1到i中最长的木棍
    f[a[1]] = f[0] = 1;                     //f[0]表示长度和为0的组合数，f[a[1]]表示长度和为a[1]的组合数，初始化为1
    /*
    背包f[j]表示长度和为j时的组合数,由于选择长度和>2*a[i]将需要开很大的背包，是从1到n*n，这肯定不行
    所以我们选择先计算总长度和<=2*a[i]的组合数情况，大于的情况就是总的组合数减去小于等于的情况数
    所以1<=j<=V
    在1到i个数中，一共有2^(i)个组合情况
    所以选所有长度和<=2*a[i]的方案数，再简化就是在此基础上除2，就是不超过a[i]，而a[i]<=5000,就可以在一个可控的背包空间里计算
    最终用2^(i-1)-小于等于a[i]的方案数，就是要的大于的方案数
    */
    for(int i = 2; i <= n; ++i) {           //枚举木棍，从第二根开始，因为f[a[1]]就是第一根木棍，已经处理了
        for(int j = V - 1; j >= a[i]; --j)  //从大到小枚举背包容量，防止f[j]被覆盖， 一维0/1背包特征
            (f[j] += f[j - a[i]]) %= MOD;   //f[j]=f[j]+f[j-a[i]]，不长度和为j时，不选择a[i]和选择a[i]的方案数
        for(int j = 0; j <= a[i+1]; ++j)    //累计前i根木棍中所有长度和小于等于a[i+1]的方案数
            (sum[i] += f[j]) %= MOD;
    }

    int ans = 0;
    //2^(i-1)-小于等于a[i]的方案数，就是要的大于的方案数
    for(int i = 3; i <= n; ++i) {
        (ans += (quick_pow(i - 1) - sum[i - 1] + MOD) % MOD) %= MOD;
    }
    cout << ans;

    return 0;
}
