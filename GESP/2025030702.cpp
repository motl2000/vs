//等价消除
//原理：利用前缀异或和与哈希表来高效计算
//详细分析过程见解析文档
#include <cstdio>
 #include <map>
 using namespace std;
 const int N = 2e5 + 5;
 int n;
 char s[N];
 map <int, int> m;
 long long ans;
 int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int v = 0;                      //表示从字符串开头到当前位置的字符出现次数的奇偶性（用二进制位表示）
    m[v]++;                         //m[v]表示前缀异或和为v的字符串个数，即字母组合奇偶性为v的字符串个数
    for (int i = 1; i <= n; i++) {
        v ^= 1 << (s[i] - 'a');     //当前字符的异或和，每一个v值表示一个字母组合的奇偶性,
                                    //相同的v值表示相同的奇偶性和相同的字母组合
        //下面两行是为了累计相同v值的组合个数
        //如果相同v值的数量有n-1个，每增加一个，总的组合个数就增加n-1个
        //证明：C(n,2)-C(n-1,2)=n-1，数学可证
        ans += m[v];                
        m[v]++;                     
    }
    printf("%lld\n", ans);
    return 0;
 }