#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();  // 读取整数后，忽略掉换行符

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);  // 读取一行字符串
        if (s.length() >= 2) {
            s.erase(s.length() - 1);  // 去掉最后一个字符
            s[s.length() - 1] = 'i';  // 替换倒数第二个字符为 'i'
        }
        cout << s << endl;
    }

    return 0;
}