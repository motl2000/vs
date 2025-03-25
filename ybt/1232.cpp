//Crossing River
#include <iostream> 
#include <algorithm>
using namespace std;
int t,n,a[1001];
int main(){
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        for (int j=0;j<n;j++)
            cin>>a[j];
        sort(a,a+n);
        int ans=0;
        while (n>3){
            int t1=a[0]+a[1]*2+a[n-1];          //最快的两个人先过河，然后最快的人回来，最慢的两个人过河，然后第二快的人回来，这样最慢的人带走次慢的人
            int t2=a[0]*2+a[n-2]+a[n-1];        //最快的人和最慢的人过河，然后最快的人回来，每次都是最快的人和最慢的人过河
            ans+=min(t1,t2);
            n-=2;
        }
        if (n==1)                               //如果只有一个人，
            ans+=a[0];
        else if (n==2)                          //如果只有两个人
            ans+=a[1];
        else if (n==3)                          //如果只有三个人
            ans+=a[0]+a[1]+a[2];                //最快的两个人过河，然后最快的人回来，最慢的两个人过河
        cout<<ans<<endl;
    }
    return 0;
}