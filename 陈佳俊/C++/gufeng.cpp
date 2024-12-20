// 中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

// 输入格式：
// 输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

// 输出格式：
// 按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）。
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string text;

    // 输入每列字符数和文本字符串
    cin >> N;
    cin.ignore();  // 忽略换行符
    getline(cin, text);

    int len = text.length();       // 字符串的长度
    int rows = (len + N - 1) / N;  // 向上取整计算行数

    // 输出字符，列优先，从下到上
    for (int col = 0; col < N; ++col) {  // 从第一列到最后一列
        for (int row = rows - 1; row >= 0; --row) {  // 从最后一行到第一行
            int idx = row * N + col;  // 计算索引
            if (idx < len) {          // 确保索引在范围内
                cout << text[idx];
            } else {
                cout << ' ';          // 补空格
            }
        }
        cout << endl;  // 每列换行
    }

    return 0;
}
