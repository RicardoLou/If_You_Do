#include<bits/stdc++.h>
using namespace std;

int main() {

    int ty[4], min, n;
    cin >> ty[0] >> ty[1] >> ty[2] >> ty[3] >> min >> n;
    int max = *max_element(begin(ty), end(ty));
    int count = 0, bj = 0;
    for (int i = 0; i < 4; i++) {
        if (max - ty[i] > n || ty[i] < min) {
            count++;
            bj = i + 1;
        }
    }
    if (count >= 2) {
        cout << "Warning: please check all the tires!";
    }
    else if (count == 1) {
        cout << "Warning: please check #" << bj << '!';
    }
    else {
        cout << "Normal";
    }

}