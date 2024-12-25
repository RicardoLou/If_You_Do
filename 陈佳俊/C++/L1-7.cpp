#include <bits/stdc++.h>
using namespace std;

int main(){
    string std;
    cin >> std;

    vector<string> vec = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    int k = std.size();
    
    if(std.length() > 0 && std[0] == '-')
    {
        cout << "fu ";
        for(int i = 1; i < k - 1; i++){
            cout << vec[std[i] - 48] << " ";
        }
    }
    else {
        for(int i = 0; i < k - 1; i++){
            cout << vec[std[i] - 48] << " ";
        }
    }
    cout << vec[std[k-1] - 48];
    cout << endl;
    return 0;
}