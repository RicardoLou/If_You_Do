#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> longest;
    int m = (int)sqrt(n);
    
    for(int i = 2; i <= m; i++){
        long long prd = 1;
        vector<int> cnt;
        for(int j = i; prd * j <= n; j++){
            prd = prd * j;
            if(n % prd == 0){
                cnt.push_back(j);
            }
        }
        if(cnt.size() > longest.size()){
            longest = cnt;
        }
    }
    int len = longest.size();
    if(len == 0){
        cout << "1\n" << n;
    }
    else cout << len << endl;
    for(int i = 0; i < len; i++){
        cout << longest[i];
        if(i < len - 1) cout << "*";
    }
    cout << endl;
    return 0;
}