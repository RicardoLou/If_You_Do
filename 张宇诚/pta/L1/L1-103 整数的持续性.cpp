#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

vector<int> a;

int func(int num)
{
    if (num / 10 == 0)  return 0;

    int n=1;
    while (num)
    {
        n *= num % 10;
        num /= 10;
    }
    return func(n) +  1;
}

int main()
{
    int n, m, cnt = 0, vmax = 0;

    cin >> n >> m;

    for(int i = n; i <= m; i ++)
        {
            cnt = 0;
            cnt = max(func(i), cnt);
            if(cnt > vmax)
            {
                vmax = cnt;
                a.clear();
                a.push_back(i);
            }
            else if(cnt == vmax)
                a.push_back(i);
        }

    cout << vmax << endl;
     for(int i = 0;i < a.size();i ++)
        {
            cout << a[i];
            if(i != a.size() - 1) cout << " ";
        }
    return 0;
}