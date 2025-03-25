//1364：二叉树遍历(flist)
//树和二叉树基本上都有先序、中序、后序、按层遍历等遍历顺序，给定中序和其它一种遍历的序列就可以确定一棵二叉树的结构。
//假定一棵二叉树一个结点用一个字符描述，现在给出中序和按层遍历的字符串，求该树的先序遍历字符串。
#include <iostream>
#include <cstring>
using namespace std;
string in,level;                            //int中序遍历 level层序遍历
void preorder(int l1,int r1,int l2,int r2){ //l1,r1表示中序遍历的区间，l2,r2表示层序遍历的区间
	int pos;
	for(int i=l2;i<=r2;i++){                //遍历层序遍历
		int flag=0;                         //标记是否找到根
		for(int j=l1;j<=r1;j++){            //在当期的中序遍历区间中找当前节点
			if(level[i]==in[j]){            //如果找到当前节点，说明当前节点在当前的中序遍历区间中，且应该是根
				cout<<in[j];                //由于是要输出先序序列，所以直接输出根
				pos=j;                      //记录根的位置
				flag=1;                     //标记找到根
				break;
			}
		}
		if(flag)                            //找到根，跳出循环，一个根只能找一次      
            break;
	}
	if(pos>l1) preorder(l1,pos-1,l2,r2);    //递归中序遍历左子树
	if(pos<r1) preorder(pos+1,r1,l2,r2);    //递归中序遍历右子树
}
int main()
{
	cin>>in>>level;
	preorder(0,in.length()-1,0,level.length()-1);	
    return 0;
}