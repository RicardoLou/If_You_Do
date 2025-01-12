#include <bits/stdc++.h>
using namespace std;

int main() {

    int y, n;
    cin >> y >> n;
    for (int i = y; y <= 3000; i++) {
        vector<int> ns(4, 0);
        int a = i;
        int j = 1;
        while (a > 0) {
            ns.erase(ns.end() - j);
            ns.insert(ns.end() - j + 1, a % 10);
            a /= 10;
            j++;
        }
        sort(ns.begin(), ns.end());
        auto ns_un = unique(ns.begin(), ns.end());
        ns.erase(ns_un, ns.end());
        if (ns.size() == n) {
            cout << i - y << " " << setw(4) << setfill('0') << i;
            break;
        }
        ns.erase(ns.begin(), ns.end());
    }

}