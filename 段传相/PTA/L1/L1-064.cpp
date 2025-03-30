#include<bits/stdc++.h>
using namespace std;
//没满分，应该先替换can you、could you ，再替换I 和 me 
int ch(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    else if (c >= 'a' && c <= 'z') {
        return 2;
    }
    else if (c >= '0' && c <= '9') {
        return 3;
    }
    else {
        return 0;
    }
}

void th(string& ss, string toFind, string replacement) {
    size_t startPos = 0;
    while ((startPos = ss.find(toFind, startPos)) != std::string::npos) {
        if (ch(ss[startPos - 1]) == 0) {
            ss.replace(startPos, toFind.length(), replacement);

        }
        startPos += replacement.length();
    }
    return;
}

int main() {

    int n;
    cin >> n;
    getchar();
    while (n--) {
        string s, ss = "";
        getline(cin, s);
        cout << s << endl;
        int l = 0, r = s.size() - 1;
        while (s[l] == ' ') l++;
        while (s[r] == ' ') r--;
        for (int i = l; i < r + 1; i++) {
            if (s[i] == ' ') {
                if ((s[i + 1] == ' ') || (ch(s[i + 1]) == 0)) {
                    continue;
                }
                else if (s[i + 1] == 'I' && ch(s[i + 2]) == 0) {
                    ss += " you";
                    i++;
                }
                else if (s[i + 1] == 'm' && s[i + 2] == 'e' && ch(s[i + 3]) == 0) {
                    ss += " you ";
                    i += 3;
                }
                else {
                    ss += s[i];
                }
            }
            else if (s[i] != 'I' && ch(s[i]) == 1) {
                ss += char(s[i] + 32);
            }
            else if (s[i] == '?') {
                ss += '!';
            }
            else {
                ss += s[i];
            }
        }

        th(ss, "can you ", "I can ");
        th(ss, "could you ", "I could ");

        cout << "AI: " << ss << endl;

    }

}