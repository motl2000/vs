//1375：骑马修栅栏(fence)
//欧拉路问题
#include<iostream>
#include<cmath>
using namespace std;
int du[10050] ={0}, ola[10050] ={0}, n , start  = 0,
//du[]用来存每个点的度数 ，ola[]用来存储路径 ，start查找最小的开始点
    map[1050][1050] ={0}, m = 0 , tot = 0;
void dfs(int k){
    for(int i = 1 ; i <= m ; i++){
        if(map[k][i] != 0){
            map[k][i] --;
            map[i][k] --;
            //避免重复走
            dfs(i);
        }
    }
    tot++;
    ola[tot] = k;
//深搜每个边
}

int main(){
    int x , y;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>x>>y;
        map[x][y] ++;
        map[y][x] ++;
        //至于为什么是 map[][]++我们等下会给出一组数据
        du[x]++;
        du[y]++;
        m = max(x , m);
        m = max(m , y);
        //寻找最大的边
    }
    //找奇数边
    for(int i = 1 ; i <= m ; i ++) {
           if(du[i] % 2 == 1){
               start = i;
               break;
           }
    }
    //如果没有奇点，就找最小的为偶数度的节点，因为如果存在欧拉回路，要输出500进制下最小的组解
    if(start == 0){
        for(int i = 1 ; i <= m ; i ++){
            if(du[i] > 0){
                start = i;
                break;
            }
        }
    } 
    dfs(start);
    for(int i = tot ; i >= 1 ; i--){
        //最后几个87分是最坑的，题目中让%500，但是500%500=0
        //一个点就是这么坑，500不取模，所以让边大于500再%500
        if(ola[i]>500)
        ola[i] %= 500;
        cout<<ola[i]<<endl;
    }
    //结束
    return 0;
}