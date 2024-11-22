//吃糖果
#include <iostream>
using namespace std;
int n,a[21];
int main(){
    cin>>n;
    a[1]=1;
    a[2]=2;
    for (int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2]; //按照题目描述的例子归纳推算一下，就是斐波那契数列
    }
    cout<<a[n];
}