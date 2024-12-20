#include <bits/stdc++.h>
using namespace std;

int n;
int root;
int maxDigree = 0;
bool isFullTree = true;
vector<int> arr;
map<int, vector<int>> Map;

void treeDigree(int root)
{
    arr.push_back(root);
    int digree = 0;
    auto iter = Map.find(root);
    if(iter != Map.end())
    {
        for(auto i : iter->second)
        {
            digree ++;
            treeDigree(i);
        }
    }
    if(digree > maxDigree)
    {
        if(maxDigree != 0) isFullTree = false;
        maxDigree = digree;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int t;
        cin >> t;
        if(t == 0) root = i;
        else 
        {
            auto iter = Map.find(t);
            if(iter == Map.end())
            {
                vector<int> vec;
                vec.push_back(i);
                Map.insert(pair<int, vector<int>>(t, vec));
            }
            else{
                iter->second.push_back(i);
            }
        }
    }
    treeDigree(root);
    cout << maxDigree << " " << (isFullTree ? "yes" : "no") << endl;
    for(int i = 0; i < arr.size(); i ++)
    {
        cout << arr[i];
        if(i != arr.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}