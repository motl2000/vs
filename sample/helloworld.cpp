#include <bits/stdc++.h>
using namespace std;
int a,b[1000000];
int main()
{
	cin>>a;
	if(a%2==1){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(j==0||j==a-1)
                    cout<<"+";
                else if(i==j)
                    cout<<"+";
                else
                    cout<<"-";
                }
            cout<<endl;
        }
    }
	return 0;
}