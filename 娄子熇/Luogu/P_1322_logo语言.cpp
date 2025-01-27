#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int calculateDistance() {
    char ch, x;
    string wz;
    int k;
    int dis = 0;
    while(cin >> ch)
    {
        if(ch == ']') 
            break;
        cin >> wz;
        cin >> k; // 这里只读了数字
        if(ch == 'R') // REPEAT
        {
            // x ： 中括号
            x = getchar();
            // repeat k 次
            dis += k * calculateDistance();
            x = getchar();
        }
        if(ch == 'B') // BK
        {
            x = getchar(); 
            dis -= k;
        }
        if(ch == 'F') // FD
        {
            x = getchar(); 
            dis += k;
        }
        if(x == ']') break;
    }
    return dis;
}

// 主函数
int main() {
    cout << abs(calculateDistance()) << endl;
    return 0;
}