class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> vv;
        vector<int> stk;
        int n = graph.size() - 1;
        stk.push_back(0);

        auto&& dfs = [&vv, &stk, &n, &graph](auto&& dfs, int jd)->void {
            if (jd == n) {
                vv.push_back(stk);
            }
            for (int x : graph[jd]) {
                stk.push_back(x);
                dfs(dfs, x);
                stk.pop_back();
            }
            };

        dfs(dfs, 0);

        return vv;

    }
};