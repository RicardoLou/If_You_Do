#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> inputId;
    vector<string> outputId;
    int n;
    int a[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (str.length() != 18) {
            outputId.push_back(str);
            continue;
        }
        inputId.push_back(str);
    }

    for (string s : inputId) {
        int sum = 0;
        bool valid = true;

        for (int j = 0; j < 17; j++) {
            if (!isdigit(s[j])) {
                outputId.push_back(s);
                valid = false;
                break;
            }
            sum += (s[j] - '0') * a[j];
        }

        if (!valid) continue;

        int z = sum % 11;
        if (s[17] != m[z]) {
            outputId.push_back(s);
        }
    }


    if (outputId.empty()) {
        cout << "All passed" << endl;
    } else {
        for (string str : outputId) {
            cout << str << endl;
        }
    }

    return 0;
}
