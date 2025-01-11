#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, m;
int stu[N];
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> stu[i];
    }
    int index = m + 1; // 此时到哪个学生接水了
    while(index <= n + m) {
        ans ++;
        // 模拟水龙头接水， m 个水龙头
        for(int i = 1; i <= m; i ++) {
            stu[i] --;
            if (stu[i] == 0)
                stu[i] = stu[index ++];
        }
    }
    cout << ans;
    return 0;
}