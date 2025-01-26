#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, k, id[100000], m, count[100000], flag = 0, ks[100000];
    fill(begin(count), end(count), -1);
    fill(begin(id), end(id), 1);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            id[x]++;
            ks[x] = k;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> count[i];
    }

    vector<int> s;
    for (int i = 0; i < 100000; i++) {
        if (((ks[count[i]] == 1) && (id[count[i]] == 2)) || (id[count[i]] < 2)) {
            if (count[i] >= 0) {
                flag++;
                if (find(s.begin(), s.end(), count[i]) == s.end()) {
                    s.push_back(count[i]);
                }
            }

        }
    }

    if (s.size() == 0) {
        cout << "No one is handsome";
    }
    else {
        for (int i = 0; i < s.size() - 1; i++) {
            printf("%05d ", s[i]);
        }
        printf("%05d", s[s.size() - 1]);
    }

}



int test() {
    int n, index = -1;
    cin >> n;
    vector<vector<int>> jls;
    for (int i = 0; i < n; i++) {
        vector<int> jl;
        int x;
        cin >> x;
        jl.push_back(x);
        for (int j = 0; j < jl[0]; j++) {
            int y;
            cin >> y;
            jl.push_back(y);
        }
        jl.push_back(index--);
        jls.push_back(jl);
    }

    int m;
    cin >> m;
    vector<int> jg;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (auto jl : jls) {
            auto it = find(jl.begin(), jl.end(), x);
            cout << distance(jl.begin(), it) << endl;
            if (it != jl.end()) {
                if (jl.size() == 2) {
                    jg.push_back(x);
                }
                break;
            }
            if (find(jg.begin(), jg.end(), x) == jg.end() && jl[jl.size() - 1] == jls[jls.size() - 1][jls[jls.size() - 1].size() - 1]) {
                jg.push_back(x);
            }
        }
    }

    // auto end_unique = unique(jg.begin(), jg.end());
    // jg.erase(end_unique, jg.end());
    if (jg.size() == 0) {
        cout << "No one is handsome";
    }
    else {
        for (int i = 0; i < jg.size() - 1; i++) {
            printf("%05d ", jg[i]);
        }
        printf("%05d", jg[jg.size() - 1]);
    }

    return 0;
}