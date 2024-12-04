//爬楼梯
#include <iostream>
using namespace std;
int a[31];
void f(int n){
    a[1]=1;
    a[2]=2;
    for (int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
}
int main(){
    f(30);
    int n;
    while (cin>>n){
        cout<<a[n]<<endl;
    }
    return 0;
}