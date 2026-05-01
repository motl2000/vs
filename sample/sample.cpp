#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("test.txt");
    fout << "Happy" << endl;
    fout << "New Year";
    fout.close();

    ifstream fin("test.txt");
    string s1, s2;
    fin >> s1;
    getline(fin, s2);
    fin.close();

    cout << s1 << "|" << s2;
    return 0;
}
