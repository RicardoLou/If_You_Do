#include<bits/stdc++.h>
using namespace std;

int main() {

    int szs[6][6] = { {1,2,3,4,5,6},{1,2,3,4,5,6},
                   {1,2,3,4,5,6},{1,2,3,4,5,6},
                   {1,2,3,4,5,6},{1,2,3,4,5,6} };
    int a = 6, b = 0, t;
    while (a--) {
        cin >> t;
        szs[b++][t - 1] = 0;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 6; j++) {
            *max_element(&szs[j][0], &szs[j][0] + 6) = 0;
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << *max_element(&szs[i][0], &szs[i][0] + 6) << " ";
    }
    cout << *max_element(&szs[5][0], &szs[5][0] + 6);

}