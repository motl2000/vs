//最长公共子上升序列，这题太复杂，不会写，直接抄的，讲不了
#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int a1[maxn],a2[maxn],dp[maxn][maxn],m1,m2;         //dp[i][j]表示a1的前i个元素和a2的前j个元素的最长公共子上升序列的长度
int b1[maxn][maxn],b2[maxn][maxn],max1,max2;        //b1[i][j]记录a1的前i个元素和a2的前j个元素的最长公共子上升序列中最后一个元素到
                                                    //max1和max2记录最长公共子上升序列的结束位置
bool ok[maxn][maxn];
void add(int x,int y){
    if (b1[x][y]==0&&b2[x][y]==0||x<=0||y<=0){      //如果b1[x][y]和b2[x][y]都为0，那么就是最长公共子上升序列的第一个元素
        cout<<a1[x]<<' ';
        return;
    }
    add(x-b1[x][y],y-b2[x][y]);                     //递归输出最长公共子上升序列
    cout<<a1[x]<<' ';
}
int main(){
    cin>>m1;
    for (int i=1;i<=m1;i++){
        cin>>a1[i];
    }
    cin>>m2;
    for (int i=1;i<=m2;i++){
        cin>>a2[i];
    }
    for (int i=1;i<=m1;i++){
        for (int j=1;j<=m2;j++){                                
            //书上的代码不好理解，后面做了优化，下面这段改成dp[i][j]=max(dp[i-1][j],dp[i][j-1])
            // if(dp[i][j]<dp[i-1][j]){        //假设a1[i]和a2[j]不相等
            //                                 //如果dp[i-1][j]>1，说明a1的前i-1个元素和a2的前j个元素的最长公共子上升序列长度大于1
            //                                 //那么dp[i][j]至少等于dp[i-1][j]
            //     dp[i][j]=dp[i-1][j];        
            //     //下面这两行对于此题没有意义，因为b1[i][j]和b2[i][j]都是0，所以不需要初始化
            //     //b1[i][j]=1;                 //由于a1[i]和a2[j]不相等，记录当前a1[i]和a2[j]的最长公共子上升序列长度的值取自a1[i-1]
            //     //b2[i][j]=0;                 //由于a1[i]和a2[j]不相等，记录当前a1[i]和a2[j]的最长公共子上升序列长度的值取自a2[j-0]
            // }
            // if(dp[i][j]<dp[i][j-1]){
            //     dp[i][j]=dp[i][j-1];
            //     //下面这两行对于此题没有意义，因为b1[i][j]和b2[i][j]都是0，所以不需要初始化
            //     //b1[i][j]=0;
            //     //b2[i][j]=1;
            // }
            if(a1[i]==a2[j]){                   //如果a1[i]和a2[j]相等，那么就计算a1的前i个元素和a2的前j个元素的最长公共子上升序列
                dp[i][j]=1;                     //初始化dp[i][j]为1，因为如果a1[i]和a2[j]相等，那么最长公共子上升序列长度至少为1
                for(int k=1;k<i;k++){
                    for(int k2=1;k2<j;k2++){
                        //如果a1[i]和a2[j]相等，且a1[i]大于a1[i-k]，且a1[i-k]等于a2[j-k2]，那么公共上升子序列数量加1
                        if(dp[i][j]<=dp[i-k][j-k2]+1&&a1[i]>a1[i-k]&&a1[i-k]==a2[j-k2]){
                            dp[i][j]=dp[i-k][j-k2]+1;
                            b1[i][j]=k;         //记录a1[i]和a2[j]的最长公共子上升序列在a1中的上一个元素到a1[i]的距离
                            b2[i][j]=k2;        //记录a1[i]和a2[j]的最长公共子上升序列在a2中的上一个元素到a2[j]的距离
                        }
                    }
                }
                if (dp[max1][max2]<dp[i][j]){   //记录最长公共子上升序列的结束位置
                    max1=i;
                    max2=j;
                }
            } 
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    //如果a1[i]和a2[j]不相等，那么最长公共子上升序列长度取自a1的前i-1个元素和a2的前j个元素的最长公共子上升序列长度和a1的前i个元素和a2的前j-1个元素的最长公共子上升序列长度的最大值
        }

    }
    cout<<dp[max1][max2]<<endl;
    if (dp[max1][max2]!=0){                     //如果最长公共子上升序列长度不为0，那么就输出最长公共子上升序列
        add(max1,max2);
    }
    return 0;
}