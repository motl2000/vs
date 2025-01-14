//不重复地输出数，这题放在分治里没什么意思，原意是联系快速排序的，但是这里只需要排序，所以直接用sort函数就行了
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100001;
int a[N];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++){
        if(i==0||a[i]!=a[i-1])
            cout<<a[i]<<" ";
    }
}