#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m, s;
    cin >> n >> m >> s;
    getchar();//cin不会读回车
    vector<queue<char>> qs;
    stack<char> stk;

    for (int i = 0; i < n; i++) {
        queue<char> q;
        for (int j = 0; j < m; j++) {
            q.push(getchar());
        }
        getchar();
        qs.push_back(q);
    }

    int a;
    while (cin >> a) {
        if (a == -1) {
            break;
        }
        else if (!stk.empty() && a == 0) {
            cout << stk.top();
            stk.pop();
        }
        else {
            if (!qs[a - 1].empty()) {
                if (stk.size() < s) {
                    stk.push(qs[a - 1].front());
                    qs[a - 1].pop();
                }
                else {
                    cout << stk.top();
                    stk.pop();
                    stk.push(qs[a - 1].front());
                    qs[a - 1].pop();
                }
            }
        }
    }

}