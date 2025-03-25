//书架
#include <iostream>
#include <algorithm>
using namespace std;
int n,b,a[20001];    
int main(){
    cin>>n>>b;
    int ans=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort (a+1,a+n+1);
    while (b>0){
        b-=a[n];
        n--;
        ans++;
    }
    cout<<ans;
}