#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x = i, f1 = 1, f2 = 1, flag = 1;
        while (x) {
            if (flag > 0 && x % 10 % 2 == 0) {
                f1 = 0;
                break;
            }
            else if (flag < 0 && x % 10 % 2 != 0) {
                f2 = 0;
                break;
            }
            flag = -1 * flag;
            x /= 10;
        }
        if (f1 && f2) {
            count++;
        }
    }
    cout << count;
    return 0;
}