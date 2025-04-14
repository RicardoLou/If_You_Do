/*
  @pintia psid=994805046380707840 pid=994805064676261888 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 关于堆的判断
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805064676261888
*/
// @pintia code=start
#include<bits/stdc++.h>
using namespace std;

// pre：堆是一个完全二叉树，小根堆指的是小的在上
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int heap[N];
int n, m;
map<int, int> pos;
int Hindex = 0;

void insert(int x) {
    heap[++Hindex] = x;
    pos[x] = Hindex;
    int i = Hindex;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        pos[heap[i]] = i;
        pos[heap[i / 2]] = i / 2;
        i /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        insert(x);
    }
    cin.ignore(); // 替代 getchar()

    while (m--) {
        string s;
        getline(cin, s);
        
        if (s.find("is the root") != -1) {
            int x;
            sscanf(s.c_str(), "%d is the root", &x);
            if (heap[1] == x) cout << "T" << endl;
            else cout << "F" << endl;
        } else if (s.find("siblings") != -1) {
            int a, b;
            sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
            int pa = pos[a] / 2, pb = pos[b] / 2;
            if (pa == pb && pa != 0) cout << "T" << endl;
            else cout << "F" << endl;
        } else if (s.find("parent") != -1) {
            int a, b;
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            if (pos[a] == pos[b] / 2) cout << "T" << endl;
            else cout << "F" << endl;
        } else {
            int x, y;
            sscanf(s.c_str(), "%d is a child of %d", &x, &y);
            if (pos[x] / 2 == pos[y]) cout << "T" << endl;
            else cout << "F" << endl;
        }
    }

    return 0;
}

// @pintia code=end