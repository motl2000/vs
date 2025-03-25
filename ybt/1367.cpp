//1367：查找二叉树(tree_a)
//已知一棵二叉树用邻接表结构存储，中序查找二叉树中值为x的结点，并指出是第几个结点。
#include <iostream>
using namespace std;
struct Node {
    int l, r, v;
} a[1001];
int n, k, cnt;
void dfs(int x) {                               //中序遍历,x为当前结点编号
    if (x == 0)                                 //如果是空结点，返回
        return;
    dfs(a[x].l);                                //左子树
    cnt++;                                      //访问到子树的根节点，计数
    if (a[x].v == k){                            //如果找到了k，输出
        cout << cnt << endl;
        return;
    }
    dfs(a[x].r);
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i].v >> a[i].l >> a[i].r;      //读入数据，并建树
    cnt = 0;
    dfs(1);                                     //从根节点开始查找
    return 0;
}