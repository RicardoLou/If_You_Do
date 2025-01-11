#include <bits/stdc++.h>
using namespace std;

int main() {
    string inputStr, outputStr = "", str;
    getline(cin, inputStr);
    getline(cin, str);

    for(char i : inputStr) {
        bool flag = true;
        for(char s : str) {
            if(i == s) {
                i ++;
                flag = false;
                break;
            }
        }
        if(flag) {
            outputStr += i;
        }
    }

    cout << outputStr;
}