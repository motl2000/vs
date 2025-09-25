//1855：【09NOIP提高组】潜伏者
//模拟
#include <iostream>
using namespace std;

int main() {
    char cipher[105], plain[105], target[105];
    cin >> cipher >> plain >> target;

    int c2p[26], p2c[26];          // 密->原，原->密
    for (int i = 0; i < 26; ++i) {
        c2p[i] = p2c[i] = -1;      // 初始化 -1 表示未映射
    }

    bool failed = false;
    for (int i = 0; cipher[i]; ++i) {//遍历密文
        int c = cipher[i] - 'A';    
        int p = plain[i] - 'A';

        // 检查是否重复映射，两个方向都要检查
        if (c2p[c] != -1 && c2p[c] != p) { //已有映射，且映射不同
            failed = true; 
            break; 
        }
        if (p2c[p] != -1 && p2c[p] != c) { //已有映射，且映射不同
            failed = true; 
            break; 
        }

        // 映射
        c2p[c] = p;
        p2c[p] = c;
    }

    // 检查是否 26 个字母全部出现
    bool complete = true;
    for (int i = 0; i < 26; ++i) {
        if (c2p[i] == -1) { complete = false; break; }
    }

    if (failed || !complete) {
        cout << "Failed" << endl;
    } else {
        for (int i = 0; target[i]; ++i) {
            cout << char(c2p[target[i] - 'A'] + 'A');
        }
        cout << endl;
    }
    return 0;
}
