//2102：【23CSPS提高组】密码锁(lock)
//枚举，组合数学
//从错误的情况转动一个或相邻两个可以得到正确的（不在错误列表中）情况数
#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool check(int a[],int b[][5]){//a是当前枚举的密码，b是所有错误的密码
    for (int i=0;i<n;i++){
        int k=0;
        for (int j=0;j<5;j++){  //检查a中有几位和b[i]不相同
            if (a[j]!=b[i][j])
                k++;
        }
        if (k>2||k==0)          //如果做到这里k>1||k==0，可以得70分，即覆盖题目里数据范围特殊性质A
            return false;
        if (k==1)               //k==1就是一种正确情况
            continue;
        //k==2的情况
        for (int j=0;j<4;j++){  //只需要检查4位，因为最后一位不可能转动两位
            if (a[j]!=b[i][j]){ //如果当前位不同
                //因为只有两连续不同的才可能是正确的，所以只需要检查相邻的位是否相同
                //这里主要是检查不同位数为2，但不是相邻的情况
                if (b[i][j+1]==a[j+1])  
                    return false;
                //如果相邻的位不同，那么就检查两位同时扭动相同距离后是否相同
                else if((b[i][j]+10-a[j])%10==(b[i][j+1]+10-a[j+1])%10)
                    break;//如果相同，说明当前情况是正确的，跳出循环
                else
                    return false;
            }                
        }

    }
    //输出正确的情况
    // for (int j=0;j<5;j++)
    //     printf("%d ",a[j]);
    // printf("\n");
    return true;
}

int main(){
    int a[5],b[10][5];
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<5;j++)
            scanf("%d",&b[i][j]);
    }
    /*用排列组合手算，扭动一个的状态有45种，
    扭动两个的状态有36种，所以是81,
    写死可以得30分
    */
    // if (n==1){
    //     printf("81");
    //     return 0;
    // }
    for (int i=0;i<=99999;i++){ //枚举00000到99999
        int x=i;
        for (int j=4;j>=0;j--){
            a[j]=x%10;
            x/=10;
        }
        //判断当前组合是否可以是一个正确的密码
        if (check(a,b))
            ans++;
    }
    printf("%d",ans);
    return 0;
}