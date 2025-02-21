#include<bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    // int q[11] = {0};
    vector<int> q(11, 0);
    string op;
    while(cin >> op) {
        if(op == "add") {
            int x;
            cin >> x;
            q[0] ++;
        } else if (op == "sync") {
            int x;
            cin >> x;
            // 如果主队列已经没有数可以加过来了
            if (q[x] == q[0]) continue;
            q[x] ++;
        } else {
            int res = q[0];
            for(int i = 1; i < n; i ++) {
                res = min(res, q[i]);
            }
            cout << res << endl;
        }
    }
    
    
    return 0;
}