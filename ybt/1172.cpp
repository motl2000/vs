//求10000以内n的阶乘
#include <bits/stdc++.h>
using namespace std;
int n,a[100000],len=1;          //a数组存储结果,len存储结果的位数
int main(){
    cin>>n;
    a[1]=1;
    for (int k=1;k<=n;k++){
        //第一种，记录进位的方法
        // int s=0;
        // for (int i=1;i<=len;i++){
        //     a[i]=a[i]*k+s;
        //     s=a[i]/10;
        //     a[i]%=10;
        //     //处理最高位进位
        //     if (i==len&&s>0){
        //         len++;
        //     }
        // }
        //第二种，不记录进位的方法
        for (int i=1;i<=len;i++){
            a[i]*=k;                //先计算当前位
            a[i]=a[i]+a[i-1]/10;    //加上上一位的进位
            a[i-1]%=10;             //上一位的进位清零
            //处理最高位进位
            if (a[i]>9&&i==len){
                len++;
            }
        }
    }
    for (int i=len;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}