//1341：【例题】一笔画问题
//如果一个图存在一笔画，则一笔画的路径叫做欧拉路，如果最后又回到起点，那这个路径叫做欧拉回路。
//输入：第一行n，m，有n个点，m条边，以下m行描述每条边连接的两点。
//输出：欧拉路或欧拉回路,输出一条路径即可。
#include <iostream>
#include <string>
using namespace std;
#include<stack>
#include<iostream>
using namespace std;
int n , m;
int G[105][105] , deg[108];                 // G 为邻接矩阵， deg 为度数
stack<int> ans;
 
void dfs(int s){
    for (int i = 1; i <= n; i ++){
        if(G[s][i]){                        // 有边
            G[s][i] = G[i][s] = 0;          // 进行标记 ， 以免走重
            dfs(i);
        }
    }
    ans.push(s);                            // 递归结束后，将点压入栈中。
}
 
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int a , b; 
        cin >> a >> b;
        G[a][b] =  G[b][a] = 1;             // 标记无向图的边
        deg[a] ++ , deg[b] ++;              // 记录度数
    }
 
    int s = 1;
    for(int i = 1; i <= n; i ++){
        if(deg[i] % 2 == 1){
            s = i;                      // 找到第一个有奇数度的点。
            break;
        }
    }
 
    dfs(s);                             // 如果有奇点，说明是欧拉路，就从奇点开始，否则是欧拉回路，从任一点开始都可以，所以就从1开始。
	
	stack<int> san;                     //用来倒序存入栈，并正序输出。
    
    //这里因为找的结果后为正序，所以要倒序进行排序。 
    while(ans.size()){
		san.push(ans.top());
        ans.pop();
    }
    
    
    while(san.size()){
		cout << san.top() << " ";
		san.pop();
    }
    return 0;
}
