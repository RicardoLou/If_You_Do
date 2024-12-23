#include<bits/stdc++.h>

using namespace std;

int main() {
    int year, num;
    cin >> year >> num;

    for (int i = year; ; i++) {
        int cntYear[10] = {0};
        string t = to_string(i);
        while (t.length() < 4) {
            t = '0' + t;  // 前面补零
        }

        // 记录每个数字出现的次数
        for (char c : t) {
            cntYear[c - '0']++;
        }

        // 检查不同数字的个数是否满足条件
        int distinctCount = 0;
        for (int j = 0; j < 10; j++) {
            if (cntYear[j] > 0) {
                distinctCount++;
            }
        }

        // 如果不同的数字个数满足条件，则输出
        if (distinctCount == num) {
            cout << i - year << " " << t << endl;
            return 0;
        }
    }
    return 0;
}