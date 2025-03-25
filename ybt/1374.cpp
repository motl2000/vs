//1374：铲雪车(snow)
//因为是双向单车道，最少的情况就是每条路都走两遍，即走一次来回，这个可以自己画图看一下，就知道了
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int row=100;                      //最多100行,加这个是为了方便本地调试，提交时不需要这个，本地调试时可以改成3，因为给的测试用例为3行
int main()
{
    ll a,b,x,y,x1,y1;
    double sum;
    cin>>a>>b;
    int r=0;
    //while(r++<row&&cin>>x>>y>>x1>>y1)
    while(cin>>x>>y>>x1>>y1)
        sum+=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));     //计算每条路的长度
    sum=sum*2/1000/20;                              //每条路都要走两遍
    ll ans=(ll)(sum);                               //取整，得到小时
    ll m=(sum-ans)*60+0.5;                          //取小数部分，得到分钟
    printf("%lld:%02lld\n",ans,m);
}