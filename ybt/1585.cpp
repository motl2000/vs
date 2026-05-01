//1585：【例 1】Amount of Degrees
#include<bits/stdc++.h>
using namespace std;
int x, y, k, b;
int dp[35][35];//dp[i][j]表示i位中有j个1的数量，或高度为i的完全二叉树中有j个1的数量，这个高度是从底到顶迭代的
void init() {
    dp[0][0] = 1;       //
    for(int i = 1; i <= 31; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            //若第i位取0，前i-1位有j个1
            //若第i位取1，前i-1位有j-1个1
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}
//将X转换位只有0,1的B进制（小于等于x最大的那个数）
int turn(int x) {
    vector <int> s;
    int ret = 0;
    while (x > 0) { //转换为B进制
        s.push_back(x % b);
        x /= b;
    }
    bool flag = 0;
    //把B进制的每一位都改成0和1
    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] > 1) {
            flag = 1;
        }
        if (flag == 1) {
            s[i] = 1;
        }
        ret = ret * 2 + s[i]; //计算二进制值
    }
    return ret;
}
int calc(int num) {
    int ans = 0;
    int cnt = 0;    //从0到num的路径中1的个数
    //从高位到低位枚举
    for(int i = 31; i >= 1; i--) {
        if ((1 << i)&num) { //如果当前位是1
            cnt++;//计数
            if (cnt > k) break; //超过k个，退出循环
            num = num ^ (1 << i); //把当前位变0
        }
        //如果下一位是1，把下一位是0的个数全部加进来，即当前位所在树的左子树中1的个数
        if ((1 << (i - 1)) <= num) {
            ans += dp[i - 1][k - cnt];
        }
    }
    //如果num刚好k个1，则加上num本身
    if (cnt + num == k) {
        ans++;//加一个
    }
    return ans;
}
int main() {
    cin >> x >> y >> k >> b;
    x = turn(x);
    y = turn(y);
    init();
    cout << calc(y) - calc(x - 1);
    return 0;
}