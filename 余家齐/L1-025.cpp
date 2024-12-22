#include <iostream>
using namespace std;
int main()
{
    char  A[1001],B[1001];
    int t1=0,t2=0,s1=0,s2=0;
    cin >> A >> B;
    for(int i=0;A[i]!='\0';i++){
        if(A[i]-'0'>=0&&A[i]-'0'<=9){
            s1=s1*10+(A[i]-'0');
        }
        else if(A[i+1]==' '){
            t1=1;
            break;
        }
        else{
            t1=1;
            break;
        }
        if(A[i+1]=='\0'){
            break;
        }
    }
    for(int i=0;B[i]!='\0';i++){
        if(B[i]-'0'>=0&&B[i]-'0'<=9){
            s2=s2*10+(B[i]-'0');
        }
        else if(B[i+1]==' '){
            t2=1;
            break;
        }
        else{
            t2=1;
            break;
        }
        if(B[i+1]=='\0'){
            break;
        }
    }
    if(t1==1&&t2==0){
        cout << "? + "<< s2 << " = ?"; 
    }
    else if(t1==0&&t2==1){
        cout << s1 << " + ?" << " = ?"; 
    }
    else if(t1==1&&t2==1){
        cout << "? + ?" << " = ?"; 
    }
    else{
        cout << s1 << " + "<< s2 << " = "<< s1+s2; 
    }
    cout << endl;
}