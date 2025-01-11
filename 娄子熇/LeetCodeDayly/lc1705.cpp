#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // 可以在n天后继续吃苹果
        for (int i = 0; i < apples.size() || !q.empty(); i++) {
            while (!q.empty() && q.top().first == i) {
                q.pop(); // 腐烂的弹出去
            }
            if (i < apples.size() && apples[i] > 0) {
                q.emplace(i + days[i], apples[i]);
            }
            if (!q.empty()) {
                ans++;
                pair<int, int> temp = q.top(); // 临时存储一下
                q.pop();
                // 还剩有苹果
                if (temp.second > 1) {
                    temp.second -= 1;
                    q.emplace(temp);
                }
            }
        }
        return ans;
    }
};