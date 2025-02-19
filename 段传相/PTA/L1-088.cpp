#include<bits/stdc++.h>
using namespace std;

int main() {
    //       天梯赛    同分数
    int n, k, s, tts, pat, tf[291] = {}, count = 0;
    cin >> n >> k >> s;
    while (n--) {
        cin >> tts >> pat;
        if (tts >= 175) {
            if (pat >= s) {
                count++;
            }
            else if (tf[tts] < k) {
                count++;
                tf[tts]++;
            }
        }
    }
    cout << count;

}