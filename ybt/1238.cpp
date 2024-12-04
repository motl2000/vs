//一元三次方程求解
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int x;
double a,b,c,d,x1,x2,xx;
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
int main(){
    cin>>a>>b>>c>>d;
    for (x=-100;x<=100;x++){
        x1=x;
        x2=x+1;
        if (f(x1)==0){
            cout<<fixed<<setprecision(2)<<x1<<' ';
        }
        else if (f(x1)*f(x2)<0){                    //说明x1和x2之间有根
            while (x2-x1>0.001){                    //提高精度
                xx=(x1+x2)/2;                       //二分法
                if (f(xx)*f(x1)<0){                 //根在x1和xx之间
                    x2=xx;                          //更新x2
                }
                else{
                    x1=xx;                          //根在xx和x2之间
                }
            }
            cout<<fixed<<setprecision(2)<<xx<<' ';  //输出根
        }
    }
    return 0;
}