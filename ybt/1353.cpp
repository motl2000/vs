//1353：表达式括号匹配(stack)
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<char> s;
    char c;
    //以@作为结束符
    while (cin >> c && c != '@') {
        if (c == '(') s.push(c);
        if (c == ')') {
            if (s.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            s.pop();
        }
    }
    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}