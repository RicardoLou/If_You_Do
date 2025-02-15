#include<bits/stdc++.h>
using namespace std;

int main() {
    int jia, yi;
    cin >> jia >> yi;
    int n;
    cin >> n;
    int cntA = 0;
    int cntB = 0;
    while(n --) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = a + c;
        if (b == d) continue; // 这种情况一定是同赢或同输
        if (b == s) cntA ++;
        if (d == s) cntB ++;
        if (cntA > jia) {
            cout << "A" << endl << cntB;
            return 0;
        } 
        if (cntB > yi) {
            cout << "B" << endl << cntA;
            return 0;
        }
    }
    return 0;
}