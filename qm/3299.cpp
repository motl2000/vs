//练50.2 卡牌游戏 II
#include <iostream>
using namespace std;
int n;
long long b;
int main(){
    cin>>n>>b;
    int i=0;
    for (;i<n&&b>0;i++){
        int a;
        cin>>a;
        b-=a;
        // if (b<0)
        //     break;
    }
    if (b>0)
        cout<<-1;
    else
        cout<<i;

}