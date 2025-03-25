//1354：括弧匹配检验
//假设表达式中允许包含两种括号：圆括号和方括号
//输入一个只包含圆括号和方括号的字符串，判断字符串中的括号是否匹配，匹配就输出 “OK” ，不匹配就输出“Wrong”。输入一个字符串：［（［］［］）］，输出：OK。
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<char> s;
    char c;
    //以回车作为结束符
    while (cin >> c && c != '\n') {
        if (c == '(' || c == '[') s.push(c);
        if (c == ')') {
            if (s.empty() || s.top() != '(') {
                cout << "Wrong" << endl;
                return 0;
            }
            s.pop();
        }
        if (c == ']') {
            if (s.empty() || s.top() != '[') {
                cout << "Wrong" << endl;
                return 0;
            }
            s.pop();
        }
    }
    if (s.empty()) cout << "OK" << endl;
    else cout << "Wrong" << endl;
}