//1431：钓鱼
//以下代码是贪心，留意看看能不能用动态规划
#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
using namespace std;
int ans;
vector<int>fish,lesss,t;//每个湖第一个 5 分钟能钓到鱼的数量，每个湖每钓鱼5分钟较前5分钟钓的鱼数减少的数量，如题意
vector<int>walk,tmpfish;//从第一个湖走到第i个湖所需时间，每个湖的当前5分钟能钓到的鱼数

char ch;

inline int read()//快读（亦名读入优化）
{
    ans=0;
    ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+ch-'0',ch=getchar();
    return ans;
}

inline void init()//初始处理动态数组，因为希望动态数组的下标从1开始
{
    fish.push_back(0);
    lesss.push_back(0);
    t.push_back(0);
    walk.push_back(0);
    walk.push_back(0);//注意walk数组在主函数是从下标为2的开始处理的，因此需要多填一个0。
    tmpfish.push_back(0);
}//为什么要填0？为了与普通全局数组的性质相同（定义时默认全初始化为0）

int main()
{
    init();
    int n=read(),h=read()*12;       //1个小时代表12个5分钟
    for(int i=1;i<=n;i++) fish.push_back(read());
    for(int i=1;i<=n;i++) lesss.push_back(read());
    for(int i=1;i<n;i++) t.push_back(read());
    for(int i=2;i<=n;i++) walk.push_back(walk[i-1]+t[i-1]);//到每个湖的时间
    int mava,mapo,tmphours,matot=0;//当前贪心找到的最大值，当前贪心找到的最大值对应的下标（即湖的编号），当前纯钓鱼时间，最后的答案。
    for(int i=1;i<=n;i++) 
        tmpfish.push_back(0);
    for(int k=1;k<=n;k++)                   //尝试最远走到第k个湖
        if(h>walk[k])
        {
            tmphours=h-walk[k];//可用的纯钓鱼时间
            for(int i=1;i<=k;i++) 
                tmpfish[i]=fish[i];//初始化，先把每个湖第一个5分钟能钓到的鱼数存下来
            int sum=0;//记录的当佳佳最后停在第k个湖时的当前答案
            while(tmphours>0)
            {
                mava=-2000000000;           //当前贪心找到的可钓鱼的最大值
                mapo=0;
                for(int i=1;i<=k;i++)       //贪心选择,记录当前5分钟可以钓的最多的鱼
                    if(mava<tmpfish[i])     
                    {
                        mava=tmpfish[i];
                        mapo=i;             //记录当前所在的湖
                    }
                if(mava<=0) 
                    break;                  //没鱼可钓就直接退出
                sum+=mava;                  //钓鱼
                if(tmpfish[mapo]>lesss[mapo])   //如果钓完鱼这个湖还能钓鱼
                    tmpfish[mapo]-=lesss[mapo]; //钓完鱼，这个湖的鱼可钓的鱼减少
                else 
                    tmpfish[mapo]=0;            //否则这个湖不能钓鱼了
                tmphours--;                     //纯钓鱼时间减少
            }
            if(sum>matot) 
                matot=sum;                      //更新最大钓鱼数量
        }
        else break;
    printf("%d",matot);
    return 0;
}