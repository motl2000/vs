//异或和（xor）
/*一个区间  [l, r]  的异或和为  k  等价于
  prefix[l-1] ^ prefix[r] == k ，
 即  prefix[l-1] == prefix[r] ^ k 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k;
ll a[N],prefix[N];
ll p[2005000],last;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) {         //求异或前缀和
        cin>>a[i];
        prefix[i]=prefix[i-1]^a[i];
    }
    memset(p,-1,sizeof p);
    p[0]=0;                         //p[x]记录的是满足x=prefix[r]^k的最后一个位置
    ll ans=0;
    for(int r=1;r<=n;r++){          //枚举右端点
        ll x=prefix[r]^k;           //求满足条件的左端点的值
        if(p[x]>=last){             //如果满足条件的左端点在last之后，则
            ans++;                  //答案加1
            last=r;                 //更新last
        }
        p[prefix[r]]=r;             //更新p[x]
    }
    cout<<ans;
    return 0;
}
