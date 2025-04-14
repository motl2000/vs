//接水问题
#include <iostream>
using namespace std;
int m,n,a[10001],s[101];
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++){
        int min=0x7fffffff;
        int k=0;
        for (int j=0;j<m;j++)       //找到用时最少得水龙头,就是下一个要换人的水龙头
            if (s[j]<min){          
                min=s[j];
                k=j;
            }
        s[k]+=a[i];                 //把当前人分配到用时最少的水龙头
                
    }
    int max=0;
    for (int i=0;i<m;i++){          //找到用时最多的水龙头，就是接水的总用时
        if (s[i]>max)
            max=s[i];   
    }
    cout<<max<<endl;
}
