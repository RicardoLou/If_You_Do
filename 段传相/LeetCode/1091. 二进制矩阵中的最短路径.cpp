class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int xlen = grid.size(), ylen = grid[0].size(), count = 0;
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        if (grid[0][0] == 1) {
            return -1;
        }
        // if(xlen==1){
        //     return 1;
        // }
        while (!q.empty()) {
            int qlen = q.size();
            count++;
            for (int i = 0; i < qlen; i++) {
                auto p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                if (x == xlen - 1 && y == ylen - 1/*&&(x!=0||y!=0)*/) {
                    return count;
                }

                for (int j = -1; j <= 1; j++) {
                    for (int k = -1; k <= 1; k++) {
                        if (x + j >= 0 && x + j < xlen && y + k >= 0 && y + k < ylen && grid[x + j][y + k] == 0) {
                            q.push({ x + j,y + k });
                            grid[x + j][y + k] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};