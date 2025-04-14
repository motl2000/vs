//【例6.6】整数区间
//本题理解上容易混乱，要求是求一个数字集合，不是一个数字区间，比如例题中，最终结果是(2,4)两个数字，所以结果为2个数字。
//贪心1，从左往右找重叠区间
//，按开始数字从小到大排序，如果开始数字相同，按结束数字从小到大排序，然后依次遍历
//，如果下一个区间不与当前区间重叠，就说明需要一个新的数去表示，否则就说明下一个区间与当前区间重叠，不需要新的数去表示，只需要更新当前区间。
// #include <bits/stdc++.h>
// using namespace std;
// int n,ans=1;							//n为区间个数，ans为最终结果，默认需要一个数字
// struct act{
// 	int start;
// 	int end;
// } a[1001];
// bool compare(act x,act y){				//比较函数，按开始数字从小到大排序，如果开始数字相同，按结束数字从小到大排序
// 	if (x.start<y.start)
// 		return true;
// 	if (x.start==y.start&&x.end<y.end)
// 		return true;
// 	return false;
// }
// int main() {
// 	cin>>n;
// 	for (int i=0;i<n;i++){
// 		cin>>a[i].start>>a[i].end;
// 	}
// 	sort (a,a+n,compare);			//排序
// 	int s,e;						//s为当前区间开始，e为当前区间结束
// 	s=a[0].start;
// 	e=a[0].end;
// 	for (int i=1;i<n;i++){
// 		if (a[i].start>e){          //如果下一个区间不与当前区间重叠，就说明需要一个新的数去表示
// 			ans++;                  
// 			s=a[i].start;
// 			e=a[i].end;
// 		}
// 		else{                       //否则就说明下一个区间与当前区间重叠，不需要新的数去表示，只需要更新当前区间
// 			s=a[i].start;			//更新重叠区间
// 			if (a[i].end<e){		
// 				e=a[i].end;
// 			}
// 		}
// 	}
// 	cout<<ans;

// 	return 0;
// }

//贪心2，从右往左找重叠区间
//这个方法更简洁，只需要保持一个最右端点，上面的方法要保持一个区间
#include<bits/stdc++.h>
using namespace std;
struct Sec
{
	int l, r;//l：区间左端点 r：区间右端点 
};
bool cmp(const Sec &a, const Sec &b)
{//右端点更小的排在前面，右端点相同则左端点更小的在前面 
    return a.r < b.r || a.r == b.r && a.l < b.l;
}
int main()
{
    Sec s[10005];
   	int n, ct = 0, lastR = -1;//lastR:上一个选择的右端点 ct:选择的数字个数
   	cin >> n;
	for(int i = 1; i <= n; ++i)
   		cin >> s[i].l >> s[i].r;
   	sort(s+1, s+1+n, cmp);
	for(int i = 1; i <= n; ++i) 
		if(s[i].l > lastR)	//如果当前区间的左端点大于当前最右端点，就说明要选择一个新的数字来处理新的重叠区间
		{
			ct++;
			lastR = s[i].r;   
		}
    cout << ct;
    return 0;
}
