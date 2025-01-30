#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<string> strs;
    string s, x;
    getline(cin, s);
    istringstream in(s);
    while (getline(in, x, ' ')) {
        strs.push_back(x);
    }

    string a = strs[0], b = strs[1];
    if (int(*a.c_str()) == 0) {
        a = "?";
    }
    if (int(*b.c_str()) == 0) {
        b = "?";
    }
    if (strs.size() > 2) {
        b = "?";
    }

    int f = 0;
    for (char i : strs[0]) {
        if (f == 0) {
            if (i == '0' || i == 0) {
                a = "?";
                break;
            }
        }
        f++;
        if (!(i >= '0' && i <= '9')) {
            a = "?";
            break;
        }
    }
    f = 0;
    for (char i : strs[1]) {
        if (f == 0) {
            if (i == '0' || i == 0) {
                b = "?";
                break;
            }
        }
        f++;
        if (!(i >= '0' && i <= '9')) {
            b = "?";
            break;
        }
    }

    // cout<<a<<' '<<int(*b.c_str())<<endl;
    if (a == "?" && b == "?") {
        cout << "? + ? = ?";
    }
    else if (a == "?" && b != "?") {
        if (stoi(b) > 1000) {
            cout << "? + " << '?' << " = ?";
        }
        else {
            cout << "? + " << stoi(b) << " = ?";
        }

    }
    else if (a != "?" && b == "?") {
        if (stoi(a) > 1000) {
            cout << '?' << " + ? = ?";
        }
        else {
            cout << stoi(a) << " + ? = ?";
        }
    }
    else {
        if (stoi(a) > 1000) a = "?";
        if (stoi(b) > 1000) b = "?";
        if (a == "?" || b == "?") {
            cout << a << " + " << b << " = " << "?";
        }
        else {
            cout << a << " + " << b << " = " << stoi(a) + stoi(b);
        }
    }

}