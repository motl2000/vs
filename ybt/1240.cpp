//查找最接近的元素
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100001;
int n,m,a[N];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        int x;
        cin>>x;
        int l=1,r=n;
        while (l<r){
            int mid=l+r>>1;                 //二分查找
            if (a[mid]<x){
                l=mid+1;                    //使x最终在l的左侧
            }
            else{
                r=mid;
            }
        }
        if (l==1){
            cout<<a[l]<<endl;
        }
        else{
            if (x-a[l-1]<=a[l]-x){          //判断哪个更接近，如果左右两个相等，输出左边的
                cout<<a[l-1]<<endl;
            }
            else{
                cout<<a[l]<<endl;
            }
        }
    }
    return 0;
}