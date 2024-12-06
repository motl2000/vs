//月度开销
#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001],l=0,r=1000000001,mid;
int f(int x){
    int money=0,cnt=1;
    for (int i=1;i<=n;i++){
        if (money+a[i]>x){              //如果当前月份的开销加上当前天的开销大于x
            cnt++;                      //说明需要新的月份
            money=a[i];                 //重置当前月份的开销
        }
        else{
            money+=a[i];                //否则加上当前天的开销
        }
    }
    return (cnt>m);                     //如果需要的月份大于m，说明x太小
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        l=max(l,a[i]);                  //最小值为最大的开销
    }
    while (l<r-1){                      //直到r-1，因为l和r相邻时，mid=l，会陷入死循环
        mid=l+r>>1;
        if (f(mid)){                    //如果x太小
            l=mid;                      //说明x在mid的右边
        }
        else{
            r=mid;
        }
    }
    if (!f(l))                          //如果l符合条件
        cout<<l<<endl;                  
    else
        cout<<r<<endl;
    return 0;
}