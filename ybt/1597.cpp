//1597：【 例 1】滑动窗口
#include<iostream>
#define size 1000000
using namespace std;
int n,k,a[size],minn[size],maxn[size],num[size],q[size];
//依次表示：个数，窗口长度，每个数，最小数的数组，最大数的数组，队列元素的编号，队列元素的值
inline void dp_min()//窗口最小数dp
{
    int head=1,tail=0;//head>tail表示空队列
    for(int i=1;i<=n;i++)
    {
        while(num[head]<i-k+1&&head<=tail) //队列中元素编号小于i-k+1的元素都弹出队列，因为这些元素不可能是最小的
            head++;
        while(a[i]<=q[tail]&&head<=tail) //队列中元素大于等于a[i]的元素都弹出队列，因为这些元素不可能是最小的
            tail--;
        q[++tail]=a[i];     //加入队列
        num[tail]=i;        //记录元素编号
        minn[i]=q[head];    //队首元素一定是最小的
    }
}
inline void dp_max()//窗口最大数dp （同上）
{
    int head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        while(num[head]<i-k+1&&head<=tail) //队列中元素编号小于i-k+1的元素都弹出队列，因为这些元素不可能是最大的
            head++;
        while(a[i]>=q[tail]&&head<=tail) //队列中元素小于等于a[i]的元素都弹出队列，因为这些元素不可能是最大的
            tail--;
        q[++tail]=a[i];     //加入队列
        num[tail]=i;        //记录元素编号
        maxn[i]=q[head];    //队首元素一定是最大的
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    dp_min();
    dp_max();
    for(int i=1+k-1;i<=n;i++)//注意不要多输出
        cout<<minn[i]<<" ";
    cout<<endl;
    for(int i=1+k-1;i<=n;i++)
        cout<<maxn[i]<<" ";
    return 0;
}