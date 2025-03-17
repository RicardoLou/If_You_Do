#include<bits/stdc++.h>
using namespace std;

int main() {

    string s, s1, s2;
    cin >> s;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b >> s1 >> s2;
        a--; b--;    //由于字符串数组的下标是从0开始，即需要减一
        string cp = s.substr(a, b - a + 1), ss = s1 + s2;    //ss用来判断是否有插入位置的
        s.erase(a, b - a + 1);    //将剪切位置的内容删掉
        int ii = s.find(ss);    //找插入位置是否存在
        if (ii == -1)    //如果没找到，s.find()返回-1
            s += cp;    //+：代表拼接字符串，s = s + cp;即将剪切板上的字符拼接到s后面
        else {    //如果找到，s.find()返回找到子串位置的第一个字符的地方
            string tmp = s.substr(0, ii);    //插入位置前的子串
            tmp += s1;    //将插入位置前的标志子串插入
            tmp += cp;    //将剪切的字符串插入
            tmp += s.substr(ii + s1.length(), s.length() - ii - s1.length()); //插入后面还剩下的
            s = tmp;
        }
    }
    cout << s << endl;

}

void test() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    while (n--) {
        int b, e;
        string l, r, s;
        cin >> b >> e >> l >> r;
        cout << "l=" << l << ' ' << "r=" << r << endl;
        s = str.substr(b - 1, e - b + 1);
        str.erase(b - 1, e - b + 1);
        cout << "s=" << s << endl;
        int l_index = 0, r_index = 0, a = 0;
        while (1) {
            l_index = str.find(l, a);
            if (l_index == string::npos) {
                break;
            }
            r_index = str.find(r, l_index + l.size());
            cout << l_index << " " << r_index << endl;
            if (r_index - l_index + l.size() == 1) {
                break;
            }
            else {
                a += l_index + 1;
            }
        }
        if (l_index != string::npos) {
            str.insert(r_index, s);
            cout << 6 << endl;
        }
        else {
            str += s;
        }
        cout << str << endl;
    }
    cout << str;
}