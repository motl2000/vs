//转进制,递归
#include <iostream>
using namespace std;
int n,k;
char c[6]={'A','B','C','D','E','F'};
void f(int x){
    if (x==0)
        return;
    f(x/k);
    if (x%k>=10)
        cout<<c[x%k-10];
    else
        cout<<x%k;
}
int main(){
    cin>>n>>k;
    f(n);
    return 0;
}