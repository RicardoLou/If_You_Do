#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    getchar();
        
    map<string, vector<string>> mp;
    string str;
    stringstream ss;

    for (int i = 0; i < N; i ++)
    {
        getline(cin, str);
        ss.clear();
        ss << str;
        string word, key;
        while(ss >> word)
        {
            key += word[0];
        }
        if (mp.find(key) == mp.end())
        {
            mp[key] = vector<string>(1, str);
        }
        else 
        {
            mp[key].push_back(str);
        }
    }

    cin >> N;
    getchar();
    
    for (int i = 0; i < N; i ++)
    {
        getline(cin, str);
        ss.clear();
        ss << str;
        string word, key;
        while(ss >> word)
        {
            key += word[0];
        }
        if (mp.find(key) == mp.end())
        {
            cout << str << endl;
        }
        else 
        {
            sort(mp[key].begin(), mp[key].end());
            string out = "";
            for (auto str : mp[key])
            {
                out += str + "|";
            }
            out.erase(out.size() - 1, 1);
            cout << out << endl;
        }
    }

    return 0;
}