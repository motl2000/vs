//1528：【例 2】单词游戏
/*
看成有向图，每个单词的首尾字母作为节点，单词作为有向边。检查是否存在欧拉路径
欧拉路径存在的充要条件是：
1. 图是连通的（所有出现过的字母在同一个连通分量中）。
2. 满足以下条件之一：
    所有点入度等于出度（存在欧拉回路）。
    恰好一个点出度比入度多 1（起点），一个点入度比出度多 1（终点），其余点入度等于出度（存在欧拉路径）
*/
#include <bits/stdc++.h>
using namespace std;
const int Z=26;
int in[Z],out[Z],e[Z],p[Z]; //in:入度，out:出度，e:存在节点，p:并查集父节点
//并查集
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void unite(int x,int y){p[find(x)]=find(y);}

bool check(){           //检查是否存在欧拉路径
    int st=-1,ed=-1;
    for(int i=0;i<Z;++i){
        if(!e[i])continue;
        if(out[i]-in[i]==1){    //出度比入度大1，说明是起点，只能有一个
            if(st!=-1)return 0;
            st=i;
        }else if(in[i]-out[i]==1){//入度比出度大1，说明是终点，只能有一个
            if(ed!=-1)return 0;
            ed=i;
        }else if(out[i]!=in[i])return 0;
    }
    if((st==-1&&ed==-1)||(st!=-1&&ed!=-1)){//起点和终点都存在或都不存在
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        memset(e,0,sizeof e);
        for(int i=0;i<Z;++i)p[i]=i;
        for(int i=0;i<N;++i){
            string s;
            cin>>s;
            if(s.empty())continue;
            int u=s[0]-'a',v=s.back()-'a';
            ++out[u]; ++in[v];
            e[u]=e[v]=1;
            unite(u,v);
        }
        bool ok=check();
        bool g=1;
        int r=-1;
        for(int i=0;i<Z;++i){
            if(!e[i])continue;
            if(r==-1)r=find(i);
            else if(find(i)!=r){
                g=0;break;
            }
        }
        cout<<(ok&&g?"Ordering is possible.\n":"The door cannot be opened.\n");
    }
    return 0;
}
