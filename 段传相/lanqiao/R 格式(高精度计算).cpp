#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 请在此输入您的代码
    int n;
    string d;
    cin >> n >> d;

    int len = d.length(), xsd, cut = 0;
    vector<int> v;
    for (int i = len - 1; i >= 0; i--) {//反向遍历转数字，方便用push_back进位
        if (d[i] == '.') {
            xsd = cut;//小数点位置
            continue;
        }
        cut++;
        v.push_back(int(d[i] - '0'));
    }

    while (n--) {
        int t = 0;//进位
        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i] * 2 + t;
            if (v[i] >= 10) {
                t = v[i] / 10;
                v[i] %= 10;
            }
            else {
                t = 0;
            }
        }
        if (t > 0) {
            v.push_back(t);
        }
    }
    //cout<<xsd<<' '<<v[xsd-1]<<endl;
    if (v[xsd - 1] >= 5) {//四舍五入
        int t = 1;
        for (int i = xsd; i < v.size(); i++) {
            v[i] += t;
            if (v[i] >= 10) {
                v[i] -= 10;
            }
            else {
                t = 0;
                break;
            }
        }
        if (t > 0) {
            v.push_back(t);
        }
    }
    for (int i = v.size() - 1; i >= xsd; i--) {
        cout << v[i];
    }
}