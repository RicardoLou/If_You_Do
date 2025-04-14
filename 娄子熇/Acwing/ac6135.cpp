#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    
    int cnt = 0; // 记录多少个点相同
    vector<int> count(N + 1, 0);
    for(int i = 1; i <= N; i ++) {
        if (a[i] == b[i]) {
            cnt ++;
        }
    }
    // 枚举所有可能的 (l, r)
    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j < 2; j ++) {
            int s = cnt;
            for(int l = i, r = i + j; l >= 1 && r <= N; l --, r ++) {
                if (a[l] == b[l]) s --; // 反转后不存在这个相同了，所以减去
                if (a[r] == b[r]) s --;
                if (a[l] == b[r]) s ++; // 反转后新增这个相同
                if (a[r] == b[l]) s ++;
                count[s] ++;
            }
        }
    }
    
    for (int i = 0; i <= N; i++) {
        cout << count[i] << "\n";
    }
    
    return 0;
}