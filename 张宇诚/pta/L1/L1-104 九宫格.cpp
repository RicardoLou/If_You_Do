#include <iostream>
#include <set>
using namespace std;
int func(int a[9][9])
{
    for(int y = 0; y < 9; y ++)
    {
        set<int> s1, s2;
        for(int x = 0; x < 9; x ++)
        {
            if(s1.find(a[y][x]) == s1.end())
            {
                s1.insert(a[y][x]);
            }
            else{
                return 0;
            }
            if(s2.find(a[x][y]) == s2.end())
            {
                s2.insert(a[x][y]);
            }
            else{
                return 0;
            }
        }
    }
    for(int Y = 0; Y < 9; Y += 3)
    {
        for(int X = 0; X < 9; X += 3)
        {
            set<int> s;
            for(int y = Y; y < Y + 3; y ++)
            {
                for(int x = X; x < X + 3; x ++)
                {
                    if(a[y][x] < 1 || a[y][x] > 9) return 0;
                    if(s.find(a[y][x]) == s.end())
                    {
                        s.insert(a[y][x]);
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    int a[1000][9][9];
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        for(int y = 0; y < 9; y ++)
        {
            for(int x = 0; x < 9; x ++)
            {
                cin >> a[i][y][x];
            }
        }
    }
    for(int i = 0; i < n; i ++)
    {
        cout << func(a[i]) << endl;
    }
    
    return 0;
}