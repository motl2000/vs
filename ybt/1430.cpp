//1430：家庭作业
#include<iostream>
#include<queue>
using namespace std;
int const N=1e6+5;
bool p[N];
struct homework{
    int f,t;
    bool operator < (const homework x) const{
        return f<x.f;               //当使用标准库的priority_queue时，默认构造的是最大堆（大顶堆），即通过operator<比较会将"较小"元素下沉
    }
}tmp;
priority_queue<homework> q;         //大根堆
int n,ans,tt;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp.t>>tmp.f;
        q.push(tmp);
    }
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        int i;
        for(i=tmp.t;i>tt;i--)           //tt是当前时间，i是下一个作业的开始时间，如果i>tt，说明当前时间可以安排作业，否则不能安排作业
            if(!p[i])
            {
                p[i]=true,ans+=tmp.f;
                break;
            }
        //没有下面的处理是无法全部通过的
        if(i==tt&&tt<tmp.t)//tt是从0开始，如果从tmp.t到0全部填满了，说明前面的空间都不可以用了，此时tt要更新为当前作业的开始时间
            tt=tmp.t;
    }
    cout<<ans;
    return 0;
}