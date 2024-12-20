#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,f,i=0;
    int x[10];
    cin >>n;
    if(n<0){
        n=-n;
        cout <<"fu"<< " ";
    }
    while(n>0){
        int a=n%10;
        n=n/10;
        x[i]=a;
        i++;
    }
    i=i-1;
    while(i>=0){
        switch(x[i]){
            case 0: cout << "ling" ;break;
            case 1: cout << "yi" ;break;
            case 2: cout << "er" ;break;
            case 3: cout << "san" ;break;
            case 4: cout << "si" ;break;
            case 5: cout << "wu" ;break;
            case 6: cout << "liu" ;break;
            case 7: cout << "qi" ;break;
            case 8: cout << "ba" ;break;
            case 9: cout << "jiu" ;break;
        }
        if(i!=0){
            cout << " ";
        }
        i--;
    }
    cout << endl;
}