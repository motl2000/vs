//1356：计算(calc)
//小明在你的帮助下，破密了Ferrari设的密码门，正要往前走，突然又出现了一个密码门，门上有一个算式，其中只有“(”，“)”，“0-9”，“+”，“-”，“*”，“/”，“^”，求出的值就是密码。小明数学学得不好，还需你帮他的忙。(“/”用整数除法)
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
stack<char> op;
stack<int> num;
int pri(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}
int calc(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    if (c == '^') {
        int res = 1;
        for (int i = 0; i < b; i++) res *= a;
        return res;
    }
    return 0;
}
int main() {
    cin >> s;
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
        } else if (s[i] >= '0' && s[i] <= '9') {
            int x = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
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