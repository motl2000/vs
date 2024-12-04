//输出前k大的数，快排的思想，书上的例子过不了，以下代码可以预先将数据序列分为左右两部分，左边的比基准元素大，右边的比基准元素小
//这样就可以直接输出前k个数，不用再对左右两部分进行递归
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int k,n,a[N];
int partition(int l,int r){                             //快排的划分函数，返回基准元素的位置，基准元素的左侧都比它大，右侧都比它小
    while(l<r){
        while(l<r&&a[l]>=a[r])r--;                      //这里的等号是为了保证稳定性
        if(l<r){
            swap(a[l],a[r]);
            l++;
        }
        while(l<r&&a[l]>=a[r])l++;
        if(l<r){
            swap(a[l],a[r]);
            r--;
        }
    }
    return r;                                           //返回基准元素的位置
}
void quickSort(int l,int r){                                //优化的快排
    int benchmark=partition(l,r);                           //划分函数返回的是基准元素的位置
    if(benchmark-1>l)quickSort(l,benchmark-1);              //递归左右两部分
    if(benchmark<k&&r>benchmark+1)quickSort(benchmark+1,r); //这里的判断是为了减少递归次数，当基准元素的位置大于k时，右侧的元素不用再递归
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    cin>>k;
    quickSort(1,n);
    for(int i=1;i<=k;i++)
        printf("%d\n",a[i]);
    return 0;
}