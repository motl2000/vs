//2087：【22CSPJ普及组】解密(decode)
//根据题面给的m=n−e×d+2，结合p*q=n；
//可推出m=p*q-(p*q-p-q+1+1)+2,即m=-(p+q)
//因此，给定 p*q = n 和 p + q =-m,由韦达定理，可以知道p，q为一元二次方程x^2-mx+n=0的两个根
//我们只需要验证这两个根都大于0，且满足p×q=n，那么两个根就是结果
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int k;
    long long n, d, e, m;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        scanf("%lld %lld %lld", &n, &d, &e);//不能用cin\cout,会超时
        m = n - e * d + 2;
        long long p, det;
        det = m * m - 4 * n;//德尔塔=b^2-4*a*c;
        if (det < 0) {//德尔塔小于零则无解
            printf("NO\n");
            continue;
        } else {
            p = (m - sqrt(det)) / 2;//较小的那个解
            if (p * (m - p) == n && p > 0)
                printf("%lld %lld\n", p, m - p);
            else
                printf("NO\n");
        }
    }
    return 0;
}

//二分查找也可以AC
// #include<bits/stdc++.h>
// using namespace std;
// int k;
// int main()
// {
// 	//freopen("decode.in","r",stdin);
// 	//freopen("decode.out","w",stdout);
// 	scanf("%d",&k);
// 	for(int i=1;i<=k;i++)
// 	{
// 		long long n,d,e;
// 		scanf("%lld %lld %lld",&n,&d,&e);
// 		long long s=n-d*e+2;
// 		long long r=(n-d*e+2)/2,l=1;
// 		while(l<r)
// 		{
// 			int mid=(l+r)/2;
// 			if(mid*(s-mid)>=n)
// 			{
// 				r=mid;
// 			}
// 			else
// 			{
// 				l=mid+1;
// 			}
// 		}
// 		if(l*(s-l)==n)
// 		{
// 			printf("%lld %lld\n",l,(s-l));
// 		}
// 		else
// 		{
// 			printf("NO\n");
// 		}
		
// 	}
	
// 	return 0;
// }