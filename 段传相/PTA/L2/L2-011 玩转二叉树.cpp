#include<bits/stdc++.h>
using namespace std;

struct Tree {
    int l = 0;
    int r = 0;
}node[31];

int main() {

    int n;
    cin >> n;
    vector<int> mid(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> mid[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }

    auto&& pp = [&](auto&& pp, int l1, int r1, int l2, int r2)->int {
        if (l1 > r1) {
            return 0;
        }
        int root = pre[l2];
        int p = l1;
        while (mid[p] != root) {
            p++;
        }
        int cnt = p - l1;
        node[root].l = pp(pp, l1, l1 + cnt - 1, l2 + 1, l2 + cnt);
        node[root].r = pp(pp, p + 1, r1, l2 + cnt + 1, r2);
        return root;
        };

    pp(pp, 1, n, 1, n);

    queue<int> q;
    q.push(pre[1]);
    vector<int> ans, f(1e6, 0);//节点的值并不是1~n
    ans.push_back(pre[1]);
    f[pre[1]] = 1;
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        if (node[d].r != 0) {
            q.push(node[d].r);
            ans.push_back(node[d].r);
            f[node[d].r] = 1;
        }
        if (node[d].l != 0) {
            q.push(node[d].l);
            ans.push_back(node[d].l);
            f[node[d].l] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << ans[i];
        }
        else {
            cout << ' ' << ans[i];
        }
    }
}