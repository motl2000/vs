#include <bits/stdc++.h>
using namespace std;
string s[4]={"0000","0110","0110","0000"};
string ins[100];
bool check(int x,int y){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (ins[x+i][y+j]!=s[i][j]) 
                return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    int n,m;
    for (int i=0;i<t;i++){
        cin>>n>>m;
        for (int j=0;j<n;j++){
            cin>>ins[j];
        }
        bool flag=false;
        for (int j=0;j<n-3;j++){
            for (int k=0;k<m-3;k++){
                if (check(j,k)){
                    flag=true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}










