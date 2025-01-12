#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, a, b;
    bool bo[2] = {true, true};
    getline(cin, str);
    const char* c = str.c_str();
    a = b = "";

    if (c[0] != ' ')
    {
        while (*c != ' ')
        {
            a += *c;
            if (!isdigit(*c))
            {
                bo[0] = false;
            }
            c += 1;
        }
        c += 1;
        while(*c != '\0') {
            b += *c;
            if (!isdigit(*c))
            {
                bo[1] = false;
                break;
            }
            c += 1;
        }
    }
    else
    {
        bo[0] = false;
        c += 1;
        while (*c != '\0')
        {
            b += *c;
            if (!isdigit(*c))
            {
                bo[1] = false;
                break;
            }
        }
    }

    if (bo[0] && bo[1])
    {
        cout << a << " + " << b << " = " << stoi(a) + stoi(b);
    }
    else if (bo[0])
    {
        cout << a << " + " << "? = ?";
    }
    else if (bo[1])
    {
        cout << "? + " << b << " = ?";
    }
    else
    {
        cout << "? + ? = ?";
    }
}