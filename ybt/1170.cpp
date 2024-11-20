//计算2的N次方
#include <bits/stdc++.h>
using namespace std;
int n,s,len=1,a[10001];
int main(){
    cin>>n;
    a[1]=1;
    for (int k=1;k<=n;k++){
        s=0;
        for (int i=1;i<=len;i++){
            a[i]=a[i]*2+s;
            s=a[i]/10;
            a[i]%=10;
        }
        if (s>0){
            len++;
            a[len]=s;
        }
    }
    for (int i=len;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
