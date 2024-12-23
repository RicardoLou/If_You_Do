#include <iostream>
using namespace std;
int main()
{
    int n;
    char c;
    cin >> n >> c;
    //题目有问题i<n/2的话只过一半的案例，i<=n/2过另一半
    for(int i = 0; i < n/2; i++){
        for(int j=0; j<n; j++){
            cout << c;
        }
        cout << endl;
    }

}