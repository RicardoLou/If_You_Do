#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, na, nb;
    cin >> n;
    while (n--) {
        cin >> na >> nb;
        int Sa = 0, Sb = 0, Na = na, Nb = nb, aflag = 0, bflag = 0;
        while (Na > 0) {
            Sa += Na % 10;
            Na /= 10;
        }
        while (Nb > 0) {
            Sb += Nb % 10;
            Nb /= 10;
        }
        if (na % Sb == 0) {
            aflag = 1;
        }
        if (nb % Sa == 0) {
            bflag = 1;
        }
        if ((aflag && bflag) || (!aflag && !bflag)) {
            cout << char(na > nb ? 'A' : 'B') << endl;
        }
        else if (aflag) {
            cout << 'A' << endl;
        }
        else if (bflag) {
            cout << 'B' << endl;
        }
    }

}