#include<bits/stdc++.h>
using namespace std;

struct Lb {
    int id, data, next;
}lb[100000];

int main() {

    int n, begin;
    cin >> begin >> n;
    vector<Lb> v1, v2;
    for (int i = 0; i < n; i++) {
        int id, data, next;
        cin >> id >> data >> next;
        lb[id] = { id,data,next };
    }
    while (begin != -1) {
        v1.push_back(lb[begin]);
        begin = lb[begin].next;
    }

    int l = 0, r = v1.size() - 1;
    while (1) {
        v2.push_back(v1[r]);
        r--;
        if (l - r == 1) {
            break;
        }
        v2.push_back(v1[l]);
        l++;
        if (l - r == 1) {
            break;
        }
    }

    for (int i = 0; i < v2.size(); i++) {
        if (i + 1 != v2.size()) {
            printf("%05d %d %05d\n", v2[i].id, v2[i].data, v2[i + 1].id);
        }
        else {
            printf("%05d %d -1\n", v2[i].id, v2[i].data);
        }
    }
}