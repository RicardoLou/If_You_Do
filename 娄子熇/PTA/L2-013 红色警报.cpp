/*
  @pintia psid=994805046380707840 pid=994805063963230208 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 红色警报
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805063963230208
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
vector<vector<int> > g(N);
bool vis[N];
bool st[N];
int n, m, k;

void dfs(int u) {
	vis[u] = true;
	for(int t : g[u]) {
		if (!st[t] && !vis[t]) {
			dfs(t);
		}
	}
}

// 统计联通
int count() {
    memset(vis, false, sizeof vis);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!st[i] && !vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int preCnt = count(); // 初始多少个联通的
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		st[a] = true; // 表示被攻占
		int tempCnt = count(); // 现在还剩多少联通
		if (tempCnt > preCnt) {
			// 影响了联通
			printf("Red Alert: City %d is lost!\n", a);
		} else {
			printf("City %d is lost.\n", a);
		}
		preCnt = tempCnt;
		// 全部沦陷
		if (i == n - 1) {
			cout << "Game Over." << endl;
			break;
		}
	}
	return 0;
}
// @pintia code=end