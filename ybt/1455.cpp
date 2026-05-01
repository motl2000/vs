//1455：【例题1】Oulipo
//核心思想：多项式哈希 + 滚动窗口
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull base = 131;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string pat, txt;
        cin >> pat >> txt;
        int m = pat.size(), n = txt.size();

        /* 预处理幂数组，pow[i] = base^i*/
        vector<ull> pow(m + 1);
        pow[0] = 1;
        for (int i = 1; i <= m; ++i) 
            pow[i] = pow[i - 1] * base;

        /* 计算 pat 的哈希 
            例： pat="ABA" ，base=131
            hp = 'A' * 131² + 'B' * 131¹ + 'A' * 131⁰ 
            131 是一个不大不小的质数，经过竞赛实践验证，能在计算效率和冲突率之间取得最佳平衡。
            由于值太大，用  unsigned long long  自然溢出，等价于自动取模 2⁶⁴。
        */
        ull hp = 0;
        for (char c : pat) //滚动求哈希值，hp(i) = hp(i-1) * base + pat[i]
            hp = hp * base + c;

        /* 滚动哈希扫描目标串中第一段长度为 m 的文本串*/
        ull ht = 0;
        for (int i = 0; i < m; ++i) 
            ht = ht * base + txt[i];

        //继续扫描m到n-1的目标串
        int cnt = (ht == hp);
        for (int i = m; i < n; ++i) {
            ht = ht * base + txt[i] - txt[i - m] * pow[m];
            if (ht == hp) 
                ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
