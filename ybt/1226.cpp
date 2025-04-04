//装箱问题，注意这是一个二维的，不是三维的，所以只需要考虑箱子的长宽，不需要考虑高度
#include <iostream>
using namespace std;
int aa[4]={0,5,3,1};                //aa[i]表示i个3*3的箱子剩下的空间,
                                    //4k个3*3的箱子剩下空间能放0个2*2的箱子,
                                    //4k+1个3*3的箱子剩下空间能放5个2*2的箱子,
                                    //4k+2个3*3的箱子剩下空间能放3个2*2的箱子,
                                    //4k+3个3*3的箱子剩下空间能放1个2*2的箱子
int main(){
    int a,b,c,d,e,f;                //a,b,c,d,e,f分别表示1*1,2*2,3*3,4*4,5*5,6*6的箱子的个数
    while(cin>>a>>b>>c>>d>>e>>f){
        if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
            break;
        int ans=f+e+d+(c+3)/4;      //先把6*6的箱子装满，然后把5*5的箱子装满，然后把4*4的箱子装满，然后把3*3的箱子装满
        int b2=5*d+aa[c%4];         //计算上面放完6*6,5*5,4*4,3*3的箱子后，已经打开的箱子里剩下的可以放2*2的箱子空间
                                    //5*d表示4*4的箱子剩下的空间能放多少个2*2的箱子，因为4*4的箱子剩下的空间够放5个2*2的箱子
                                    //aa[c%4]表示3*3的箱子剩下的空间能放多少个2*2的箱子
        if(b>b2)                    //如果2*2的箱子的个数大于剩下的空间能放的2*2的箱子的个数
            ans+=(b-b2+8)/9;        //那么就把可以放2*2的箱子的空间装满，+8是为了向上取整，因为如果多出1个2*2的箱子，那么就需要多一个新的箱子
        int b1=36*ans-36*f-25*e-16*d-9*c-4*b;   //计算剩余可以放1*1的空间，36*ans表示已经打开的箱子的总空间
                                                //36*f表示6*6的箱子的空间，25*e表示5*5的箱子的空间，16*d表示4*4的箱子的空间，9*c表示3*3的箱子的空间，4*b表示2*2的箱子的空间

        if(a>b1)
            ans+=(a-b1+35)/36;      //如果1*1的箱子的个数大于剩下的空间能放的1*1的箱子的个数，那么就把可以放1*1的箱子的空间装满
        cout<<ans<<endl;
    }
    return 0;
}