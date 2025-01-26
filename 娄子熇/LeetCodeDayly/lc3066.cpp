#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ans = 0;
        while(pq.top() < k) {
            long long a = pq.top();pq.pop();
            long long b = pq.top();pq.pop();
            pq.push(a * 2 + b);
            ans ++;
        }
        return ans;
    }
};