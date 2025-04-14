//1351：【例4-12】家谱树
//这题他们放错地方了，应该属于拓扑排序。
//输入：第1行一个整数N（1≤N≤100），表示家族的人数；接下来N行，第i行描述第i个人的儿子；每行最后是0表示描述完毕。
//输出：输出一个序列，使得每个人的后辈都比那个人后列出；如果有多解输出任意一解。
#include<bits/stdc++.h>
using namespace std;
int a[101][101],c[101],r[101],ans[101]; //a[i][j]表示第i个人第j个儿子，c[i]表示第i个人有几个儿子，r[i]表示第i个人有几个祖先，ans[i]模拟一个堆
int tot,temp,num,n,b;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        do{
            cin>>b;
            if (b!=0){
                c[i]++;
                a[i][c[i]]=b;
                r[b]++;
            }
        }while(b!=0);
    }
    for (int i=1;i<=n;i++){             //找根
        if (r[i]==0){
            ans[++tot]=i;               
        }
    }
    do{
        temp=ans[tot];                  //输出根
        cout<<temp<<" ";
        tot--;
        num++;
        for (int i=1;i<=c[temp];i++){   //找根的后代
            r[a[temp][i]]--;            //后代的祖先数减1
            if (r[a[temp][i]]==0){      //如果后代没有祖先了
                ans[++tot]=a[temp][i];  //加入根的后代
            }
        }
    }while(num!=n);
    return 0;
}
