#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上
        int x = 0, y = 0, dir = 0;
        for(int i = 1; i <= n * n; i ++) {
            ans[x][y] = i;
            int dx = x + d[dir][0];
            int dy = y + d[dir][1];
            if (dx < 0 || dx > n || dy < 0 || dy > n || ans[dx][dy]) {
                dir = (dir + 1) % 4; // 更改方向
            }
            // 按新的方向走一步
            x += d[dir][0];
            y += d[dir][1];
        }
        return ans;
    }
};