//B3850 [GESP202306 四级] 幸运数
#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
//如果数字乘以7后的数字大于9，则将乘积的各个位数相加，如果还大于9，就继续将该和的各个位数相加，直到和小于9
int convert(int k){
    //如果数字乘以7后的数字大于9
//    if (a[k]>0)
//    	return a[k];
    int num=0;
    if (k*7>9){
        //将乘积的各个位数相加
        int sum=0;
        int kk=k*7;
        while (kk>0){
            sum+=kk%10;
            kk/=10;
        }
        //如果还大于9
        while (sum>9){
            //就继续将该和的各个位数相加
            int temp=sum;
            sum=0;
            while (temp>0){
                sum+=temp%10;
                temp/=10;
            }
        }
        num=sum;
    }
    else{
        num=k*7;
    }
//    a[k]=num;
    return num;
}
void lucky(string s){
    //从最后开始找奇数位
    long long ans=0;
    for (int i=s.size(),j=1;i>=1;i--,j++){
        int k=s[i-1]-'0';
        if (j%2==1){
            ans+=convert(k);
        }
        else
        	ans+=k;
 
    }
    if (ans%8==0){
        cout<<"T"<<endl;
    }
    else{
        cout<<"F"<<endl;
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        lucky(s);
    }
    return 0;
}