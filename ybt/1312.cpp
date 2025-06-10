//1312：【例3.4】昆虫繁殖
#include <iostream>

using namespace std;
int x,y,z;
long long a[51],b[51];          //a[i]表示第i个月成虫的数量，b[i]表示第i个月产卵的数量
int main() {
	cin>>x>>y>>z;
	//初始化第一轮的成虫数量为1 
	for (int i=1;i<=x;i++){
		a[i]=1;
	}
	//从x+1个月开始产卵，要计算z个月后，所以是z+1 
	for (int i=x+1;i<=z+1;i++){
		b[i]=y*a[i-x];           //第i个月产卵的数量等于第i-x个月的成虫数量乘以y
		a[i]=a[i-1]+b[i-2];      //第i个月成虫的数量等于第i-1个月的成虫数量加上第i-2个月的产卵数量
        cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
	}
	cout<<a[z+1];
	return 0;
}