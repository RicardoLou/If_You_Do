#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    map<string, string> sjb;
    //map存储键值对，自动按照key(键)升序排序；
    //first为键，second为值
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b >> b;
        sjb.insert({ a,b });
    }

    string start = "00:00:00";
    sjb.insert({ "23:59:59","" });
    for (auto x : sjb) {
        if (x.first > start) {
            cout << start << " - " << x.first << endl;
        }
        start = x.second;
    }

}