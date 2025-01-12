#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<long long> fz, fm;
    long long fzsum = 0, fmsum = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int tmp = __gcd(stoi(s.substr(0, s.find('/'))), stoi(s.substr(s.find('/') + 1, s.length() - 1)));
        fz.push_back(stoi(s.substr(0, s.find('/'))) / tmp);
        fm.push_back(stoi(s.substr(s.find('/') + 1, s.length() - 1)) / tmp);
        fmsum *= fm[i];
    }
    for (int i = 0; i < fz.size(); i++) {
        int sum = fz[i];
        for (int j = 0; j < fm.size(); j++) {
            if (j != i) {
                sum *= fm[j];
            }
        }
        fzsum += sum;
    }
    if (fzsum == 0) {
        cout << 0;
    }
    else if (fzsum / fmsum == 0) {
        if (fmsum / __gcd(fzsum, fmsum) < 0) {
            cout << "-" << fzsum / __gcd(fzsum, fmsum) << "/" << fmsum / __gcd(fzsum, fmsum) * -1;
        }
        else {
            cout << fzsum / __gcd(fzsum, fmsum) << "/" << fmsum / __gcd(fzsum, fmsum);
        }
    }
    else if (fzsum % fmsum == 0) {
        cout << fzsum / fmsum;
    }
    else {
        if (fzsum / fmsum < 0) {
            cout << fzsum / fmsum << " -" << fzsum / __gcd(fzsum, fmsum) % (fzsum / fmsum) << "/" << fmsum / __gcd(fzsum, fmsum) * -1;
        }
        else {
            cout << fzsum / fmsum << " " << fzsum / __gcd(fzsum, fmsum) % (fzsum / fmsum) << "/" << fmsum / __gcd(fzsum, fmsum);
        }
    }

}