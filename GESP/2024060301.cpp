//4061：【GESP2406三级】移位
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fl=0;
    for(int i=0;i<26;i++){
        int j = (i+n)%26;
        char ch = 'A'+j;
        cout<<ch;
    }
    cout<<"\n";
}