#include<bits/stdc++.h>
using namespace std;

int main() {

    int a, b, n, a_count = 0, b_count = 0;
    cin >> a >> b;
    cin >> n;
    int jl[4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> jl[j];
        }
        if (jl[1] == jl[3]) {
            continue;
        }
        else if (jl[1] == jl[0] + jl[2]) {
            a_count++;
        }
        else if (jl[3] == jl[0] + jl[2]) {
            b_count++;
        }
        if (a_count > a) {
            cout << 'A' << endl << b_count;
            break;
        }
        if (b_count > b) {
            cout << 'B' << endl << a_count;
            break;
        }
    }

}