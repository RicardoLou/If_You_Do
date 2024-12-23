#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,cnt = 0;
    cin >> a >> b;
    int sum = 0;
    
    if(a <= b && a >= -100 && b <= 100){
        for(int i = a; i <=b; i++){
            sum += i;
            printf("%5d",i);
            cnt++;
            if(cnt % 5 == 0) cout << endl;
        }
    }
    if(cnt %5 != 0) cout << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}