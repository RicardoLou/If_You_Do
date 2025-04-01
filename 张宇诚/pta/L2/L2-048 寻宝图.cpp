
#include <bits/stdc++.h>
using namespace std;

struct Point{
public:
    Point(int y, int x) : x(x), y(y) {}
    bool operator== (const Point & p) {
        return p.y == y && p.x == x;
    }
    bool operator < (const Point & p) const
    {
        if(x < p.x) return true;
        else if (x == p.x)
        {
            if(y < p.y) return true;
            else 
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    int x, y;
};

int N, M;
vector<string> Map;
int island_count = 0;
int treaisland_count = 0;
set<Point> global_hidden;

void dfs(int y, int x, int &treasure) 
{
    int num = Map[y][x] - '0';
    if(num > 1) treasure = 1;
    global_hidden.insert(Point(y, x));
    if(x - 1 >= 0 && global_hidden.find(Point(y, x - 1)) == global_hidden.end() && Map[y][x - 1] - '0' >= 1)
        dfs(y, x - 1, treasure);
    if(x + 1 < M && global_hidden.find(Point(y, x + 1)) == global_hidden.end() && Map[y][x + 1] - '0' >= 1)
        dfs(y, x + 1, treasure);
    if(y - 1 >= 0 && global_hidden.find(Point(y - 1, x)) == global_hidden.end() && Map[y - 1][x] - '0' >= 1)
        dfs(y - 1, x, treasure);
    if(y + 1 < N && global_hidden.find(Point(y + 1, x)) == global_hidden.end() && Map[y + 1][x] - '0' >= 1)
        dfs(y + 1, x, treasure);
}

void func() 
{
    for(int y = 0; y < N; y ++)
    {
        for(int x = 0; x < M; x ++)
        {
            int num = Map[y][x] - '0';
            if(num == 0 || global_hidden.find(Point(y, x)) != global_hidden.end())
            {
                continue;
            }
            else {
                int treasure = 0;
                dfs(y, x, treasure);
                island_count += 1;
                treaisland_count += treasure;
            }
        }
    }
}

int main()
{
    cin >> N;
    cin >> M;
        
    for(int i = 0; i < N; i ++)
    {
        string s;
        cin >> s;
        Map.push_back(s);
    }

    func();
    cout << island_count << " " << treaisland_count << endl;
    
    return 0;
}
