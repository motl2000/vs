//1315：【例4.5】集合的划分
// #include <iostream>

// /* run this program using the console pauser or add your own getch, system("pause") or input loop */

// using namespace std;
// int k,n;
// long long f(int n,int k){
// 	if (n<k||k==0)                  //n<k或者k=0时，无法划分
// 		return 0;
// 	if (n==k||k==1)                  //n=k或者k=1时，只有一种划分方法
// 		return 1;	
// 	return f(n-1,k-1)+k*f(n-1,k);   //f(n-1, k-1)：第 n 个球单独放在一个新盒子里。
//                                     //k*f(n-1,k)：第 n 个球不单独放，而是放进已有的某个盒子。
// }
// int main() {
// 	cin>>n>>k;
// 	cout<<f(n,k);

// 	return 0;
// }

//递推版本
#include <iostream>
using namespace std;

long long dp[100][100]; // 假设n和k不超过100，dp[i][j]表示将n个元素划分成j个集合的方案数

int main() {
    int n, k;
    cin >> n >> k;
    
    // 初始化边界条件
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;  // k=1时只有一种划分（全部放在一个集合）
        if (i <= 100) dp[i][i] = 1; // n=k时每个元素单独一个集合，一种划分
    }
    
    // 递推计算
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i > j) { // 只有i>j时才需要递推公式
                dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];
    return 0;
}
