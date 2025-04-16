#include<bits/stdc++.h>
using namespace std;

struct AA {
    string name;
    string sfzh;
    bool ff;
    string time;
    bool kz = 0;
    int idx;
    int ts = -1;
};

struct BB {
    int index;
    vector<AA> md;
};

bool isNum(string s) {
    stringstream sin(s);//字符流
    double d;
    char c;
    //转换为double，转换失败返回0
    if (!(sin >> d)) {
        return false;
    }
    //判断"3.f"这种数字加字符的情况，数字部分被上面接收，还剩下字符
    if (sin >> c) {
        return false;
    }
    return true;
}

bool px(AA a, AA b) {
    if (a.time == b.time) {
        return a.idx < b.idx;
    }
    return a.time < b.time;
}

int main() {

    int d, p;
    cin >> d >> p;
    vector<BB> mds(d);
    vector<AA> sy;
    map<string, int> mp, mf;
    for (int i = 0; i < d; i++) {
        int t, s;
        cin >> t >> s;
        vector<AA> aas;
        for (int j = 0; j < t; j++) {
            AA aa;
            cin >> aa.name >> aa.sfzh >> aa.ff >> aa.time;
            if (aa.sfzh.size() != 18) {
                continue;
            }
            else if (isNum(aa.sfzh)) {
                aa.idx = j;
                if (mf[aa.sfzh] == 0 && aa.ff == 1) {
                    mf[aa.sfzh] = 1;
                    sy.push_back(aa);
                }

                aas.push_back(aa);

            }
        }
        sort(aas.begin(), aas.end(), px);

        // cout<<"--------"<<endl;
        // for(auto x:aas){
        //     cout<<x.name<<' '<<x.sfzh<<' '<<x.ff<<' '<<x.time<<endl;
        // }
        // cout<<"--------"<<endl;

        mds[i].index = i;
        mds[i].md = aas;
        int kzs = s;
        for (int j = 0; kzs > 0 && j < mds[i].md.size() && j < s; j++) {
            if (mp[mds[i].md[j].sfzh] == 0 || i + 1 - mp[mds[i].md[j].sfzh] > 2) {
                kzs--;
                mds[i].md[j].kz = 1;
                mp[mds[i].md[j].sfzh] = i + 1;
                cout << mds[i].md[j].name << ' ' << mds[i].md[j].sfzh << endl;
            }


        }
    }
    for (auto x : sy) {
        cout << x.name << ' ' << x.sfzh << endl;
    }

}