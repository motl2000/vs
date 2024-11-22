//Pell数列
//给出一个正整数 k，要求Pell数列的第 k 项模上 32767是多少。
#include <iostream>
using namespace std;
int ans[1000001];
int pell(int n){
    if (ans[n]!=0){
        return ans[n];
    }    
    if (n==1){
        return ans[n]=1;
    }
    if (n==2){
        return ans[n]=2;
    }
    ans[n]=(2*pell(n-1)+pell(n-2))%32767;
    return ans[n];
}
int main(){
    for (int i=1;i<=1000000;i++){
        pell(i);
    }
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int m;
        cin>>m;
        cout<<ans[m]<<endl;
    }
    return 0;
}