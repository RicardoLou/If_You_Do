#include <bits/stdc++.h>

using namespace std;
using LST = vector<int>;

int N;
int maxDeep = 0;
int deepest_door = 0;
vector<LST> mp;

void dfs(int curDoor, int deep)
{
    LST doors = mp[curDoor - 1];
    if(doors.size() == 0 && deep > maxDeep)
    {
        maxDeep = deep;
        deepest_door = curDoor;
        return;
    }
    for(int door : doors)
    {
        dfs(door, deep + 1);
    }
}

int main()
{
    cin >> N;
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        LST lst;
        for(int j = 0; j < K; j ++)
        {
            int D;
            cin >> D;
            s += D;
            lst.push_back(D);
        }
        mp.push_back(lst);
    }

    int first_door = (1 + N) * N / 2 - s;
    dfs(first_door, 1);
    cout << deepest_door << endl;
    
    return 0;
}