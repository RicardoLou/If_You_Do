#include <bits/stdc++.h>
using namespace std;

void test();
//���һ�����Ե㳬ʱ
int main() {
    int n;
    cin >> n;

    // ʹ�� unordered_map �����������
    vector<unordered_map<int, int>> szs(n);
    vector<vector<int>> jhs;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> jh;
        while (m--) {
            int x;
            cin >> x;
            szs[i][x]++;
            jh.push_back(x);
        }
        jhs.push_back(jh);
    }

    int k;
    cin >> k;
    while (k--) {
        int a, b, nc = 0;
        cin >> a >> b;
        set<int> s;

        for (auto& kv : szs[a - 1]) {
            if (szs[b - 1].count(kv.first)) {
                nc++;
            }
            s.insert(kv.first);
        }
        for (auto& kv : szs[b - 1]) {
            s.insert(kv.first);
        }

        // ���㲢����ٷֱ�
        double percentage = 1.0 * nc / s.size() * 100;
        printf("%.2f%%\n", percentage);
    }

    return 0;
    //test();
}

//�������
void test() {

    int n;
    cin >> n;
    vector<vector<int>> jhs;
    int szs[n][int(pow(10, 4)) + 1];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> jh;
        while (m--) {
            int x;
            cin >> x;
            szs[i][x]++;
            jh.push_back(x);
        }
        jhs.push_back(jh);
    }
    int k;
    cin >> k;

    while (k--) {
        set<int> s;
        int a, b, nc = 0, nt = 0;
        cin >> a >> b;
        for (int i = 0; i<int(pow(10, 4)) + 1; i++) {
            if (szs[a - 1][i] > 0 && szs[b - 1][i] > 0) {
                nc++;
            }
            if (szs[a - 1][i] > 0 || szs[b - 1][i] > 0) {
                s.insert(i);
            }

        }
        printf("%.2f%%\n", 1.0 * nc / s.size() * 100);
    }

}
