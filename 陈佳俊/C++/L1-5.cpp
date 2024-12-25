#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string std,exam;
    int test;
    cin >> n;

    vector<vector<string>> inform(1010, vector<string>(2));
    
    for(int i = 0; i < n;i++){
        cin >> std >> test >> exam;
        inform[test][0] = std;
        inform[test][1] = exam;
    }

    int m;
    cin >> m;
    while(m--){
        int i;
        cin >> i;
        cout << inform[i][0] << " " << inform[i][1] << endl;
    }
    return 0;
}