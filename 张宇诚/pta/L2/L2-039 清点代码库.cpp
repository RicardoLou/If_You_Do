#include <bits/stdc++.h>
using namespace std;

int N, M;

struct MyData
{
    vector<int> vec;
    //重载<运算符（set排序所需）注意：不能漏写const
    bool operator< (const MyData & other) const
    {
        if(vec[0] < other.vec[0]) return false;
        if(vec[0] == other.vec[0])
        {
            for(int i = 1; i < vec.size(); i ++)
            {
                if(vec[i] > other.vec[i]) return false;
                else if(vec[i] < other.vec[i]) return true;
            }
        }
        return true;
    }
};

int main()
{
    cin >> N >> M;

    map<vector<int>, int> mp;    //用map快速记录重复次数
    set<MyData> myset;    //用set进行排序（排序规则来自MyData重载<运算符）

    for(int i = 0; i < N; i ++)
    {
        vector<int> nums;
        for(int j = 0; j < M; j ++)
        {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        auto iter = mp.find(nums);
        if(iter == mp.end())
        {
            mp[nums] = 1;
        }
        else {
            mp[nums] += 1;
        }
    }

    for(auto it : mp)
    {
        vector<int> vec;
        vec.push_back(it.second);
        for(int num : it.first)
        {
            vec.push_back(num);
        }
        MyData mydata;
        mydata.vec = vec;
        myset.insert(mydata);
    }

    cout << myset.size() << endl;
    
    for(auto it : myset)
    {
        cout << it.vec[0];
        for (int i = 1; i < it.vec.size(); i ++)
        {
            cout << " " << it.vec[i];
        }
        cout << endl;
    }
    
    return 0;
}