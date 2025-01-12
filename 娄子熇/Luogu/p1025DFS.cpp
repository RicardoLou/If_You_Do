#include<bits/stdc++.h>
using namespace std;

int n, k;
int cnt;
// 必须大于 last 这是为了维护升序，这样不会出现重复， cur表示当前分了多少份了 
void dfs(int last, int sum, int cur) {
    if (cur == k) {
        if (sum == n) cnt ++;
        return;
    }
    // 剪枝 当前总和加上 当前可分配份数 * 当前最小可分配值
    for(int i = last; sum + i * (k - cur) <= n; i ++) {
        dfs(i, sum + i, cur + 1);
    }
}
int main() {
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << cnt;
    return 0;
}