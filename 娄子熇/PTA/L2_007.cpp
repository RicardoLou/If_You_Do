#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int p[N];
int n;
int peopleNum[N], houseNum[N], areaNum[N];
vector<int> ship[N];
struct fam {
    int id;
    int famNum;
    int houseNum;
    int areaNum;
    double avgHouseNum;
    double avgAreaNum;
    bool operator < (const fam &rhs) const {
        if (avgAreaNum != rhs.avgAreaNum)
            return avgAreaNum > rhs.avgAreaNum;
        return id < rhs.id;
    }
};
vector<fam> f;
int find(int x) {
    if (p[x] == -1) return -1;
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) return;
    // 维护家里编号最小
    if (pa > pb) swap(pa, pb);
    p[pb] = pa; // 把最小的当成代表人物
    // 注意这里不要写反了
    peopleNum[pa] += peopleNum[pb];
    houseNum[pa] += houseNum[pb];
    areaNum[pa] += areaNum[pb];
}

int main() {
    cin >> n;
    p[0] = -1;
    for(int i = 1; i <= n; i ++) {
        int tid, dad, mom, sonK;
        cin >> tid >> dad >> mom >> sonK;
        while(sonK --) {
            int son;
            cin >> son;
            ship[tid].push_back(son);
            p[son] = son;
            peopleNum[son] = 1;
        }
        if (dad != -1) {
            ship[tid].push_back(dad);
            p[dad] = dad;
            peopleNum[dad] = 1;
        }
        if (mom != -1) {
            ship[tid].push_back(mom);
            p[mom] = mom;
            peopleNum[mom] = 1;
        }
        p[tid] = tid;
        peopleNum[tid] = 1;
        cin >> houseNum[tid] >> areaNum[tid];
    }
    for(int i = 0; i < 10000; i ++) {
        // 对于每个人，合并他的亲属
        for(int j = 0; j < ship[i].size(); j ++) {
            merge(i, ship[i][j]);
        }
    }
    for(int i = 0; i < 10000; i ++) {
        // 每次找到一个家庭
        if (i == p[i]) {
            f.push_back({i, peopleNum[i], houseNum[i], areaNum[i], 1.0 * houseNum[i] / peopleNum[i], 1.0 * areaNum[i] / peopleNum[i]});
        }
    }
    sort(f.begin(), f.end());
    cout << f.size() << endl;
    for(int i = 0; i < f.size(); i ++) {
        printf("%04d %d %.3lf %.3lf\n", f[i].id, f[i].famNum, f[i].avgHouseNum, f[i].avgAreaNum);
    }
    return 0;
}