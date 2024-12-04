//【例6.4】拦截导弹问题(Noip1999)
#include <iostream>
#include <algorithm>
using namespace std;
int a[101],ans;
int l[101];                             //l[i]表示第i套系统的最后一个导弹的高度 
int main(){
    //输入一串整数，以回车换行结束
    int n=1;
    while(cin >> a[n])
	{
        n++;
        if (cin.get() == '\n')
            break;
    }	
    int k=1;                            //k表示需要多少套系统
    l[k]=a[1];                          //第一套打第一个目标
    for (int i=2;i<=n;i++){
        int p=0;
        for (int j=1;j<=k;j++){         //遍历所有系统
            if (l[j]>=a[i]){            //如果当前系统可以打当前目标
                if (p==0)               //如果当前系统是第一个可以打当前目标的系统
                    p=j;
                else if (l[j]<l[p])     //如果当前系统比之前的系统更优
                    p=j;
            }
        }
        if (p==0){                      //如果没有系统可以打当前目标
            k++;                        //增加一套系统
            l[k]=a[i];                  //新的系统打当前目标
        }
        else
            l[p]=a[i];                  //当前系统打当前目标
    }
    cout<<k;
    return 0;
}