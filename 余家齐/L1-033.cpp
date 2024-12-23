#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int year,x=0,num,a[10];
    char chyear[5];
    cin>>year>>num;
    for(int i=year;i<=3000;i++){
        for (int k = 0; k < 10; k++) {
            a[k] = 0;
        }
        sprintf(chyear, "%04d",i);
        for(int j=0;j<4;j++){
            switch(chyear[j]-'0'){
                case 0: a[0]=1;break;
                case 1: a[1]=1;break;
                case 2: a[2]=1;break;
                case 3: a[3]=1;break;
                case 4: a[4]=1;break;
                case 5: a[5]=1;break;
                case 6: a[6]=1;break;
                case 7: a[7]=1;break;
                case 8: a[8]=1;break;
                case 9: a[9]=1;break;
            }
        }
        x=a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
        if(x==num){
            cout<< i-year << " " << chyear <<endl;
            break;
        }
    }
}