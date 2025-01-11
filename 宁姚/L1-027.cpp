#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr, index;
    int temp[10] = {0};
    string phoneNumber;

    cin >> phoneNumber;
    for(auto p : phoneNumber) {
        temp[p - '0'] ++;
        if(temp[p - '0'] == 1) {
            arr.push_back(p - '0');
        }
    }

    sort(arr.rbegin(), arr.rend());
    
    int count = 0;
    for(auto p : phoneNumber) {
        for(int i = 0; i < arr.size(); i++) {
            if(p - '0' == arr[i]) {
                index.push_back(i);
            }
        }
    }

    cout << "int[] arr = new int[]{";
    int tempCount = 0;
    for(auto a : arr) {
        cout << a;
        if(tempCount < arr.size() - 1) {
            cout << ",";
        }
        tempCount ++;
    }
    cout << "};" << endl;
    
    cout << "int[] index = new int[]{";
    tempCount = 0;
    for(auto i : index) {
        cout << i;
        if(tempCount < index.size() - 1) {
            cout << ",";
        }
        tempCount ++;
    }
    cout << "};" << endl;
}