//逆波兰表达式
#include <bits/stdc++.h>
using namespace std;
char str[1001];
double f(){
    scanf("%s",str);
    double x=0;
    switch (str[0])
    {
    case '+':
        x=f()+f();
        break;
    case '-':
        x=f()-f();
        break;
    case '*':
        x=f()*f();
        break;
    case '/':
        x=f()/f();
        break;  
    default:
        x=atof(str);    //如果不是符号，就是数字，atof()函数将字符串转换为浮点数
    }
    return x;
}
int main(){
    printf("%f",f());
    return 0;
}
