#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<stack<int>> sts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            stack<int> st;
            st.push(x);
            sts.push_back(st);
            continue;
        }

        int stssize = sts.size();
        int t = stssize - 1, flag = 0;
        for (int j = 0; j < stssize; j++) {
            if (sts[j].top() > x) {
                if (sts[j].top() < sts[t].top()) {
                    t = j;
                }
                flag = 1;
            }
        }

        if (flag) {
            sts[t].push(x);
        }
        else {
            stack<int> st;
            st.push(x);
            sts.push_back(st);
        }

        // vector<stack<int>> stss=sts;
        // for(auto a:sts){
        //     while(!a.empty()){
        //         cout<<a.top()<<' ';
        //         a.pop();
        //     }
        //     cout<<endl;
        // }

    }
    cout << sts.size();
}