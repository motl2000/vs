//【例72.2】 取出整数的一部分
#include <iostream>
#include <string>
using namespace std;
string n;
int k;
char a[10];
int main(){
    cin>>n>>k;
    int len=n.length();
    if (abs(k)>len) 
        cout<<"Error"<<endl;
    else if (k==0) 
        cout<<n<<endl;
    else{
        if (k>0)                    //正数直接输出
            for (int i=0;i<k;i++)
                cout<<n[i];
        else{                       //负数倒序输出
            int j=0;
            for (int i=len-1;i>=len-abs(k);i--){
                a[j]=n[i];
                j++;
            }
            //倒序输出a数组，去除前导0
            for (int i=abs(k)-1;i>=0;i--)
                if (a[i]!='0'){
                    for (int j=i;j>=0;j--)
                        cout<<a[j];
                    break;
                }
        }
    }
    return 0;
}