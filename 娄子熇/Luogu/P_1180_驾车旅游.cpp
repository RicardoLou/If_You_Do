#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second

const int N = 110;

// 全局变量
double volumn, originFee, per, ans = 1e9;
int dis, n;
vector<pair<double, double>> gas(N);

// 递归函数
void dfs(double vol, int loc, double sum) {
    if (loc == n + 1) { // 到达终点
        ans = min(ans, sum);
        return;
    }

    double dist = gas[loc + 1].x - gas[loc].x;

    // 如果油量不足以到达下一站，必须加油
    if (vol < dist / per) {
        sum += 20; // 搞吃搞喝
        sum += (volumn - vol) * gas[loc].y; // 加满油
        vol = volumn - dist / per; // 更新油量
        dfs(vol, loc + 1, sum);
    } else {
        // 当前油量足够的情况下，有两种选择：
        // 1. 不加油，直接前往下一站
        dfs(vol - dist / per, loc + 1, sum);

        // 2. 油量少于半箱，考虑加油
        if (vol < volumn / 2) {
            sum += 20; // 搞吃搞喝
            sum += (volumn - vol) * gas[loc].y; // 加满油
            vol = volumn - dist / per; // 更新油量
            dfs(vol, loc + 1, sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 输入
    cin >> dis >> volumn >> per >> originFee >> n;
    for (int i = 1; i <= n; i++) {
        cin >> gas[i].x >> gas[i].y;
    }
    gas[0] = {0, 0}; // 起点
    gas[n + 1] = {double(dis), 0}; // 终点

    dfs(volumn, 0, 0);

    // 输出结果
    printf("%.1f\n", ans + originFee);
    return 0;
}