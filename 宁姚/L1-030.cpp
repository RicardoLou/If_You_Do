#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<string> man, woman;
    cin >> n;

    vector<int> flag(n);
    for(int i = 0; i < n; i++) {
        string name;
        cin >> flag[i] >> name;
        if(flag[i] == 0) {
            woman.push_back(name);
        }else {
            man.push_back(name);
        }
    }

    while(!man.empty() && !woman.empty()) {
        if(flag.front() == 0) {
            cout << woman.front() << " " << man.back() << endl;
            woman.erase(woman.begin());
            man.pop_back();
        }else {
            cout << man.front() << " " << woman.back() << endl;
            man.erase(man.begin());
            woman.pop_back();
        }
        flag.erase(flag.begin());
    }
}