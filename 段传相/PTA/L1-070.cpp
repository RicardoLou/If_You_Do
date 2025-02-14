#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    getline(cin, s);
    int count1 = 1, flag = 0, count2 = 0;
    while (s != ".") {
        if (s.find("chi1 huo3 guo1") != string::npos) {
            count2++;
            if (flag == 0) {
                flag = count1;
            }
        }
        getline(cin, s);
        count1++;
    }
    if (count2 == 0) {
        cout << count1 - 1 << endl << "-_-#";
    }
    else {
        cout << count1 - 1 << endl << flag << ' ' << count2;
    }

}