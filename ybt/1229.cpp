//电池的寿命
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;   
    while (cin>>n){
        double sum=0;
        int max=0,a;
        for (int i=0;i<n;i++){
            cin>>a;
            if (a>max)
                max=a;
            sum+=a;
        }
        if (sum-max<max)//如果最大容量电池的时间大于所有其他电池的时间和，那么就是最大时间就是所有其他电池的时间和
            cout<<fixed<<setprecision(1)<<sum-max<<endl;
        else//否则最大时间就是所有电池的时间和的一半，因为需要两个电池
            cout<<fixed<<setprecision(1)<<sum/2<<endl;
    }
}