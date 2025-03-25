//1336：【例3-1】找树根和孩子
//给定一棵树，输出树的根root，孩子最多的结点max以及他的孩子。
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m;
    map<int,vector<int>> tree;          //构建树结构
    vector<int> parent(n+1,-1);         //进行初始化所有节点值为-1 用于标记父节点
    for(int i=0;i<m;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        parent[b] = a;
    }
    int max=0,maxnode=0,root=-1;
    for(int i=1;i<=tree.size();i++){
        if(parent[i]==-1)               //找到根节点,没有父节点的就是根节点
            root=i;
        if(tree[i].size()>maxnode){     //查找最大结点max
            maxnode = tree[i].size();
            max = i;                    //记录最大结点
        }
    }
    cout<<root<<endl;
    cout<<max<<endl;
    for(auto a:tree[max]){
        cout<<a<<" ";
    }
 
}