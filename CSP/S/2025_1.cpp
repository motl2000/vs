//CSP-S 2025 社团招新 / club
/*
先把选每个人的最大值放进对应的部门，如果都不超过n/2,就是要的结果，否则先计算一个总的结果
如果有超过，最多只可能有一个部门超过
超过的学生，只需要考虑其最大值和次大值之间的差值最小的，把他移出这个超出的部门，并把次大值加到总值上，这时候就是损失最小的。
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int maxV,minDif,nextV;//maxV:最大值,nextV:最大值与次大值的差值
};
bool compare(node a,node b){
    return a.minDif<b.minDif;
}
int t,n;
long long ans;
vector<node> v [3];
int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 1; i <= n; ++i) {
            int a,b,c;
            cin>>a>>b>>c;
            //找出a,b,c中的最大值和次大值,差值
            if (a>=b && a>=c){
                if (b>c){
                    v[0].push_back({a,a-b,b});
                }else{
                    v[0].push_back({a,a-c,c});
                }
            }else if (b>=a && b>=c){
                if (a>c){
                    v[1].push_back({b,b-a,a});
                }else{
                    v[1].push_back({b,b-c,c});
                    
                }
            }else if (c>=a && c>=b){
                if (a>b){
                    v[2].push_back({c,c-a,a});
                }else{
                    v[2].push_back({c,c-b,b});
                }
            }
        }
        // for (int i = 0; i < 3; ++i){
        //     cout<<"v"<<i<<" : ";
        //     for (int j = 0; j < v[i].size(); ++j) {
        //         cout<<v[i][j].maxV<<" ";
        //     }
        //     cout<<endl;
        // }
        //找出v中数量超过n/2的行，顺便计算每一行的和
        int l=-1;     //l:数量超过n/2的行数
        for (int i = 0; i < 3; ++i) {
            if(v[i].size()>n/2)
                l=i;
            for (int j = 0; j < v[i].size(); ++j) {
                ans+=v[i][j].maxV;
            }
        }
        //如果l>=0，说明有数量超过n/2的行，需要将其中差值最小的值移走
        if (l>=0){
            sort(v[l].begin(), v[l].end(), compare);
            
            for (int i = 0; i < v[l].size()-n/2; ++i) {
                ans-=v[l][i].maxV;
                ans+=v[l][i].nextV;
            }
        }
        
        //输出结果
        cout<<ans<<endl;
        
        //清空v
        for (int i = 0; i < 3; ++i) {
            v[i].clear();
        }   
        ans=0;
    }
    return 0;
}