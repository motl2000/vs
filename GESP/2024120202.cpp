//4092：【GESP2412二级】数位和
#include <bits/stdc++.h>
long long s,ans;
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		long long sum=0;
		while(s!=0)
		{
			sum+=s%10;
			s=s/10;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}