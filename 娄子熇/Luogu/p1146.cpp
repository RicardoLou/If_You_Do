#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];
int main() {
    int n;
    cin >> n;
    cout << n << endl;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            // 答案一定有并且要保证最小的字典序，所以一定是这样的顺序
            if (j != i) {
                a[j] = !a[j];
            }
            cout << a[j];
        }
        cout << endl;
    }
}