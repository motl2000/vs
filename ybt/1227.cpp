//Ride to Office，本题是一个模拟题，Charley到达办公室的时间就是陪伴人最快到达办公室的时间
//，所以我们只需要计算每个人到达办公室的时间，然后取最小值即可。
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=1;
    while (cin>>n&&n!=0){
        int v,t,ans=INT_MAX;
        while(n--){
            cin>>v>>t;
            if (t>=0){
                double Time=4.5/v*3600;     //计算到达时间，注意单位换算，将公里/小时转换成公里/秒        
                if (Time-(int)Time>0)       //Time向上取整
                    Time++;
                if (Time+t<ans)             //如果到达时间加上等待时间小于ans，那么就更新ans
                    ans=Time+t;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}