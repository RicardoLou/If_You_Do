#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, count = 0, tmp = 0, t = 0, sum = 1, max = 0;
    cin >> N;
    int m = sqrt(N);
    //����������˺������ӣ���˷�����������ӿ϶�ֻ��2~sqrt(n)+1֮��
    //������̸��һ������ n ������ʱ����˼�������һ������ d �ܹ����� n �� n%d=0��
    //��ô d ���� n ��һ�����ӡ������κη����� n�������ӿ��ԳɶԳ��֣����� d �� n/d��
    //����Ĺؼ��۲��ǣ���� d �� n ��һ��С�� sqrt(n) �����ӣ�
    //��ô n/d �ض����� sqrt(n)����֮��Ȼ��
    //����ζ��Ϊ���ҵ� n ���������ӣ�
    //����ʵ����ֻ��Ҫ���� 2 �� sqrt(n)���� sqrt(n)֮������Ƿ������� n��
    int yz[m] = {};
    for (int i = 2; i <= m + 1; i++) {
        if (N % i == 0) {
            yz[t++] = i;
        }
    }
    if (t == 0) {
        cout << 1 << endl << N;
    }
    else if (t == 1) {
        cout << 1 << endl << yz[0];
    }
    else {
        for (int i = 0; i < m - 1; i++) {
            sum = yz[i];
            count = 1;
            for (int j = i; j < m - 1; j++) {
                if (yz[j + 1] - yz[j] == 1 && N % (sum * yz[j + 1]) == 0) {
                    sum *= yz[j + 1];
                    count++;
                }
                else {
                    break;
                }
            }
            if (max < count) {
                max = count;
                tmp = i;
            }
        }
        cout << max << endl;
        cout << yz[tmp];
        for (int i = tmp + 1; i < tmp + max; i++) {
            cout << "*" << yz[i];
        }
    }

}