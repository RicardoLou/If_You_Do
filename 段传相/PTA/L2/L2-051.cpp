#include<bits/stdc++.h>
using namespace std;

int n, counts = 0;//全局count会命名冲突，加个s解决
vector<set<int>> tree(100001, set<int>());

void qxbl(int a) {
    if (a) {
        if (counts == 1) {
            cout << a;
        }
        else {
            cout << ' ' << a;
        }
    }
    counts++;
    for (auto x : tree[a]) {
        qxbl(x);
    }

}


int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tree[x].insert(i);
    }

    int max = tree[1].size(), flag = 0;
    for (int i = 1; i <= n; i++) {
        if (tree[i].size() > max) {
            max = tree[i].size();
            flag++;
        }
    }

    cout << max;
    if (flag > 1) {
        cout << " no" << endl;
    }
    else {
        cout << " yes" << endl;
    }
    qxbl(0);


}