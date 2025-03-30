#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    getchar();
    //multiset有序可重复
    map<string, multiset<string>> mp;
    for (int i = 0; i < n; i++) {
        string s, s1, s2 = "";
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s1) {
            s2 += s1[0];
        }
        mp[s2].insert(s);
    }

    int m;
    cin >> m;
    getchar();
    for (int i = 0; i < m; i++) {
        string s, s1, s2 = "";
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s1) {
            s2 += s1[0];
        }
        if (mp[s2].empty()) {
            cout << s << endl;
        }
        else {
            int a = 0;
            for (auto it = mp[s2].begin(); it != mp[s2].end(); it++) {
                if (!a) {
                    cout << *it;
                    a++;
                }
                else {
                    cout << '|' << *it;
                }
            }
            cout << endl;
        }
    }

}

//会超时
void test2() {

    int n;
    cin >> n;
    getchar();
    vector<string> sss(n, ""), szm(n, "");
    for (int i = 0; i < n; i++) {
        getline(cin, sss[i]);
        stringstream ss(sss[i]);
        string s;
        while (ss >> s) {
            szm[i] += s[0];
        }
        //cout<<szm[i]<<endl;
    }

    int m;
    cin >> m;
    getchar();
    for (int i = 0; i < m; i++) {
        string s1, s2, s3 = "";
        getline(cin, s1);
        stringstream ss(s1);
        while (ss >> s2) {
            s3 += s2[0];
        }
        set<string> st;
        for (int j = 0; j < n; j++) {
            if (szm[j] == s3) {
                st.insert(sss[j]);
            }
        }
        if (st.empty()) {
            cout << s1 << endl;
        }
        else {
            int a = 0;
            for (auto it = st.begin(); it != st.end(); it++) {
                if (!a) {
                    cout << *it;
                    a++;
                }
                else {
                    cout << '|' << *it;
                }
            }
            cout << endl;
        }
    }

}

//忽略了多个空格
void test1() {

    int n;
    cin >> n;
    vector<vector<string>> sss1;
    vector<string> str;
    for (int i = 0; i < n; i++) {
        vector<string> ss;
        while (1) {
            string s;
            cin >> s;
            ss.push_back(s);
            if (getchar() == '\n') {
                break;
            }
        }
        sss1.push_back(ss);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {

        vector<string> ss;
        while (1) {
            string s;
            cin >> s;
            ss.push_back(s);
            if (getchar() == '\n') {
                break;
            }
        }
        vector<vector<string>> sss2;
        for (auto x : sss1) {
            int flag = 1;
            if (x.size() == ss.size()) {
                for (int j = 0; j < x.size(); j++) {
                    if (x[j][0] != ss[j][0]) {
                        flag = 0;
                        break;
                    }
                }
                sss2.push_back(x);
            }
        }
        if (sss2.size() == 0) {
            cout << ss[0];
            for (int j = 1; j < ss.size(); j++) {
                cout << ' ' << ss[j];
            }
            cout << endl;
        }
        else {
            set<string> se;
            for (auto x : sss2) {
                string z = "";
                for (int j = 0; j < x.size(); j++) {
                    z += x[j];
                    if (j + 1 != x.size()) {
                        z += ' ';
                    }
                }
                se.insert(z);
            }
            for (auto it = se.begin(); it != se.end(); it++) {
                cout << *it;
                if (next(it) != se.end()) {
                    cout << '|';
                }
            }
            cout << endl;
        }
    }

}