#include<bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin >> str;
    vector<int> arr, index;

    for (char c : str) {
        if (find(arr.begin(), arr.end(), c - '0') == arr.end()) {
            arr.push_back(c - '0');
        }
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    for (char c : str) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == c - '0') {
                index.push_back(i);
            }
        }
    }

    cout << "int[] arr = new int[]{";
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ",";
    }
    cout << arr[arr.size() - 1] << "};" << endl;

    cout << "int[] index = new int[]{";
    for (int i = 0; i < index.size() - 1; i++) {
        cout << index[i] << ",";
    }
    cout << index[index.size() - 1] << "};" << endl;

}