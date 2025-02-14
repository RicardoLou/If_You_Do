#include <bits/stdc++.h>
using namespace std;

vector<int> dice[7];

int main() {
    for (int i = 1; i <= 6; i++) {
        dice[i].resize(7, 0);
        int x;
        cin >> x;
        dice[i][x] = 1; // 标记使用过
    }

    int n;
    cin >> n;
    vector<int> ans;

    for (int i = 1; i <= 6; i++) {
        int cnt = 0;
        for (int j = 6; j >= 1; j--) {
            if (dice[i][j] != 1) {
                cnt++;
                dice[i][j] = 1;
            }
            // 骰n轮
            if (cnt == n) {
                ans.push_back(j);
                break;
            }
        }
    }

    for (int i = 0; i < 6; i ++) {
        if (i != 5) {
            cout << ans[i] << " ";
        } else cout << ans[i];
    }
    return 0;
}
