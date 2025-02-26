#include<bits/stdc++.h>
using namespace std;

class JD {
public:
    int dz = 0;
    int zhi = 0;
    int next = 0;
    JD(int dz, int zhi, int next) {
        this->dz = dz;
        this->zhi = zhi;
        this->next = next;
    }
    JD() {}
};

int main() {
    int h, n, idx1 = 0, idx2 = 0;
    cin >> h >> n;
    int dz, zhi, next;
    unique_ptr<JD[]> lb(new JD[100000]);
    unique_ptr<JD[]> lb1(new JD[100000]);
    unique_ptr<JD[]> lb2(new JD[100000]);

    while (cin >> dz >> zhi >> next) {
        lb[dz] = JD(dz, zhi, next);
    }

    set<int> s;
    while (h != -1) {
        if (!s.count(abs(lb[h].zhi))) {
            s.insert(abs(lb[h].zhi));
            lb1[idx1++] = lb[h];
        }
        else {
            lb2[idx2++] = lb[h];
        }
        h = lb[h].next;
    }

    for (int i = 0; i < idx1 - 1; i++) {
        printf("%05d %d %05d\n", lb1[i].dz, lb1[i].zhi, lb1[i + 1].dz);
    }
    printf("%05d %d -1\n", lb1[idx1 - 1].dz, lb1[idx1 - 1].zhi);

    if (idx2) {
        for (int i = 0; i < idx2 - 1; i++) {
            printf("%05d %d %05d\n", lb2[i].dz, lb2[i].zhi, lb2[i + 1].dz);
        }
        printf("%05d %d -1\n", lb2[idx2 - 1].dz, lb2[idx2 - 1].zhi);
    }

}

void test() {
    int h, n, h2 = -1;
    cin >> h >> n;
    int zhi[100000] = {}, prior[100000] = {}, next[100000] = {}, flag[10000] = {};
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        zhi[a] = b;
        prior[c] = a;
        next[a] = c;
    }

    a = h;
    b = zhi[a];
    c = next[a];
    for (int i = 0; i < 2 * n; i++) {

        if (++flag[abs(b)] > 1) {
            cout << b << " ";
            if (h2 == -1) {
                h2 = a;
                //prior[a]=h2;
            }
            next[prior[a]] = next[a];
            prior[next[a]] = prior[a];
            a = next[a];
            b = zhi[a];
            c = next[a];
            if (c == -1) {
                break;
            }
        }
        else {
            a = c;
            b = zhi[a];
            c = next[a];
        }
    }
    a = h;
    b = zhi[a];
    c = next[a];
    for (int i = 0; i < n; i++) {
        cout << b << endl;
        a = c;
        b = zhi[a];
        c = next[a];
        if (c == -1) {
            break;
        }
    }
    cout << "------" << endl;
    a = h2;
    b = zhi[a];
    c = next[a];
    for (int i = 0; i < n; i++) {
        cout << b << endl;
        a = c;
        b = zhi[a];
        c = next[a];
        if (c == -1) {
            break;
        }
    }
}