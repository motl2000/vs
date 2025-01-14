//单向链表
//输入：第一行一个整数 q 表示操作次数。接下来 q 行，每行表示一次操作
//1 x y ：将元素 y 插入到值为x的节点后面；
//2 x ：询问值为x的节点后面的元素是什么。如果值为x的节点是最后一个元素，则输出 0；
//3 x：从表中删除值为x的节点后面的那个元素，不改变其他元素的先后顺序。
//以下代码仅为了联系单向链表的操作，实际上不需要链表，直接用数组即可
#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head;
int main(){
    int q;
    cin>>q;
    head=new node;
    head->data=1;
    head->next=NULL;
    while (q--){
        int op,x,y;
        cin>>op;
        if (op==1){
            cin>>x>>y;
            node *p=head;
            while (p!=NULL){
                if (p->data==x){
                    node *q=new node;
                    q->data=y;
                    q->next=p->next;
                    p->next=q;
                    break;
                }
                p=p->next;
            }
        }
        else if (op==2){
            cin>>x;
            node *p=head;
            while (p!=NULL){
                if (p->data==x){
                    if (p->next==NULL)
                        cout<<0<<endl;
                    else
                        cout<<p->next->data<<endl;
                    break;
                }
                p=p->next;
            }
        }
        else if (op==3){
            cin>>x;
            node *p=head;
            while (p!=NULL){
                if (p->data==x){
                    if (p->next!=NULL){
                        node *q=p->next;
                        p->next=q->next;
                        delete q;
                    }
                    break;
                }
                p=p->next;
            }
        }
    }
    return 0;
}
