//4091：【GESP2412二级】寻找数字
#include <bits/stdc++.h>
using namespace std; 
int a,b;
int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)//逐个判断。 
	{
		scanf("%d",&a);
		b=0;
		for(int j=1;j<=a;j++)//确定b的值 
		{
			if(b*b*b*b>=a)//如果b的四次方等于a: 
			{
				break;//跳出循环。 
			 } 
			else
			{
				b++;//将b自增1。 
			}
		}
		if(b*b*b*b==a)//如果b的四次方等于a:
		{
			printf("%d\n",b);//输出b。 
		}
		else
		{
			printf("-1\n");//输出-1。 
		}
	}
	return 0;
}