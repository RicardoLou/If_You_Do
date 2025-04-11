#include <bits/stdc++.h>

using namespace std;

int N, K;
string S, E;

map<string, int> Counts;
map<string, vector<pair<string, int>>> Roads;

vector<string> Result;
int minLen = -1;
int maxCount = -1;
int minLenCount = 0;

set<string> visited;

void dfs(string begin, string end, vector<string> &result, int length, int count)
{
    if (begin == end)
    {
        if (minLen == -1 || length < minLen)
        {
            minLen = length;
            Result = result;
            maxCount = count;
            minLenCount = 1;
        }
        else if (length == minLen)
        {
            minLenCount += 1;
            if (result.size() > Result.size())
            {
                Result = result;
                maxCount = count;
            }
            else if (result.size() == Result.size() && count > maxCount)
            {
                Result = result;
                maxCount = count;
            }
        }
        return;
    }
    vector<pair<string, int>> &road = Roads[begin];
    for (auto & r : road)
    {
        string name = r.first;
        int len = r.second;
        if (visited.find(name) != visited.end())
        {
            continue;
        }
        visited.insert(name);
        result.push_back(name);
        dfs(name, end, result, length + len, count + Counts[name]);
        result.pop_back();
        visited.erase(name);
    }
}

int main()
{
    cin >> N >> K >> S >> E;

    for (int i = 0; i < N - 1; i ++)
    {
        string name;
        int count;
        cin >> name >> count;
        Counts[name] = count;
    }

    for (int i = 0; i < K; i ++)
    {
        string A, B;
        int len;
        cin >> A >> B >> len;
        if (Roads.find(A) != Roads.end())
        {
            Roads[A].push_back(pair<string, int>(B, len));
        }
        else {
            Roads[A] = vector<pair<string, int>>(1, pair<string, int>(B, len));
        }
        if (Roads.find(B) != Roads.end())
        {
            Roads[B].push_back(pair<string, int>(A, len));
        }
        else {
            Roads[B] = vector<pair<string, int>>(1, pair<string, int>(A, len));
        }
    }

    vector<string> result;
    visited.insert(S);
    result.push_back(S);
    dfs(S, E, result, 0, 0);

    for (int i = 0; i < Result.size(); i ++)
    {
        cout << Result[i];
        if (i != Result.size() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
    cout << minLenCount << " " << minLen << " " << maxCount << endl;

    return 0;
}