#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, num, h, m, sumtime = 0, count = 0;
    char c;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int book[1001] = { 0 }, time[1001] = { 0 };

        while (scanf("%d %c %d:%d", &num, &c, &h, &m)) {
            if (num == 0) break;
            book[num]++;
            if (c == 'S') {
                time[num] = h * 60 + m;
            }
            else if (book[num] % 2 == 0 && c == 'E') {
                time[num] = h * 60 + m - time[num];
                sumtime += time[num];
                count++;
                time[num] = 0;
            }
        }

        if (count == 0) {
            cout << "0 0" << endl;
        }
        else {
            cout << count << ' ' << int(sumtime * 1.0 / count + 0.5) << endl;
        }

        count = 0;
        sumtime = 0;
    }

}