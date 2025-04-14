#include <bits/stdc++.h>

using namespace std;

struct Hash
{
    size_t operator() (const vector<int> &v) const
    {
        size_t hash_value = hash<int>()(v[0]);
        int s = 1;
        for (int i = 1; i < v.size(); i ++)
        {
            hash_value ^= hash<int>()(v[i]) << s ++;
        }
        return hash_value;
    }
};

unordered_map<vector<int>, int, Hash> papers;
vector<int> points;
int N, M;
vector<int> result;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        int h;
        cin >> h;
        points.push_back(h);
    }
    cin >> M;
    for (int i = 0; i < M; i ++)
    {
        int c;
        cin >> c;
        vector<int> paper;
        for (int j = 0; j < c; j ++)
        {
            int h;
            cin >> h;
            paper.push_back(h);
        }
        papers[paper] = i + 1;
    }

    int begin = 0, end = 1;
    while (end < points.size())
    {
        vector<int> P(points.begin() + begin, points.begin() + end + 1);
        auto iter = papers.find(P);
        if (iter != papers.end())
        {
            result.push_back(iter->second);
            begin = end;
            papers.erase(iter);
        }
        end += 1;
    }

    for(int i = 0; i < result.size(); i ++)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    
    return 0;
}