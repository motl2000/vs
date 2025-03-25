//1199：全排列, 递归实现
//给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int vis[1001],ans[1001];
string s;
void dfs(int n){
	if (n==s.size()){
		for (int i=0;i<n;i++)
			printf("%c",ans[i]);
		printf("\n");
		return;
	}
		
	for (int i=0;i<s.size();i++){
		if (!vis[i]){
			vis[i]=1;
			ans[n]=s[i];
			dfs(n+1);
			vis[i]=0;
		}
	}
}
int main() {
	cin>>s;

	dfs(0);//从第0个开始 

	return 0;
}