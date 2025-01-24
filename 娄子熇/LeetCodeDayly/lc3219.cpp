#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        long long ans = 0;
        int i = 0, j = 0;
        int h = 1, v = 1; // 同一方向的块数
        while(i < m - 1 || j < n - 1) {
            if (j == n - 1 || i < m - 1 && horizontalCut[i] > verticalCut[j]) {
                // 同一行所有的快速都切了
                ans += horizontalCut[i ++] * v;
                h ++; // 切完列就多了一列了
            } else {
                // 同一列
                ans += verticalCut[j ++] * h;
                v ++;
            }
        }
        return ans;
    }
};