#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int col; // 非静态成员变量，存储排序列索引

    // 非静态比较函数，通过 this 指针访问非静态成员
    bool compare(const vector<int>& a, const vector<int>& b) {
        return a[col] > b[col]; // 按第 col 列降序排序
    }

public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        col = k; // 设置排序列索引
        sort(score.begin(), score.end(), [this](const vector<int>& a, const vector<int>& b) {
            return compare(a, b); // 调用非静态比较函数
        });
        return score;
    }
};