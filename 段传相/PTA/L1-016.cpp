#include<bits/stdc++.h>
using namespace std;

int main() {

    int a;
    int q[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
    char M[] = { '1','0','X','9','8','7','6','5','4','3','2' };
    string s;
    vector<string> sfzhs;
    vector<string> err;

    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> s;
        sfzhs.push_back(s);
    }

    for (string sfzh : sfzhs) {
        int i = 0, flag = 1, sum = 0;
        for (; i < sfzh.length() - 1; i++) {
            if ('0' <= sfzh[i] && sfzh[i] <= '9') {
                sum += int(sfzh[i] - '0') * q[i];
                //cout<<int(sfzh[i]-'0')*q[i]<<endl;
            }
            else {
                err.push_back(sfzh);
                flag = 0;
                break;
            }
        }
        //cout<<sum<<endl;
        if (sfzh[i] != M[sum % 11] && flag) {
            //cout<<sfzh[i]<<" "<<M[sum%11]<<endl;
            err.push_back(sfzh);
        }
    }

    if (err.size()) {
        for (auto c : err) {
            cout << c << endl;
        }
    }
    else {
        cout << "All passed";
    }

}