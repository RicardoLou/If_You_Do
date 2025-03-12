#include<bits/stdc++.h>
using namespace std;

int a[31] = {}, b[31] = {}, n = 0, j = 1;

//完全二叉树按顺序编号，左节点2x,右节点2x+1
void dfs(int x) {
    if (x <= n) {
        dfs(x * 2);
        dfs(x * 2 + 1);
        b[x] = a[j++];
    }
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    cout << b[1];
    for (int i = 2; i <= n; i++) {
        cout << " " << b[i];
    }

}