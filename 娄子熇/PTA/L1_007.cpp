#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') 
            cout << "fu ";
        else {
            cout << pinyin[s[i] - '0'];
            if (i != s.length() - 1) cout << " ";  // 输出空格，除非是最后一个字符
        }
    }
    cout << endl;
    return 0;
}