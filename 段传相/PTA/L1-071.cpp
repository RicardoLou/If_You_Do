#include<bits/stdc++.h>
using namespace std;

//������������nΪ��ȣ�
//�ڵ���=2^n-1��
//���ӽڵ�ı��=��ǰ�ڵ���*2�����ӽڵ�ı��=��ǰ�ڵ���*2+1
//Ҷ�ӽڵ���=Ҷ�ӽڵ������еı��-�ڵ���

int main() {

    int n, m;
    cin >> n >> m;
    int jds = pow(2, n) - 1;
    string s;
    while (m--) {
        cin >> s;
        int k = 1;
        for (char c : s) {
            if (c == 'y') {
                k = 2 * k;
            }
            else {
                k = 2 * k + 1;
            }
        }
        cout << k - jds << endl;
    }

}