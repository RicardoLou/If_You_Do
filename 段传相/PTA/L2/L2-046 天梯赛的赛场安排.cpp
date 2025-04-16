#include<bits/stdc++.h>
using namespace std;
//能混18分
int main() {

    int n, c, sum = 0;
    cin >> n >> c;
    vector<string> na(n);
    vector<int> rs(n);
    for (int i = 0; i < n; i++) {
        cin >> na[i] >> rs[i];
        cout << na[i] << ' ' << rs[i] / c + (rs[i] % c > 0) << endl;
        sum += rs[i];
    }
    cout << sum / c + (sum % c > 0);

}