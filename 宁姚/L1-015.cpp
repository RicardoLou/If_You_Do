#include <bits/stdc++.h>
using namespace std;

int main() {
    int col, row, temp;
    char c;
    cin >> col >> c;
    for(int i = 0; i < ceil(col/2); i++) {
        for(int j = 0; j < col; j++) {
            cout << c;
        }
        cout << endl;
    }
}