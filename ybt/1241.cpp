//二分法求函数的零点
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double x;
double f(double x){
    return x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
}
int main(){
    //在区间[1.5,2.4] 有且只有一个根，请用二分法求出该根。要求四舍五入到小数点后6位。
    double l=1.5,r=2.4;
    while (r-l>1e-6){                       //精度要求  
        x=(l+r)/2;                          //二分法，近似逼近根
        if (f(x)*f(l)<0){
            r=x;
        }
        else{
            l=x;
        }
    }
    cout<<fixed<<setprecision(6)<<x;
    return 0;
}