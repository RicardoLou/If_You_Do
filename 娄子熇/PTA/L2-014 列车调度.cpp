/*
  @pintia psid=994805046380707840 pid=994805063166312448 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 列车调度
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805063166312448
*/
// @pintia code=start
// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805063166312448
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, cnt = 0;
    vector<int> v;
    cin >> n;
    while (n--) {
        cin >> a;
        int pos = upper_bound(v.begin(), v.end(), a) - v.begin();
        if (pos == v.size()) v.push_back(a);
        else v[pos] = a;
    }
    cout << v.size();
    return 0;
}
// @pintia code=end