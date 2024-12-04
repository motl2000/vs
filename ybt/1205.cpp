//汉诺塔问题
#include <cstdio>       //用cin和cout会超时
using namespace std;
int n;
void hanoi(int n,char a,char b,char c){
    if (n==0)
        return;

    hanoi(n-1,a,c,b);
    printf("%c->%d->%c\n",a,n,b);
    hanoi(n-1,c,b,a);
}
int main(){
    char x,y,z;
    scanf("%d %c %c %c",&n,&x,&y,&z);
    hanoi(n,x,y,z);
    return 0;
}