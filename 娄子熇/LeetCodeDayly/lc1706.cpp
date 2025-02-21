#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), -1);
        for(int i = 0; i < grid[0].size(); i ++) {
            int cindex = i; // 当前遍历哪个点就从这个点开始
            for(int rindex = 0; rindex < grid.size(); rindex ++) {
                if (grid[rindex][cindex] == 1 && cindex + 1 < grid[0].size() && grid[rindex][cindex + 1] != -1) {
                    // 往右边转并且右边不是墙并且右边不会把自己卡住
                    cindex ++;
                } else if (grid[rindex][cindex] == -1 && cindex - 1 >= 0 && grid[rindex][cindex - 1] != 1) {
                    // 往左边转并且左边不是墙并且左边不会把自己卡住
                    cindex --;
                } else {
                    cindex = -1;
                    break;
                }
            }
            ans[i] = cindex;
        }
        return ans;
    }
};