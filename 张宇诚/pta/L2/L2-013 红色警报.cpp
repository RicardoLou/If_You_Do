#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<vector<int>> roads; 
vector<set<int>> areas;
set<int> lostCities;

void dfs(int node, set<int> &visited)
{
    if (visited.find(node) != visited.end() || lostCities.find(node) != lostCities.end())
    {
        return;
    }
    visited.insert(node);
    vector<int> &road = roads[node];
    for (int next : road)
    {
        dfs(next, visited);
    }
}

//将连接的城市划分成同一个区域
void zoning(const set<int> &cities)
{
    for (int i : cities)
    {
        bool sign = true;
        for (const set<int> &it : areas)
        {
            if (it.find(i) != it.end())
            {
                sign = false;
                break;
            }
        }
        if (sign)
        {
            set<int> visited;
            dfs(i, visited);
            areas.push_back(visited);
        }
    }
}

int main()
{
    cin >> N >> M;
    roads.resize(N);

    for(int i = 0; i < M; i ++)
    {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    set<int> cities;
    for (int i = 0; i < N; i ++)
    {
        cities.insert(i);
    }
    zoning(cities);

    
    cin >> K;
    int s = 0;
    
    for (int i = 0; i < K; i ++)
    {
        int k;
        cin >> k;
        s += k;
        for (auto iter = areas.begin(); iter != areas.end(); iter ++)
        {
            if (iter->find(k) == iter->end())
            {
                continue;
            }
            int begin = -1;
            bool alert = false;
            for (int node : *iter)
            {
                if (node != k)
                {
                    begin = node;
                    break;
                }
            }
            if (begin != -1)
            {
                set<int> visited;
                visited.insert(k);
                dfs(begin, visited);
                if (visited.size() != iter->size())
                {
                    alert = true;
                }
            }
            if (alert)
            {
                cout << "Red Alert: City " << k << " is lost!" << endl;
            }
            else{
                cout << "City " << k << " is lost." << endl;
            }
            set<int> newCities = *iter;
            areas.erase(iter);
            newCities.erase(k);
            lostCities.insert(k);
            zoning(newCities);
            break;
        }
    }

    if (s == (N - 1) * N / 2)
    {
        cout << "Game Over." << endl;
    }
    
    return 0;
}