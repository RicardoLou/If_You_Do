#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> missiles;
    int x;
    
    // 读取输入
    while (cin >> x) {
        missiles.push_back(x);
    }

    int n = missiles.size();
    
    // 计算 LNIS (最长不升子序列)
    vector<int> lnis;
    for (int i = 0; i < n; i++) {
        auto pos = upper_bound(lnis.begin(), lnis.end(), missiles[i], greater<int>()); // 找到 <= missiles[i] 的最大值位置
        if (pos == lnis.end()) {
            lnis.push_back(missiles[i]); // 追加
        } else {
            *pos = missiles[i]; // 替换
        }
    }
    
    // 计算 LIS (最长上升子序列)
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis.begin(), lis.end(), missiles[i]); // 找到 > missiles[i] 的最小值位置
        if (pos == lis.end()) {
            lis.push_back(missiles[i]); // 追加
        } else {
            *pos = missiles[i]; // 替换
        }
    }
    
    cout << lnis.size() << endl;
    cout << lis.size() << endl;

    return 0;
}
