#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s = "";
        cin >> s;
        //vector<int> v;
        // for(int j=0;j<s.size();j++){
        //   if(s[j]!='l'&&s[j]!='q'&&s[j]!='b'){
        //     v.push_back(j);
        //   }
        // }
        // int flag=1;
        // if(v.size()==0){
        //   flag=0;
        // }else{
        //   int l=v[0],ll=v[0],r=v[v.size()-1],rr=v[v.size()-1];
        //   while(l<=r&&s[l]==s[r]){
        //     l++;
        //     r--;
        //   }
        //   while(ll>=0&&rr<s.size()&&s[ll]==s[rr]){
        //     ll--;
        //     rr++;
        //   }
        //   if(l>r&&ll<0){
        //     flag=0;
        //   }
        // }
        // v.clear();

        int j;
        int x;
        for (j = s.size() - 1; j >= 0; j--) {
            if (s[j] != 'l' && s[j] != 'q' && s[j] != 'b') {
                break;
            }
        }
        for (x = 0; x < s.size(); x++) {
            if (s[x] != 'l' && s[x] != 'q' && s[x] != 'b') {
                break;
            }
        }
        int flag = 0;
        if (x > s.size() - j) {
            flag = 1;
        }
        else {
            for (int k = x, y = j; k < y; k++, y--) {
                if (s[k] != s[y]) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag) {
            cout << "No" << endl;//搞半天发现把o打成0了
        }
        else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}