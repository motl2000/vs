//1671：扑克牌
#include<bits/stdc++.h>
using namespace std;
int n,b;
priority_queue <int, vector<int>,greater<int>> q;   //优先队列，保存n张牌，小根堆
int ans;
int main() {
    cin>>n>>b;
    for(int i=1;i<=n;i++){                          //优先队列保存n张牌
        int a;
        cin>>a;
        q.push(a);
    }
    //理论上特殊牌的使用数量一定小于最后可以凑成整副牌的数量
    ans=q.top();                                    //记录最初可以凑出的牌数
    for(int i=1;i<=b;i++){                          //将特殊牌补充到队列里，每循环一次，代表使用一张特殊牌
        int t = q.top();
        q.pop();
        t++;                                        //加到最少的那种牌里
        q.push(t);                                  //补充后放回队列
        ans=q.top();                                //当前最少的牌数，即当前可凑出的牌数
        if (i>ans){                                 //如果使用的特殊牌超过了可以凑成整副牌的数量，表示无法再凑出更多的牌数了
            break;
        }
    }
    cout<<ans;//输出答案
    //cout << q.top()
    return 0;
}