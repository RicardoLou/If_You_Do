#include<bits/stdc++.h>
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    int cxc[b - a + 1] = {};
    for (int i = a; i <= b; i++) {
        int m = i, jc, cx = i, count = 0;
        while (cx > 9) {
            jc = 1;
            m = cx;
            while (m > 0) {
                jc *= m % 10;
                m /= 10;
            }
            cx = jc;
            count++;
        }
        cxc[i - a] = count;
        //cout<<cx<<endl;
    }

    int max = *max_element(cxc, cxc + b - a + 1);
    stringstream ss; // ʹ��stringstream����������ַ���

    for (int i = 0; i < b - a + 1; ++i) {
        if (cxc[i] == max) {
            ss << i + a << " ";
        }
    }

    string s = ss.str();
    s.pop_back(); // �Ƴ����һ���ո�
    cout << max << endl << s; // ��������������ͷ�������������

}

