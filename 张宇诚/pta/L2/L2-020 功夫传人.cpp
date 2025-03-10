#include <bits/stdc++.h>

using namespace std;

int N;
float Z, r;
vector<vector<int>> pupils;
double S = 0.0;

void dfs(int master, double kongfu)
{
    vector<int> &vec = pupils[master];
    if(vec[0] == 0)
    {
        S += kongfu * vec[1];
        return;
    }
    for(int i = 1; i < (int)vec.size(); i ++)
    {
        dfs(vec[i], kongfu * (1.0 - r / 100.0));
    }
}

int main()
{
    cin >> N >> Z >> r;
    for(int i = 0; i < N ; i ++)
    {
        int K;
        cin >> K;
        vector<int> vec;
        vec.push_back(K);
        if(K == 0)
        {
            K = 1;
        }
        for(int j = 0; j < K; j ++)
        {
            int id;
            cin >> id;
            vec.push_back(id);
        }
        pupils.push_back(vec);
    }

    dfs(0, Z);
    cout << (int)S << std::endl;

    return 0;
}