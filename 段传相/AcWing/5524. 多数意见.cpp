#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> st;
        for (int& x : v) {
            cin >> x;
        }
        if (n == 2) {
            if (v[0] != v[1]) {
                cout << -1 << endl;
                continue;
            }
            else {
                st.insert(v[0]);
            }
        }

        for (int i = 0; i < n - 2; i++) {
            if (i + 2 < n) {
                //只要存在xxy或者xyx或者xyy排列
                if (v[i] == v[i + 1] || v[i] == v[i + 2]) {
                    st.insert(v[i]);
                }
                else if (v[i + 1] == v[i + 2]) {
                    st.insert(v[i + 1]);
                }
            }
        }

        if (st.size() == 0) {
            cout << -1 << endl;
        }
        else {
            for (auto it = st.begin(); it != st.end(); it++) {
                if (it == st.begin()) {
                    cout << *it;
                }
                else {
                    cout << ' ' << *it;
                }
            }
            cout << endl;
        }
        v.clear();
        st.clear();

    }

}