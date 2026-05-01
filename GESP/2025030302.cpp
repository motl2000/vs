//4110：【GESP2503三级】词频统计
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    
    map<string, int> cnt;        // 定义map容器，用于统计每个单词（小写形式）的出现次数
    int mx = -1;                 // 记录当前最大出现次数，初始化为-1确保第一个单词能更新它
    
    for (int i = 1; i <= n; i ++) {
        string s; 
        cin >> s;
        assert(s.length() <= 30);  // 断言：确保单词长度不超过30
        
        // 将单词s全部转换为小写，实现大小写不敏感统计
        // ::tolower是C标准库函数，transform将s中每个字符都转换为小写
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        if (! cnt.count(s))        // 如果该单词首次出现，初始化计数为0
            cnt[s] = 0;
        
        mx = max(mx, ++ cnt[s]);   // 先自增计数(++cnt[s])，再用max更新最大值mx
    }
    
    int mx_num = 0;                // 记录出现次数为mx的单词个数（用于后续断言验证唯一性）
    
    // 遍历map，找出所有出现次数等于最大值的单词
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        if ((it->second) == mx) {  // it->second 是单词的出现次数，it->first 是单词本身
            cout << (it->first) << '\n';  // 输出出现次数最多的单词（小写形式）
            mx_num ++;
        }

    return 0;
}
