#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,sum = 1,i = 1,layer = 0;
    char m;
    cin >> n >> m;
    
    while (n >= sum)
    {
        i += 2;
        sum += i * 2;
        layer++;
    }
    sum -= i  * 2;
    
    int index = layer;
    for(int i = 0; i < layer; i++){
        for (int j = 0; j < layer - index; j++)
        {
            cout << " ";
        }
        for(int j = 0; j < index * 2 - 1; j++){
            cout << m;
        }
        index = index - 1;
        cout << endl;
        }
        
        for(int i = 0; i < layer -1; i++){
            for(int j = 1; j < layer - i - 1; j++){
                cout << " ";
            }
            for(int j = 0; j < i * 2 + 3; j++){
                cout << m;
            }
            cout << endl;
        }

        cout << (n - sum);
    }