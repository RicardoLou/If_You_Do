#include <iostream>
using namespace std;
int main()
{
    char ch[51];
    int x=0,z=0,s=0;//f判断正负，x判断有多少2，y判断奇偶,z判断位数
    double f=1,y=1;
    cin >> ch;
    for(int i=0;ch[i]!='\0';i++){
       if(ch[i] == '-'){
        f=1.5;
        i++; 
       } 
        s=s*10+(ch[i]-'0');
        if(ch[i]=='2'){
            x++;
        }
        z++;
    };
    if(s%2 ==0){
        y=2;
    }
    double a=(1.0*x/z)*f*y*100;
    printf("%.2f",a);
    cout << "%";
}