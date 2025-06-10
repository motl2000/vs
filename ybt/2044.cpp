//2044：【例5.12】回文字串
//输入一串字符,字符个数不超过100,且以“.”结束。 判断它们是否构成回文。
#include<iostream>
using namespace std;
int main()
{
    char a[101];
    cin>>a;
    int i=0,j=0;
    while(a[i]!='.')
        i++;
    i--;
    while(a[j]==a[i]&&j<i)
    {
        j++;
        i--;
    }
    if(j>=i)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}