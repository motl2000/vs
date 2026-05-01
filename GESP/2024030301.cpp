//4045：【GESP2403三级】字母求和
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
char str[N];  // 存储加密后的字符串

int main() {
    int n;          // 字符串长度
    cin >> n;       // 读取字母个数
    cin >> str;     // 读取加密字符串
    
    int ans = 0;    // 存储解密后的整数总和
    
    // 遍历字符串，逐个处理每个字符
    for (int i = 0; i < n; i ++) {
        // 处理小写字母：代表正整数，值为字母表顺序
        // 'a'-'a'+1=1, 'b'-'a'+1=2, ..., 'z'-'a'+1=26
        if (str[i] >=  && str[i] <= )//填入>=和<=后的内容
            ans += ;//填入+=后的内容
        
        // 处理大写字母：代表负整数，值为ASCII码的相反数
        // 根据题意：字母A代表-65，即-(65)=-65
        // 因此直接减去ASCII码：ans -= 65 等价于 ans += (-65)
        else if ()//填入()内的内容
            ans -= ;  // 填入-=后的内容
    }
    
    cout << ans << endl;  // 输出解密后的整数
    return 0;
}
