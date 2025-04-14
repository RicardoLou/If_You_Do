/* 
 * @pintia psid=994805046380707840 pid=994805099426070528 compiler=GXX
 * 
 * ProblemSet: 团体程序设计天梯赛-练习集
 * 
 * Title: L1-033 出生年
 * 
 * https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805099426070528
 * 
 */
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

int main() {
    int year, num;
    int cntYear[10] = {0};  // 用于统计每个数字的出现次数
    cin >> year >> num;

    for (int i = year; i <= 3000; i++) {
        memset(cntYear, 0, sizeof(cntYear)); // 清空统计数组
        
        // 将年份转为四位字符串，确保补零
        string t = to_string(i);
        while (t.length() < 4) {
            t = '0' + t;  // 前面补零，确保年份是四位数
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
// @pintia code=end