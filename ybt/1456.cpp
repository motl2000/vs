//1456：【例题2】图书管理
#include<bits/stdc++.h>
using namespace std;
 
int main(){
int t;
cin>>t;
unordered_set<string>s1;    
for(int i=1;i<=t;i++){
    string s;
    cin>>s;
    if(s=="add"){
        string a;
        getline(cin,a);
        s1.insert(a);
    }
    else{
        string b;
        getline(cin,b);
        if(s1.find(b)==s1.end()){//s1.end()表示s1中没有b这个元素
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }
    }
}
    return 0;
}
