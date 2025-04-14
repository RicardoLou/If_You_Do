#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> vec;

set<int> visited;
vector<array<int, 2>> Queue;

int bfs(int d)
{
    int maxDistance = 0;
    int result = 0;
    visited.clear();
    Queue.push_back(array<int, 2>({d, 0}));
    visited.insert(d);
    while(!Queue.empty())
    {
        int curMountain = Queue[0][0];
        int curDistance = Queue[0][1];
        vector<int> & mountains = vec[curMountain];
        if (curDistance > maxDistance || curDistance == maxDistance && curMountain < result)
        {
            maxDistance = curDistance;
            result = curMountain;
        }
        for (int mountain : mountains)
        {
            if (visited.find(mountain) != visited.end())
            {
                continue;
            }
            visited.insert(mountain);
            Queue.push_back(array<int, 2>({mountain, curDistance + 1}));
        }
        Queue.erase(Queue.begin());
    }
    return result;
}

int main()
{
    cin >> N >> M >> K;
    vec.resize(N + 1, vector<int>());
    for (int i = 0; i < M; i ++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 0; i < K; i ++)
    {
        int d;
        cin >> d;
        cout << bfs(d) << endl;
    }

    return 0;
}