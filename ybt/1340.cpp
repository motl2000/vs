//1340：【例3-5】扩展二叉树
//我们把这样处理后的二叉树称为原二叉树的扩展二叉树，扩展二叉树的先序和后序序列能唯一确定其二叉树。
//输入：扩展二叉树的先序序列,扩展二叉树含义为：将二叉树的空结点用'·'补齐。
//输出：二叉树的中序和后序序列。
#include <iostream>
#include <string>
using namespace std;
struct TreeNode{
    char val;
    TreeNode *left;
    TreeNode *right;
};
string pre;
int pt;
TreeNode* build(){                          //递归建树
    if(pt>=pre.size()||pre[pt]=='.') 
        return NULL;
    TreeNode *root=new TreeNode;
    root->val=pre[pt];
    pt++;
    root->left=build();
    pt++;
    root->right=build();
    return root;
}
void inorder(TreeNode *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}
void postorder(TreeNode *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val;
}
int main(){
    cin>>pre;
    TreeNode *root=build();
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
