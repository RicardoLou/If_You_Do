#include <bits/stdc++.h>
#define MAX_SIZE 10000000

using namespace std;

int N, M;
vector<vector<int>> points(1, vector<int>());
array<int, MAX_SIZE> saves;
int curPoint = 1;

void jump(int j)
{
    vector<int> &choose = points[curPoint];
    curPoint = choose[j];
}

void save(int j)
{
    saves[j] = curPoint;
    cout << curPoint << endl;
}

void restore(int j)
{
    curPoint = saves[j];
}

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++)
    {
        int K;
        cin >> K;
        vector<int> nums;
        nums.push_back(K);
        for (int j = 0; j < K; j ++)
        {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        points.push_back(nums);
    }
    
    for (int i = 0; i < M; i ++)
    {
        int k, j;
        cin >> k >> j;
        switch(k)
        {
            case 0 : 
                jump(j);
                break;
            case 1 : 
                save(j);
                break;
            case 2 : 
                restore(j);
                break; 
        }
    }

    cout << curPoint << endl;
    
    return 0;
}


