//Maximum sum
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
const int maxn=50005;
int num[maxn],lsum[maxn],rsum[maxn],t,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>num[i];
        }
        memset(lsum,0,sizeof(lsum));
        memset(rsum,0,sizeof(rsum));
        lsum[1]=num[1];
        for (int i=2;i<=n;i++){             //从左到右求到i的最大子序列和
            if (lsum[i-1]>0)                //排除负数和，保证lsum[i]是以i结尾的最大子序列和
                lsum[i]=lsum[i-1]+num[i];
            else
                lsum[i]=num[i];             //如果lsum[i-1]小于0，那么lsum[i]就是num[i]
        }
        rsum[n]=num[n];
        for (int i=n-1;i>=1;i--){           //从右到左求到i的最大子序列和
            if (rsum[i+1]>0)
                rsum[i]=rsum[i+1]+num[i];
            else
                rsum[i]=num[i];
        }
        int ans=INT_MIN;
        int temp=INT_MIN;
        for(int i=1;i<n;i++){               //两个不重合字段的最大子序列和就是lsum[i]+rsum[i+1]，所以只需要找到最大的lsum[i]和rsum[i+1]的和即可
            if(temp<lsum[i])
                temp=lsum[i];
            if(ans<temp+rsum[i+1])
                ans=temp+rsum[i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}