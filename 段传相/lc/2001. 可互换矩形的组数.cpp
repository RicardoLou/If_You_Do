class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long count = 0;
        //unordered_map不排序的map减少时间消耗
        unordered_map<double, int> mp;
        for (int i = 0; i < rectangles.size(); i++) {
            mp[1.0 * rectangles[i][0] / rectangles[i][1]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            count += 1.0 * (it->second) * (it->second - 1) / 2;
            //组合公式C(n,2)=n*(n-1)/2
        }
        return count;
    }
};