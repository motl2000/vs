//1571：【例 3】凸多边形的划分
//注意要用高精度
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 65;
inline void qread(int &x) {
	x = 0;
	register int ch = getchar();
	while(ch < '0' || ch > '9')    ch = getchar();
	while(ch >= '0' && ch <= '9')    x = 10 * x + ch - 48, ch = getchar();
}
struct bignum {
	int num[40];
	bignum() {
		num[0] = 1;
	}
	void set(int x) {
		memset(num, 0, sizeof(num));
		while(x) {
			num[++num[0]] = x % 10;
			x /= 10;
		}
		if(!num[0])    num[0] = 1;
	}
	void clear() {
		memset(num, 0, sizeof(num));
		num[0] = 1;
	}
	void INF() {
		num[0] = 30;
		num[num[0]] = 9;
	}
};
bignum minn(const bignum &a, const bignum &b) {
	if(a.num[0] > b.num[0])    return b;
	if(a.num[0] < b.num[0])    return a;
	for(int i = a.num[0]; i >= 1; --i) {
		if(a.num[i] > b.num[i])    return b;
		if(a.num[i] < b.num[i])    return a;
	}
	return a;
}
bignum add(bignum a, bignum b) {
	bignum c;
	c.clear();
	c.num[0] = max(a.num[0], b.num[0]);
	int jw = 0;
	for(int i = 1; i <= c.num[0]; ++i) {
		c.num[i] = a.num[i] + b.num[i] + jw;
		jw = c.num[i] / 10;
		if(jw)    c.num[i] -= 10;
	}
	if(jw)    c.num[++c.num[0]] = jw;
	return c;
}
bignum mul(bignum a, bignum b) {
	bignum c;
	c.clear();
	c.num[0] = a.num[0] + b.num[0];

	for(int i = 1; i <= a.num[0]; ++i) {
		int jw = 0;
		for(int j = 1; j <= b.num[0]; ++j) {
			c.num[i + j - 1] += a.num[i] * b.num[j] + jw;
			jw = c.num[i + j - 1] / 10;
			c.num[i + j - 1] %= 10;
		}
		c.num[i + b.num[0]] = jw;
	}
	while(c.num[c.num[0]] == 0)
		--c.num[0];
	if(!c.num[0])    c.num[0] = 1;
	return c;
}
void show(const bignum &a) {
	for(int i = a.num[0]; i >= 1; --i)
		putchar(a.num[i] + 48);
}
int n;
bignum data[maxn << 1];
bignum dp[maxn << 1][maxn << 1];//将多边形顶点 i 到顶点 j 组成的多边形划分的最小代价
int main(void) {
	qread(n);
	for(int i = 1; i <= n; ++i) {
		int x;
		qread(x);
		data[i].set(x);
		data[i + n] = data[i];// 复制一份，处理环形
	}
	data[n << 1 | 1] = data[1];
	for(int i = 1; i < n; i++)
		dp[i][i + 1].set(0);
	for(int i = 2; i < n; i++)              // 枚举区间长度
		for(int j = 1; j <= n - i; j++) {   // 枚举起点
			dp[j][j + i].INF();             // 初始化为无穷大
			for(int k = j + 1; k < i + j; k++)// 枚举划分点
				dp[j][j + i] = minn(dp[j][j + i], add(add(dp[j][k], dp[k][j + i]),
                mul(mul(data[i + j], data[j]), data[k])));//新增三角形的代价： data[i+j] × data[j] × data[k]

		}
	show(dp[1][n]);
}

