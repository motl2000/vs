//【例52.2】 序列倒置
#include <iostream>
using namespace std;
int a[10001];
int main(){
    //输入一串整数直到回车结束
    int n=0;
    while(cin >> a[n])
	{
        n++;
        if (cin.get() == '\n')
            break;
    }
    //倒序输出
    for (int i=n-1;i>=0;i--)
        cout<<a[i]<<" ";
    return 0;
}