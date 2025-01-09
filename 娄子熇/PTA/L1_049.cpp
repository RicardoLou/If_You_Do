#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; // 高校数量
    cin >> N;

    vector<int> M(N); // 每所高校的队伍数
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    // 队列存储：高校编号和当前队员的编号
    queue<pair<int, int>> q;
    vector<int> totalStudents(N); // 每所高校的参赛队员总数

    for (int i = 0; i < N; i++) {
        totalStudents[i] = M[i] * 10; // 每支队伍10人
        q.push({i + 1, 1}); // 初始化为每校第一位队员
    }

    vector<vector<int>> seating(N); // 保存每所高校的座位安排
    int seatNumber = 1; // 当前分配的座位号

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int school = current.first;
        int student = current.second;

        // 分配座位号
        seating[school - 1].push_back(seatNumber++);

        // 如果当前学校还有剩余队员，则将下一位队员加入队列
        if (student < totalStudents[school - 1]) {
            q.push({school, student + 1});
        }

        // 如果队列只剩下一所学校，进行隔位安排
        if (q.size() == 1) {
            auto lastSchool = q.front().first;
            auto lastStudent = q.front().second;
            q.pop();
            for (int i = lastStudent; i <= totalStudents[lastSchool - 1]; i++) {
                seating[lastSchool - 1].push_back(seatNumber);
                seatNumber += 2; // 隔位就坐
            }
        }
    }

    // 输出结果
    for (int i = 0; i < N; i++) {
        cout << "#" << i + 1 << endl;
        for (int j = 1; j <= seating[i].size(); j++) {
            cout << seating[i][j - 1];
            if (j % 10 == 0 && j != seating[i].size()) cout << endl;
            else if(j != seating[i].size()) cout << " ";
        }
        cout << endl;
    }

    return 0;
}