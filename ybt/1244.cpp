//和为给定数
#include <bits/stdc++.h>
using namespace std;
const int N=100001;
int a[N];
int main(){
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    sort(a,a+n);
    int i=0,j=n-1;
    while (i<j){
        if(a[i]+a[j]==m){
            cout<<a[i]<<" "<<a[j];
            return 0;
        }
        if(a[i]+a[j]<m)//如果左边最小的加右边最大的还不能到m，那么说明左边的太小了，右移，此时如果右边的左移，那么和会更小，所以只能右移
            i++;
        else
            j--;
    }
    cout<<"No";
}