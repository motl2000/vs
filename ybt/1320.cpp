//【例6.2】均分纸牌(Noip2002)
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[101],step;
int main(){
    cin>>n;
    int ave=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        ave+=a[i];              //计算总数
    }
    ave/=n;                     //计算平均数
    for (int i=1;i<=n;i++){     //计算每堆与平均数的差值
        a[i]-=ave;
    }
    int i=1,j=n;
    while (a[i]==0&&i<n)        //找到第一堆不为0的纸牌
        i++;
    while (a[j]==0&&j>1)        //找到最后一堆不为0的纸牌
        j--;
    while (i<j){
        a[i+1]+=a[i];           //将第i堆的纸牌分给第i+1堆
        a[i]=0;                 //第i堆的纸牌清空
        step++;                 //操作次数加一
        i++;                    //处理下一堆
        while (a[i]==0&&i<j)    //找到下一堆不为0的纸牌
            i++;
    }
    cout<<step;
    return 0;
}