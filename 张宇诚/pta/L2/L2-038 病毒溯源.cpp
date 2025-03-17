#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> childs;
vector<int> result;

bool func(const vector<int> &A, const vector<int> &B)
{
    if(A.size() > B.size()) return true;
    if(A.size() == B.size())
    {
        for(int i = 0; i < (int)A.size(); i ++)
        {
            if(A[i] < B[i]) return true;
            else if(B[i] < A[i]) return false;
        }
    }
    return false;
}

void dfs(int index, vector<int> &lst)
{
    lst.push_back(index);
    if((int)childs[index].size() == 0 && func(lst, result))
    {
        result = lst;
    }
    for(int child : childs[index])
    {
        dfs(child, lst);
    }
    lst.pop_back();
}

int main()
{
    int s = 0, N;
    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        int k;
        cin >> k;
        vector<int> vec;
        for(int j = 0; j < k; j ++)
        {
            int child;
            cin >> child;
            vec.push_back(child);
            s += child;
        }
        childs.push_back(vec);
    }

    int first = (N - 1) * N / 2 - s;
    vector<int> lst;
    dfs(first, lst);

    cout << result.size() << endl;
    for(int i = 0; i < (int)result.size(); i ++)
    {
        cout << result[i];
        if(i != (int)result.size() - 1)
        {
            cout << " ";
        }
    }
    
    return 0;
}


