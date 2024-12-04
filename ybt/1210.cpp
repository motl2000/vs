//因子分解，递归，如果该整数可以分解出因子a的b次方，当b大于1时，写做 a^b ；当b等于1时，则直接写成a
#include <iostream>
using namespace std;
int n;
void f(int y,int z){
    if (n%y!=0){
        if (z==1)
            cout<<y;
        else
            cout<<y<<"^"<<z;
        return;
    }
    n=n/y;
    f(y,z+1);
}
int main(){
    cin>>n;
    for (int i=2;i<=n&&n>1;i++){
        if(n%i==0){
            f(i,0);      
            if(n>1)
                cout<<"*";
        }
    }
    return 0;
}
