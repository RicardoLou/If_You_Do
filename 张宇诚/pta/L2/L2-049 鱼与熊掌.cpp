#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    vector<int> arr[100000];
    cin >> n >> m;
    for(int i = 0;i < n;i ++)
    {
        int c;
        cin >> c;
        for(int j = 0;j < c;j ++)
        {
            int id;
            cin >> id;
            arr[i].push_back(id);
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0; i <Q; i ++)
    {
        int a, b;
        cin >> a >> b;
        int num = 0;
        for(int j = 0; j < n; j ++)
        {
            bool containA = false, containB = false;
            for(auto it : arr[j])
            {
                if(it == a) containA = true;
                else if(it == b) containB = true;
            }
            if(containA && containB) num ++;
        }
        cout << num << endl;
    }
    return 0;
}