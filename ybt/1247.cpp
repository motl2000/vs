//河中跳房子
//方法是二分答案，枚举最小的跳跃距离，然后判断是否能跳过m个石头
#include <iostream>
#include <algorithm>
#define maxN 50001
using namespace std;
int n,m,l,r,mid,L;
int a[maxN],b[maxN];
int f(int mid){                     //mid是最小的跳跃距离,返回最多能跳过多少个
    int k=0;                        //k是去掉的石头的个数
    for (int i=0;i<=n;i++)          //b[i]是从0到i的最大跳跃距离
        b[i]=a[i];
    for (int i=1;i<=n;i++){         
        if (b[i]-b[i-1]<mid){       //如果两个石头之间的距离小于mid，就去掉这个石头
            b[i]=b[i-1];
            k++;            
        }
        if (k>m)
            return k;
    }
    return k;
}
int main(){
    cin>>L>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    n++;
    a[0]=0;                         //a[0]是起点
    a[n]=L;                         //a[n]是终点
    l=0;                            //l是最小的跳跃距离
    r=L;                            //r是最大的跳跃距离
    while (l+1<r){                  //二分答案
        mid=(l+r)/2;
        if (f(mid)<=m){             //如果这个跳跃距离可以去掉的石头小于m，就增大跳跃距离
            l=mid;
        }
        else
            r=mid;
    }
    if (f(r)<=m)                    //最后算完r比l大1，所以这时候结果不是r就是l，所以要判断一下是r满足条件还是l满足条件
        cout<<r<<endl;
    else                            
        cout<<l<<endl;
}