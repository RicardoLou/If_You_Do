#include<bits/stdc++.h>
using namespace std;
//���������֣����Ե�1û��
int main() {

    int n, m, k;
    cin >> n >> m >> k;
    int gx[n + 1][n + 1] = {};
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        gx[a][b] = c;
        gx[b][a] = c;
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (gx[a][b] == 1) {
            cout << "No problem" << endl;
        }
        else if (gx[a][b] == -1) {
            for (int i = 1; i <= m; i++) {
                if (gx[a][i] == 1 && gx[b][i] == 1) {
                    cout << "OK but..." << endl;
                    break;
                }
                else {
                    cout << "No way" << endl;
                    break;
                }
            }
        }
        else {
            for (int i = 1; i <= m; i++) {
                if (gx[a][i] == 1 && gx[b][i] == 1) {
                    cout << "No problem" << endl;
                    break;
                }
                else {
                    cout << "OK" << endl;
                    break;
                }
            }
        }
    }
}