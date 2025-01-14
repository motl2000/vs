#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[20];
int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int U=1<<n;                             //U=2^n
	
	for(int S=0;S<U;S++)                    //枚举S的所有子集
	{
		if( __builtin_popcount(S)==m )      //__builtin_popcount(S)表示S中1的个数
		{
			for(int i=0;i<n;i++)            //输出S中的元素
			{
				if( S&(1<<i) )              //S中包含第i个元素
                {
                    cout<<a[i]<<" ";
                }
			}
			
			cout<<endl;
		}
	}
	
	return 0;
}