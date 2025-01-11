#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, vis[N], l[N];
string s[N];
char ch;
int ans = 0;

// 检查是否可以合并
int find(int x, int y) {
    int lx = l[x], ly = l[y];
    for (int i = lx - 1; i >= 1; i--) {
        if (s[x][i] == s[y][0]) {
            int k = 0;
            for (int j = i + 1; j <= lx - 1; j++) {
                k++;
                if (s[x][j] != s[y][k]) return 0; // 不匹配
            }
            return ly - (k + 1); // 返回新增长度
        }
    }
    return 0;
}

void dfs(int x, int p) {
    for (int i = 1; i <= n; i++) {
        int overlap = find(x, i);
        if (vis[i] < 2 && overlap) {
            vis[i]++;
            dfs(i, p + overlap);
            vis[i]--;
        }
    }
    ans = max(ans, p); // 更新最大长度
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        l[i] = s[i].length();
    }
    cin >> ch;

    for (int i = 1; i <= n; i++) {
        if (s[i][0] == ch) {
            vis[i]++;
            dfs(i, l[i]);
            vis[i]--;
        }
    }
    printf("%d", ans);
    return 0;
}