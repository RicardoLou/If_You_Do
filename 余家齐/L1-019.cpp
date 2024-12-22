#include <iostream>
using namespace std;
int main()
{
    int A,B;
    int a1,b1,n,c1=0,c2=0;//A和B的酒量,n轮数,c1,c2喝了多少杯酒
    cin >> A >> B;
    a1=A;
    b1=B;
    cin >> n;
    for(int i=0;i<n;i++){
        int a2,b2,a3,b3;
        cin >> a2 >> a3 >> b2 >> b3;
        if(a3==a2+b2&&b3==a2+b2){
            c1++;
            c2++;
            a1--;
            b1--;
        }
        else if(a3==a2+b2){
            a1--;
            c1++;
        }
        else if(b3==a2+b2){
            b1--;
            c2++;
        }
        if(a1<0||b1<0){
            break;
        }
    }
    if(a1<0){
        cout << "A" << endl;
        cout << c2;
    }
    else{
        cout << "B" << endl;
        cout << c1;
    }
}