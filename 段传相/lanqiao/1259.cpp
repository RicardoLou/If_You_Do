#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n = 1000000, count = 0;
    while (n) {
        count += n % 7;
        n /= 7;
    }
    cout << count;
    return 0;
}