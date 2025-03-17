#include<bits/stdc++.h>

using namespace std;
int main() {
    int a;
    cin >> a;
    string b[a];
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }
    int c;
    cin >> c;
    string d;
    getchar();
    getline(cin, d);
    int count = 0;
    for (int i = 0; i < a; i++) {
        while (d.find(b[i]) != string::npos) {
            count++;
            d.replace(d.find(b[i]), b[i].length(), "-");
        }
    }
    while (d.find('-') != string::npos) {
        d.replace(d.find('-'), 1, "<censored>");
    }
    if (count < c) {
        cout << d;
    }
    else {
        cout << count << endl << "He Xie Ni Quan Jia!";
    }
}