#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> vv(n);
    for (auto& x : vv)
    {
        int a;
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            int b;
            cin >> b;
            x.push_back(b);
        }
    }

    map<int, set<vector<int>>> mp;
    auto&& dfs = [&](auto&& dfs, int id, int cnt, vector<int> v) -> void
        {
            v.push_back(id);
            if (vv[id].size() == 0)
            {
                mp[cnt].insert(v);
                mp[cnt - 1].clear();
                v.clear();
                return;
            }

            for (auto x : vv[id])
            {
                dfs(dfs, x, cnt + 1, v);
            }
            return;
        };

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (vv[i].size() != 0)
        {
            dfs(dfs, i, 1, vector<int>());
            flag = 1;
        }
    }

    if (flag)
    {
        cout << mp.rbegin()->first << endl;

        // cout<<"-----"<<endl;
        // for(auto x:mp.rbegin()->second){
        //     cout<<x<<endl;
        // }
        // cout<<"----"<<endl;

        for (int i = 0; i < (*mp.rbegin()->second.begin()).size(); i++)
        {
            if (i == 0)
            {
                cout << (*mp.rbegin()->second.begin())[i];
            }
            else
            {
                cout << ' ' << (*mp.rbegin()->second.begin())[i];
            }
        }
    }
    else
    {
        cout << 1 << endl
            << 0;
    }
}