/*
  @pintia psid=994805046380707840 pid=1781658570803388424 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 鱼与熊掌
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388424
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, q;
unordered_map<int, unordered_set<int>> foodMap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            foodMap[i].insert(x);
        }
    }

    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (foodMap[i].count(a) && foodMap[i].count(b)) {
                res++;
            }
        }
        cout << res << '\n';
    }

    return 0;
}


// @pintia code=end