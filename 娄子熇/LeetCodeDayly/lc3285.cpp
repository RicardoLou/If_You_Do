#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 0; i + 1 < height.size(); i++) {
            if (height[i] > threshold) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};