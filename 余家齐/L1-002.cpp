#include <iostream>
using namespace std;
int main()
{
    int n,i,j,s=1,x;
    cin >> n;
    for(i=1,j=1;s<=n;i+=2){
        s+=i*2;
        j++;
    }
    j-=1;
    cout << j << endl;
    x=n-(s-(i*2));
    for(i=j,x=0;i>=0;i--){
        for(int k=0;k<=x-1;k++){
            cout << " ";
        }
        x++;
        for(int k=1;k<=i*2-1;k++){
            cout << "*";
        }
        cout << endl;
    }
    cout << x;
}