//菲波那契数列
#include <iostream>
using namespace std;
int fib(int n){
    if (n==1||n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>m;
        cout<<fib(m)<<endl;
    }
    return 0;
}