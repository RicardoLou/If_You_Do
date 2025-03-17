#include<bits/stdc++.h>
using namespace std;

class HB {
public:
    int sum = 0;
    int index = 0;
    int count = 0;

    HB() {}
};

HB hb[10001];

bool f(HB a, HB b) {
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    }
    else if (a.count != b.count) {
        return a.count > b.count;
    }
    else {
        return a.index < b.index;
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        hb[i].index = i;
        int k;
        cin >> k;
        while (k--) {
            int x;
            int p;
            cin >> x >> p;
            hb[x].sum += p;
            hb[x].count++;
            hb[i].sum -= p;
        }
    }

    sort(hb + 1, hb + n + 1, f);
    for (int i = 1; i <= n; i++) {
        printf("%d %.2f\n", hb[i].index, hb[i].sum * 0.01);
    }
}