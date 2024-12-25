#include <bits/stdc++.h>
using namespace std;

int main(){
    int d,m,dig[10] = {0};
    string str;
    cin >> str;
    for(int i = 0; i < 10; i++){
        d = i;
        m = 0;
        for(int j = str.size() - 1; j >= 0; j--){
            if(str[j] - 48 == i) m++;
        }
        if(m > 0) cout << d << ":" << m << endl;
    }
}