//1366：二叉树输出(btout)
//输入：两行，每行是由字母组成的字符串（一行的每个字符都是唯一的），分别表示二叉树的先序遍历和中序遍历的序列。
//输出：用树的凹入表示法输出该二叉树
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string s1,s2;
int c[205];                                     //c[i]表示以s1[i]为根的子树的结点个数
int build(int l1,int r1,int l2,int r2){         //l1,r1表示先序遍历的区间，l2,r2表示中序遍历的区间
	if(l1==r1){                                 //到达叶子
		c[l1]=1;
        return c[l1];
	}
	int p=s2.find(s1[l1]);                      //找到根节点在中序遍历中的位置
	if(p>l2)                                    //递归左子树
        c[l1]+=build(l1+1,l1+p-l2,l2,p-1);          
	if(p<r2)                                    //递归右子树
        c[l1]+=build(l1+p-l2+1,r1,p+1,r2);
	return c[l1];                               //返回以l1为根的子树的结点长度
}
int main()
{
	cin>>s1>>s2;
	build(0,s1.length()-1,0,s2.length()-1);     //建树
	for(int i=0;i<s1.length();i++){
		for(int j=1;j<=c[i];j++)                //根据节点长度输出当前节点字母
            cout<<s1[i];
		cout<<endl;
	}
    return 0;
}