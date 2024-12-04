//统计数字，本题考查的是快速排序的基本应用
#include <iostream>
using namespace std;
const int N=200001;
int n,a[N];
//普通的快速排序
void quickSort(int l,int r){
    if (l>=r) return;
    int x=a[l+r>>1],i=l,j=r;
    while (i<=j){
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    quickSort(l,j);
    quickSort(i,r);
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    quickSort(1,n);
    for (int i=1;i<=n;i++){
        int cnt=0;
        while (a[i]==a[i+1]){
            cnt++;
            i++;
        }
        if (cnt){
            cout<<a[i]<<' '<<cnt+1<<endl;
        }
        else{
            cout<<a[i]<<' '<<1<<endl;
        }
    }
    return 0;
}