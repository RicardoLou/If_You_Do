#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
public:
    vector<int> pos[100010];
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i ++) {
            pos[arr[i]].push_back(i);
        }
    }
    int upper(vector<int>& a, int target) {
        int l = 0, r = a.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
    int low(vector<int>& a, int target) {
        int l = 0, r = a.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
    int query(int left, int right, int value) {
        if (pos[value].empty()) {
            return 0;
        }
        return upper(pos[value], right) - low(pos[value], left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */