//区间合并
#include<iostream>
using namespace std;
const int N=10001;
bool a[N];                      //a[i]表示i是否在区间内
int n;
int main(){
    cin>>n;
    int minx=100000,maxx=-1;
    for (int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        for (int j=l;j<r;j++)   //将区间内的数标记为true,但最后一位不标记，因为这样可以处理尾首不重合的情况
                                //，如[1,3]和[3,5]合并为[1,5],但是[1,2]和[3,5]不能合并
            a[j]=true;
        minx=min(minx,l);
        maxx=max(maxx,r);
    }
    for (int i=minx;i<maxx;i++)
        if (!a[i]){
            cout<<"no";
            return 0;
        }
    cout<<minx<<' '<<maxx;
    return 0;
}
