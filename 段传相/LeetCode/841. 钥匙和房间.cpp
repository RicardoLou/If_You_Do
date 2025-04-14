class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), count = 0;
        vector<bool> b(n, 0);
        auto&& dfs = [&b, &count, rooms](auto&& dfs, int jd)->void {
            b[jd] = 1;
            count++;
            for (auto x : rooms[jd]) {
                if (b[x] == 0) {
                    dfs(dfs, x);
                }
            }
            };
        dfs(dfs, 0);
        return count == n;
    }
};