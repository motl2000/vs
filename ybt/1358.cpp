//1358：中缀表达式值(expr)
//输入一个中缀表达式（由0-9组成的运算数、加+减-乘*除/四种运算符、左右小括号组成。注意“-”也可作为负数的标志，表达式以“@”作为结束符），判断表达式是否合法，如果不合法，请输出“NO”；否则请把表达式转换成后缀形式，再求出后缀表达式的值并输出。
//注意：必须用栈操作，不能直接输出表达式的值。
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
stack<char> op;
stack<int> num;
string s;
//校验表达式是否合法，开头的负号和'('后的负号前加'0',检查括号是否匹配,不能有连续的运算符
bool check() {
    if (s[0] == '+' || s[0] == '*' || s[0] == '/' || s[0] == ')') return false;
    if (s[0] == '-') s = '0' + s;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '(' && (s[i - 1] == ')' || isdigit(s[i - 1]))) return false;
        if (s[i] == ')' && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/')) return false;
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/') return false;
        }
        if (s[i] == '-' && s[i - 1] == '(') s = s.substr(0, i) + '0' + s.substr(i);
    }
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') cnt++;
        if (s[i] == ')') cnt--;
        if (cnt < 0) return false;
    }
    if (cnt != 0) return false;
    //去掉最后的@
    s = s.substr(0, s.length() - 1);
    return true;
}
//优先级
int pri(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}
//计算
int calc(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    return 0;
}
int main() {
    cin >> s;
    if (!check()) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') op.push(s[i]);
        else if (s[i] == ')') {
            while (op.top() != '(') {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                num.push(calc(a, b, op.top()));
                op.pop();
            }
            op.pop();
        } else if (isdigit(s[i])) {
            int x = 0;
            while (i < s.length() && isdigit(s[i])) {
                x = x * 10 + s[i] - '0';
                i++;
            }
            i--;
            num.push(x);
        } else {
            while (!op.empty() && pri(op.top()) >= pri(s[i])) {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                num.push(calc(a, b, op.top()));
                op.pop();
            }
            op.push(s[i]);
        }
    }
    while (!op.empty()) {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        num.push(calc(a, b, op.top()));
        op.pop();
    }
    cout << num.top() << endl;
    return 0;
}

