#include<bits/stdc++.h>
using namespace std;

//满二叉树，设n为深度；
//节点数=2^n-1；
//左子节点的编号=当前节点编号*2；右子节点的编号=当前节点编号*2+1
//叶子节点编号=叶子节点在树中的编号-节点数

int main() {

    int n, m;
    cin >> n >> m;
    int jds = pow(2, n) - 1;
    string s;
    while (m--) {
        cin >> s;
        int k = 1;
        for (char c : s) {
            if (c == 'y') {
                k = 2 * k;
            }
            else {
                k = 2 * k + 1;
            }
        }
        cout << k - jds << endl;
    }

}