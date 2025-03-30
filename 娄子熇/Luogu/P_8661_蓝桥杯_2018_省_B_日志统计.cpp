#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
priority_queue<int, vector<int>, greater<int>> inf[N];
set<int> ids;
int main() {
    int n, d, k;
    cin >> n >> d >> k;
    for(int i = 0; i < n; i ++) {
        int ts, id;
        cin >> ts >> id;
        inf[id].push(ts); // 默认从小到大排序
        ids.insert(id);
    }
    set<int> ans; // 避免重复
    for(auto id : ids) {
        vector<int> timestamps; // 取出 堆 内所有时间戳
        while (!inf[id].empty()) {
            timestamps.push_back(inf[id].top());
            inf[id].pop();
        }
        int len = timestamps.size();
        for(int i = 0; i < len; i ++) {
            int t = timestamps[i];
            int cnt = 0;
            for(int j = i; j < len; j ++) {
                if (timestamps[j] < t + d) {
                    // 在当前这个区间中
                    cnt ++;
                } else {
                    // 因为已经排好序了，所以直接break掉
                    break;
                }
                if (cnt >= k) {
                    ans.insert(id);
                    break;
                }
            }
        }
    }
    for(int id : ans) {
        cout << id << endl;
    }
    return 0;
}