#include<bits/stdc++.h>
using namespace std;

int main() {

    string hhmm;
    cin >> hhmm;
    int hh = stoi(hhmm.substr(0, 2));
    int mm = stoi(hhmm.substr(3, 2));
    if (hh > 12) {
        for (int i = 0; i < hh - 12; i++) {
            cout << "Dang";
        }
        if (mm > 0) {
            cout << "Dang";
        }
    }
    else {
        cout << "Only " << hhmm << ".  Too early to Dang.";
    }


}