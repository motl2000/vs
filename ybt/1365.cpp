//1365：FBI树(fbi)
#include <bits/stdc++.h>
using namespace std;
#define N 2050
struct Node
{
	char val;//结点类型，可以是'F', 'B', 或'I' 
	int left, right;
};
Node node[N];//结点池 
int n, p;
string s;
int createTree(string fs)               //根据FBI串fs构建二叉树，返回二叉树的根 
{
	int np = ++p;                       //新建结点
	if(fs.length() == 1)                //如果是叶子结点 
	{
		if(fs[0]=='1')                  //根据题意，1表示I，0表示B
			node[np].val='I';
		else 
			node[np].val='B';           
		return np;	                    //返回结点编号
	}
	string ls = fs.substr(0, fs.length()/2);        //分割字符串
    string rs = fs.substr(fs.length()/2);
	int lp = createTree(ls);                        //递归构建左子树
    int rp = createTree(rs);                        //递归构建右子树
	node[np].left = lp;                             //连接左右子树
    node[np].right = rp;                            //连接左右子树
	if(node[lp].val == node[rp].val)
		node[np].val = node[lp].val;                //如果二者相同，则为二者的值,I或B
	else
		node[np].val = 'F';                         //否则为F
	return np;
}
void postOrder(int r)                               //后序遍历输出
{
	if(r == 0)
		return;
	postOrder(node[r].left);
	postOrder(node[r].right);
	cout << node[r].val;
}
int main()
{
	cin >> n >> s;
	int root = createTree(s);
	postOrder(root);
	return 0;
}