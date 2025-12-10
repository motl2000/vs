//CSP-J 2025 拼数 / number
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<char> digs;
    for (char c : s)
        if (isdigit(c))
            digs.push_back(c);

    // 题目保证至少有一个 1~9 的数字，无需判断 digs.empty()
    sort(digs.begin(), digs.end(), greater<char>());

    cout << string(digs.begin(), digs.end()) << '\n';
    return 0;
}