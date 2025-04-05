class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int xlen = maze.size(), ylen = maze[0].size(), count = 0;
        queue<pair<int, int>> q;
        q.push({ entrance[0],entrance[1] });
        while (!q.empty()) {
            int qlen = q.size();
            for (int i = 0; i < qlen; i++) {
                auto p = q.front();
                int x = p.first, y = p.second;
                q.pop();

                if ((x == 0 || y == 0 || x == xlen - 1 || y == ylen - 1) && (x != entrance[0] || y != entrance[1])) {
                    return count;
                }
                maze[x][y] = '+';
                if (x + 1 < xlen && maze[x + 1][y] == '.') {
                    maze[x + 1][y] = '+';
                    q.push({ x + 1,y });
                }
                if (x - 1 >= 0 && maze[x - 1][y] == '.') {
                    maze[x - 1][y] = '+';
                    q.push({ x - 1,y });
                }
                if (y + 1 < ylen && maze[x][y + 1] == '.') {
                    maze[x][y + 1] = '+';
                    q.push({ x,y + 1 });
                }
                if (y - 1 >= 0 && maze[x][y - 1] == '.') {
                    maze[x][y - 1] = '+';
                    q.push({ x,y - 1 });
                }

            }
            count++;
        }
        return -1;
    }
};