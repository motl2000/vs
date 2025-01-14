//膨胀的木棍，这是一道数学题
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double n,c,l;                           //n是升高的温度，c是膨胀系数，l是木棍的长度
int main(){
    cin>>l>>n>>c;
    double minv=0,maxv=acos(-1.0),midv; //acos(-1.0)是π，midv是要求的木棍中心的偏移值
    double l2=(1+n*c)*l;
    while (maxv-minv>1e-12){            //1e-12是1*10^-12
        midv=(maxv+minv)/2;
        if(2*l2/l>midv/sin(midv/2))    //2*l2/l是直径，midv/sin(midv/2)是弧长
            minv=midv;
        else
            maxv=midv;
    }
    cout<<fixed<<setprecision(3)<<l2/midv*(1-cos(midv/2))<<endl; //l2/midv是半径，1-cos(midv/2)是木棍的半径与半径的余弦值
}