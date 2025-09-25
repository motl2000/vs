#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int main() {
    int n;
    cin >> n;
    int maxW=10000000;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]<maxW){
            maxW=a[i];
            ans+=a[i];
        }
        else{
            ans+=maxW;
        }
    }
    cout<<ans<<endl;
    return 0;
}
