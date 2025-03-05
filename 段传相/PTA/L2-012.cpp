#include<bits/stdc++.h>
using namespace std;
//ж╩дцак13╥ж
class HEAP {
public:
    int len = 0;
    int jd[1001] = {};

    HEAP(int n, int data[]) {
        this->len = n;
        for (int i = 1; i <= n; i++) {
            int t = i;
            while (t != 1 && data[(t) / 2] > data[t]) {
                int tmp = data[(t) / 2];
                data[(t) / 2] = data[t];
                data[t] = tmp;
                this->jd[(t) / 2] = data[t];
                this->jd[t] = tmp;
                t = (t) / 2;
            }
        }
    }

};


int main() {

    int n, m;
    cin >> n >> m;
    int data[n];
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    HEAP heap = HEAP(n, data);
    while (m--) {

        int a, b;
        string s;
        cin >> a >> s;
        int f = 0, a_index = 0, b_index = 0;
        if (s == "is") {
            cin >> s;
            if (s == "the") {
                cin >> s;
                if (s == "root") {//root
                    if (a == heap.jd[1]) {
                        f = 1;
                    }
                }
                else {//parent
                    cin >> s >> b;
                    for (int i = 1; i <= n; i++) {
                        if (heap.jd[i] == a) {
                            a_index = i;
                        }
                        if (heap.jd[i] == b) {
                            b_index = i;
                        }
                    }
                    if (b_index / 2 == a_index || (b_index - 1) == a_index) {
                        f = 1;
                    }
                }
            }
            else {//child
                cin >> s >> s >> b;
                for (int i = 1; i <= n; i++) {
                    if (heap.jd[i] == a) {
                        a_index = i;
                    }
                    if (heap.jd[i] == b) {
                        b_index = i;
                    }
                }
                if (a_index > b_index) {
                    f = 1;
                }
            }

        }
        else {//siblings
            cin >> b >> s >> s;
            for (int i = 1; i <= n; i++) {
                if (heap.jd[i] == a) {
                    a_index = i;
                }
                if (heap.jd[i] == b) {
                    b_index = i;
                }
            }
            if (a_index > b_index) {
                swap(a, b);
            }
            if (a_index / 2 == (b_index - 1) / 2) {
                f = 1;
            }
        }

        if (f) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }

    }

}