#include<bits/stdc++.h>
using namespace std;

int main() {

    string s, s1, s2;
    cin >> s;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b >> s1 >> s2;
        a--; b--;    //�����ַ���������±��Ǵ�0��ʼ������Ҫ��һ
        string cp = s.substr(a, b - a + 1), ss = s1 + s2;    //ss�����ж��Ƿ��в���λ�õ�
        s.erase(a, b - a + 1);    //������λ�õ�����ɾ��
        int ii = s.find(ss);    //�Ҳ���λ���Ƿ����
        if (ii == -1)    //���û�ҵ���s.find()����-1
            s += cp;    //+������ƴ���ַ�����s = s + cp;�������а��ϵ��ַ�ƴ�ӵ�s����
        else {    //����ҵ���s.find()�����ҵ��Ӵ�λ�õĵ�һ���ַ��ĵط�
            string tmp = s.substr(0, ii);    //����λ��ǰ���Ӵ�
            tmp += s1;    //������λ��ǰ�ı�־�Ӵ�����
            tmp += cp;    //�����е��ַ�������
            tmp += s.substr(ii + s1.length(), s.length() - ii - s1.length()); //������滹ʣ�µ�
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