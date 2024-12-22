#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    n -= 1;
    int index = 1;
    int step = 1;
    
    while(n >= ((index + 2) * 2)) {
        n -= ((index + 2) * 2);
        index += 2;
        step ++;
    }
    int num = step * 2 - 1; // 每一行打印的总数
    for(int i = 1; i <= step; i ++) {
       int limit = (step - i) * 2 + 1;//当前层需要打印的数量
        // 打印空格
        for(int j = 1; 2 * j <= num - limit; j ++) {
            cout << " ";
        }
        for(int j = 1; j <= limit; j ++) {
            cout << c;
        }
        cout << endl;
    }
    
    for(int i = step - 1; i >= 1; i --) {
        int limit = (step - i) * 2 + 1;//当前层需要打印的数量
        // 打印空格
        for(int j = 1; 2 * j <= num - limit; j ++) {
            cout << " ";
        }
        for(int j = 1; j <= limit; j ++) {
            cout << c;
        }
        cout << endl;
    }
    cout << n << endl;
    return 0;
}