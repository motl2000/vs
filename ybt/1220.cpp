//单词接龙
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[101];
int n,ans;
int a[101];                             //记录第i个单词被使用的次数
bool check(string x,string y,int k){    //判断x的后k位是否与y的前k位相同
    int lenx=x.length();
    for (int i=0;i<k;i++)
        if (x[lenx-k+i]!=y[i])
            return false;
    return true;
}
void link(string &x,string y,int k){    //连接x与y的前k位
    int leny=y.length();
    for (int i=k;i<leny;i++)
        x+=y[i];
}
void dfs(string ss){
    ans=max(ans,(int)ss.length());       //必须要强制转换，否则会出现错误
    for(int i=1;i<=n;i++){
        if (a[i]>=2)                     //每个单词最多使用两次
            continue;
        for (int j=1;j<=s[i].length();j++){
            if (check(ss,s[i],j)){      //判断能否连接
                string t=ss;
                link(t,s[i],j);       //连接
                if (t==ss)            //如果连接后与原字符串相同，说明前后两个单词相互包含，需要跳过当前单词
                    continue;
                a[i]++;
                dfs(t);
                a[i]--;
            }
        }
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    string ss;
    cin>>ss;
    dfs(ss);
    cout<<ans;
    return 0;
}