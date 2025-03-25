//【例1-2】后缀表达式的值
//从键盘读入一个后缀表达式（字符串），只含有0-9组成的运算数及加（+）、减（—）、乘（*）、除（/）四种运算符。每个运算数之间用一个空格隔开，不需要判断给你的表达式是否合法。以@作为结束标志。
#include <bits/stdc++.h>
using namespace std;
string s;
stack<long long> st;
int main() {
    getline(cin,s);
    int i=0;
    while (s[i]!='@') {
        if (s[i]>='0'&&s[i]<='9') {
            long long x=0;
            while (s[i]>='0'&&s[i]<='9') {
                x=x*10+s[i]-'0';
                i++;
            }
            st.push(x);
        } 
        else if (s[i]==' ') i++;
        else {
            long long a=st.top();st.pop();
            long long b=st.top();st.pop();
            if (s[i]=='+') st.push(b+a);
            if (s[i]=='-') st.push(b-a);
            if (s[i]=='*') st.push(b*a);
            if (s[i]=='/') st.push(b/a);
            i++;
        }
    }
    cout<<st.top();
}