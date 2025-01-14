//抓住那头牛
#include <iostream>
using namespace std;
int q[1000001],step[1000001],n,k;//q是队列，step是记录每个数的步数,书上的h[][]数组其实就是q和step，可读性差，容易混淆，又没有实际意义，所以我分成两个数组
bool v[1000001];
int main(){
    cin>>n>>k;
    q[1]=n;
    v[n]=true;
    int head=0,tail=1;
    while (head<tail) {
        head++;
        for (int i=1;i<=3;i++){
            int x=q[head];
            if (i==1)
                x++;
            if (i==2)
                x--;
            if (i==3)
                x*=2;
            if (x>=0&&x<=100000&&(!v[x]||step[x]>step[q[head]]+1)){        //这里是关键，如果这个数已经被访问过了，那么就要判断这个数的步数是否比之前的小，如果小就更新
                    tail++;
                    q[tail]=x;
                    step[x]=step[q[head]]+1;  
                    v[x]=true;
            }
        }
    }
    cout<<step[k]<<endl;
    return 0;
}