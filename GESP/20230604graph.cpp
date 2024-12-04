//B3851 [GESP202306 四级] 图像压缩
#include <bits/stdc++.h>
using namespace std;
int n,a[16],b[256];
string s[21];
//十六进制转十进制
int HtoTen(char c1,char c2){
    int x=0;
    if (c1>='0'&&c1<='9'){
        x+=(c1-'0')*16;
    }
    else{
        x+=(c1-'A'+10)*16;
    }
    if (c2>='0'&&c2<='9'){
        x+=(c2-'0');
    }
    else{
        x+=(c2-'A'+10);
    }
    return x;
}
//找距离最近的数
int GetNum(int x){
    int y=INT_MAX;
    int mi=0;
    for (int i=0;i<16;i++){
        int temp=abs(a[i]-x);
        if (temp<y){
            y=temp;
            mi=i;
        }
    }
    return mi;
}
//十进制转十六进制
string TentoH(int x){
    string s;
    if (x/16>=10){
        s+=(x/16-10+'A');
    }
    else{
        s+=(x/16+'0');
    }
    if (x%16>=10){
        s+=(x%16-10+'A');
    }
    else{
        s+=(x%16+'0');
    }
    return s;
}
//1到15的十进制数转十六进制
string TentoH2(int x){
    string s;
    if (x>=10){
        s+=(x-10+'A');
    }
    else{
        s+=(x+'0');
    }
    return s;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    //从输入里把所有数在b中计数
    for (int i=0;i<n;i++){
        for (int j=0;j<s[i].length();j+=2){
            b[HtoTen(s[i][j],s[i][j+1])]++;
        }
    }
    //找出前16个最多的数放到a中
    for (int i=0;i<16;i++){
        int x=0;
        int mi=0;
        for (int j=0;j<256;j++){
            if (b[j]>x){
                x=b[j];
                mi=j;
            }
        }
        a[i]=mi;
        b[mi]=0;
    }
    
    //输出a的十六进制形式
    for (int i=0;i<16;i++){
        cout<<TentoH(a[i]);
    }
    cout<<endl;
    //把s中的做压缩
    for (int i=0;i<n;i++){
        for (int j=0;j<s[i].length();j+=2){
            cout<<TentoH2(GetNum(HtoTen(s[i][j],s[i][j+1])));
        }
        cout<<endl;
    }
}