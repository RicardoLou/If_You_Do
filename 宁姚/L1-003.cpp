#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int counts[10] = {0};
    vector<int> digits;
    cin >> n;
    while(n > 0) {
        int t = n % 10;
        if(counts[t] == 0) {
            digits.push_back(t);
        }
        counts[t] ++;
        n /= 10;
    }

    sort(digits.begin(), digits.end());

    for(int d : digits) {
        cout << d << ":" << counts[d] << endl;
    }

    return 0;
}