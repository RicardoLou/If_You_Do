#include <bits/stdc++.h>
using namespace std;

int main() {
    int inputCount, outputCount;
    int id[1000], s[1000][2];
    cin >> inputCount;
    for(int i = 0; i < inputCount; i++) {
        cin >> id[i] >> s[i][0] >> s[i][1];
    }

    cin >> outputCount;
    int output[outputCount];
    for(int i = 0; i < outputCount; i++) {
        cin >> output[i];
    }

    for(int i = 0; i < outputCount; i++) {
        for(int j = 0; j < inputCount; j++) {
            if(s[j][0] == output[i]) {
                cout << id[i] << " " << s[j][1] << endl;
                break;
            }
        }
    }
}