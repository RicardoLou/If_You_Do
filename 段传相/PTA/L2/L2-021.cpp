#include<bits/stdc++.h>
using namespace std;

struct sj {
    string name;
    int bqs;
    set<int> id;
};

bool px(struct sj a, struct sj b) {
    if (a.id.size() == b.id.size()) {
        return a.bqs < b.bqs;
    }
    return a.id.size() > b.id.size();
}

int main() {

    int n;
    cin >> n;
    struct sj aa[n];
    for (int i = 0; i < n; i++) {
        cin >> aa[i].name >> aa[i].bqs;
        for (int j = 0; j < aa[i].bqs; j++) {
            int x;
            cin >> x;
            aa[i].id.insert(x);
        }
    }

    sort(aa, aa + n, px);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << aa[i].name;
        }
        else {
            cout << " " << aa[i].name;
        }
        if (i == 2) {
            break;
        }
    }
    if (n < 3) {
        for (int i = n; i < 3; i++) {
            cout << " -";
        }
    }
}