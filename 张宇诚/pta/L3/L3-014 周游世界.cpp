#include <bits/stdc++.h>

using namespace std;
using Station = pair<string, int>;
using StationList = vector<Station>;

map<string, StationList> Map;

int minStCnt = -1;
int minChCnt = -1;
vector<Station> Result;
set<string> visited;

void dfs(string begin, string end, vector<Station> &result, int stCnt, int chCnt, int curCom)
{
    if (begin == end)
    {
        if (minStCnt == -1 || stCnt < minStCnt)
        {
            minStCnt = stCnt;
            minChCnt = chCnt;
            Result = result;
        }
        else if (stCnt == minStCnt && chCnt < minChCnt)
        {
            minChCnt = chCnt;
            Result = result;
        }
        return;
    }
    if (minStCnt != -1 && stCnt >= minStCnt)
    {
        return;
    }
    auto iter = Map.find(begin);
    if (iter == Map.end())
    {
        return;
    }
    StationList &nextStations = iter->second;
    for (Station station : nextStations)
    {
        string id = station.first;
        int com = station.second;
        if (visited.find(id) != visited.end())
        {
            continue;
        }
        visited.insert(id);
        result.push_back(Station(id, com));
        int newChCnt = chCnt;
        if (visited.size() != 2 && curCom != com) 
        {
            newChCnt ++;
        }
        dfs(id, end, result, stCnt + 1, newChCnt, com);
        result.pop_back();
        visited.erase(id);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        int M;
        cin >> M;
        string front = "";
        for (int j = 0; j < M; j ++)
        {
            string id;
            cin >> id;
            if (front != "")
            {
                auto iter = Map.find(front);
                if (iter != Map.end())
                {
                    Map[front].push_back(Station(id, i + 1));
                }
                else {
                    Map[front] = StationList(1, Station(id, i + 1));
                }
                iter = Map.find(id);
                if (iter != Map.end())
                {
                    Map[id].push_back(Station(front, i + 1));
                }
                else {
                    Map[id] = StationList(1, Station(front, i + 1));
                }
            }
            front = id;
        }
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i ++)
    {
        string begin, end;
        vector<Station> result;
        cin >> begin >> end;
        minStCnt = -1;
        minChCnt = -1;
        Result.clear();
        visited.clear();
        visited.insert(begin);
        dfs(begin, end, result, 0, 0, 0);
        string s = begin;
        if (minStCnt == -1)
        {
            cout << "Sorry, no line is available." << endl;
            continue;
        }
        cout << minStCnt << endl;
        for (int i = 0; i < Result.size() - 1; i ++)
        {
            Station &station = Result[i];
            string id = station.first;
            int com = station.second;
            if (com != Result[i + 1].second)
            {
                cout << "Go by the line of company #" << com << " from " << s << " to " << id << "." << endl;
                s = id;
            }
        }
        cout << "Go by the line of company #" << Result[Result.size() - 1].second << " from " << s << " to " << end << "." << endl;
    }


    return 0;
}