//3428：【例74.3】 彼得·潘框架
#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    cin >> n;
    //输出第一行
    for(int i = 1; i <=n.size(); i++) {
        if (i%3!=0) {
            cout << "..#.";
        } else {
            cout << "..*.";
        }
    }
    cout <<"."<< endl;
    //输出第二行
    for(int i = 1; i <=n.size(); i++) {
        if (i%3!=0) {
            cout << ".#.#";
        } else {
            cout << ".*.*";
        }
    }
    cout <<"."<< endl;
    //输出第三行
    for(int i = 1; i <=n.size(); i++) {
        if (i%3!=0) {
            //如果是第3n+1个数，先输出*，否则输出#
            if (i>1&&i%3==1) {
                cout << "*."<<n[i-1]<<".";
            } else {
                cout << "#."<<n[i-1]<<".";
            }
        } else {
            cout << "*."<<n[i-1]<<".";
        }
    }
    if (n.size()%3==0) {
        cout << "*";
    } else {
        cout << "#";
    }
    cout << endl;
    //输出第四行
    for(int i = 1; i <=n.size(); i++) {
        if (i%3!=0) {
            cout << ".#.#";
        } else {
            cout << ".*.*";
        }
    }
    cout <<"."<< endl;
    //输出第五行
    for(int i = 1; i <=n.size(); i++) {
        if (i%3!=0) {
            cout << "..#.";
        } else {
            cout << "..*.";
        }
    }
    cout <<"."<< endl;


    return 0;
}