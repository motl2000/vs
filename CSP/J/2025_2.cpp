//CSP J 2025 座位（seat）
#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
    cin>>n>>m;
    int t=0;

    for (int i = 1; i <= n*m; ++i){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,greater<int>());   //按成绩倒序排序
    int k=0;
    for (int i = 1; i <= n*m; ++i){     //找到小R的排名
        if (a[i]==t){
            k=i;
            break;
        }
    }
    if (k%n==0){                        //如果排名正好是行的整数
        if (k/n%2==0){                  //偶数列就在第一行
            cout<<k/n<<" "<<1<<endl;
        }else{                          //奇数列就在第一行
            cout<<k/n<<" "<<n<<endl;
        }        
    }
    else{                               //如果排名不是行的整数
        if (k/n%2==0){                  //如果前面是偶数列，就在k%n行
            cout<<k/n+1<<" "<<k%n<<endl;
        }else{                          //如果前面是奇数列，就在n-k%n+1行
            cout<<k/n+1<<" "<<n-k%n+1<<endl;
        }
    }
}