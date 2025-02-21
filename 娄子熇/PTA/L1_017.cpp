#include <iostream>
#include <string>
#include <iomanip>  // 用于格式化输出

using namespace std;
 
int main() {
    string s;
    getline(cin, s);  // 读取输入字符串

    // 判断是否为负数
    bool is_negative = s[0] == '-';
    // 统计字符 '2' 的数量
    int count_of_two = 0;
    for (char ch : s) { 
        if (ch == '2') {
            count_of_two++;
        }
    }
    // 判断最后一个字符是否为偶数
    bool is_last_digit_even = (s.back() - '0') % 2 == 0;

    // 计算有效长度（如果为负数，去掉负号）
    int effective_length = is_negative ? s.length() - 1 : s.length();

    // 计算 '2' 的出现频率
    double frequency = static_cast<double>(count_of_two) / effective_length;

    // 根据条件调整结果
    if (is_last_digit_even) {
        frequency *= 2.0;
    }
    if (is_negative) {
        frequency *= 1.5;
    }

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2) << frequency * 100 << "%" << endl;

    return 0;
}