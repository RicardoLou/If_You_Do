// 中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

// 输入格式：
// 输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

// 输出格式：
// 按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）。
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    string text;
    
    // 输入每列字符数
    cin >> N;
    cin.ignore();  // 忽略掉接下来的换行符
    
    // 输入文本字符串
    getline(cin, text);

    int len = text.length();  // 获取字符串的长度
    int rows = (len + N - 1) / N;  // 计算行数，向上取整
    
    // 创建一个二维数组，表示排版后的字符
    vector<vector<char>> grid(rows, vector<char>(N, ' '));  // 默认为空格填充

    // 将字符串按照列优先顺序填入grid
    for (int i = 0; i < len; ++i) {
        int row = i / N;  // 当前字符所在行
        int col = i % N;  // 当前字符所在列
        grid[row][col] = text[i];  // 填充字符
    }

    // 按古风排版输出（竖着打印）
    for (int col = N - 1; col >= 0; --col) {
        for (int row = 0; row < rows; ++row) {
            if (grid[row][col] != ' ') {  // 只有在该位置有字符时才输出
                cout << grid[row][col];
            }
        }
    }

    return 0;
}
