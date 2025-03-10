#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    set<string> att;
    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        string name;
        cin >> name;
        att.insert(name);
    }
    cin >> N;
    map<string, int> mp;
    float avg = 0.0f;
    for(int i = 0; i < N; i ++)
    {
        string name;
        int count;
        cin >> name;
        cin >> count;
        avg += count;
        if (att.find(name) == att.end())
        {
            mp.insert(pair<string, int>(name, count));
        }
    }
    avg /= N;
    bool isNull = true;
    for(auto iter : mp)
    {
        if(iter.second > avg)
        {
            cout << iter.first << endl;
            isNull = false;
        }
    }
    if(isNull)
    {
        cout << "Bing Mei You" << endl;
    }

    return 0;
}