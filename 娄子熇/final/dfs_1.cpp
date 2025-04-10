#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 15;
int n;
long long perket[N][2];
long long ans = 1e9;

void dfs(int idx, long long acid, long long bitter, bool selected) {
    // 当所有食材都考虑完后，只有选取至少一个时才更新答案
    if (idx == n) {
        if (selected) {
            ans = min(ans, llabs(acid - bitter));
        }
        return;
    }
    // 不选择当前食材
    dfs(idx + 1, acid, bitter, selected);
    // 选择当前食材：酸度相乘，苦度相加，标记为已选择
    dfs(idx + 1, acid * perket[idx][0], bitter + perket[idx][1], true);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> perket[i][0] >> perket[i][1];
    }
    // 初始酸度设为1（乘法单位），苦度设为0，且还未选中任何食材
    dfs(0, 1, 0, false);
    cout << ans << "\n";
    return 0;
}
