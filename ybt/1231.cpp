//最小新整数
#include <iostream>
#include <string>
using namespace std;
int t;
int main(){
    cin>>t;
    for (int i=0;i<t;i++){
        string s;
        int k;
        cin>>s>>k;
        for (int j=0;j<s.length();j++){
            if (s[j]>s[j+1]){
                s.erase(j,1);
                k--;
                if (k==0)
                    break;
                j=-1;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
