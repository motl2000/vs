//网线主管
#include <iostream>
#include <cstdio>
using namespace std;
double a[10001],ans;
int n,k,l=0,r=10000000,mid;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]*=100;                      //初始化为cm
    }
    while (l<=r){
        mid=l+r>>1;
        int cnt=0;
        for (int i=1;i<=n;i++){
            cnt+=a[i]/mid;              //计算当前长度下可以切出的网线数量
        }
        if (cnt>=k){                    //如果可以切出的网线数量大于等于k，说明长度可以增加
            if (mid>ans) ans=mid;       //更新答案
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf("%.2lf",ans/100);            //输出答案
    return 0;
}