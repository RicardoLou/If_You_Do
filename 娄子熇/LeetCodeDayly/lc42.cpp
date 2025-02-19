#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for(int i = 0; i < height.size(); i ++) {
            while (!s.empty() && height[i] >= height[s.top()]) {
                int t = height[s.top()];
                s.pop(); // 更小的那个，相当于0
                if (s.empty()) break; // 避免第一个比第二个小的情况
                int h = min(height[i], height[s.top()]) - t;
                ans += h * (i - s.top() - 1);
            } 
            s.push(i);
        }
        return ans;
    }
};