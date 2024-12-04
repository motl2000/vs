//【例6.1】排队接水
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int n;
struct person{
    int num;
    int time;
}a[1001];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].time;
        a[i].num=i;
    }
    //按时间排序得到总等待时间最短的序列
    sort(a+1,a+n+1,[](person x,person y){return x.time<y.time;});
    //输出序列，并计算总时间
    int sum=0;
    for (int i=1;i<=n;i++){
        cout<<a[i].num<<' ';
        sum+=a[i].time*(n-i);       
    }
    //输出平均时间，保留两位小数
    cout<<endl<<fixed<<setprecision(2)<<(double)sum/n;

    return 0;
}
