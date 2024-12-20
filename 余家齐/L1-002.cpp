#include <iostream>
using namespace std;
int main()
{
    int n,i,j,s;
    cin >> n;
    for(i=3,j=1,s=1;s<=n;i+=2)
    {
        s+=i*2;
        j++;
    }
    cout << j-1 << endl;
    cout << n-(s-(i*2)) << endl;
}