#include <iostream>
using namespace std;
int main(){
    int R1,R2,C1,C2;
    cin >> R1 >> C1;
    int A[R1][C1];
    for(int i=0;i<R1;i++){
        for(int j=0;j<C1;j++){
            cin >> A[i][j];
        }
    }
    cin >> R2 >> C2;
    int B[R2][C2];
    for(int i=0;i<R2;i++){
        for(int j=0;j<C2;j++){
            cin >> B[i][j];
        }
    }
    int C[R1][C2];
    if(C1!=R2){
        cout << "Error: "<< C1 << " != " << R2<< endl;
        return 0;
    }
    else{
        for(int i=0;i<R1;i++){
            for(int j=0;j<C2;j++){
                C[i][j]=0;
                for(int k=0;k<C1;k++){
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        cout << R1 << " " << C2 << endl;
        for(int i=0;i<R1;i++){
            for(int j=0;j<C2;j++){
                cout << C[i][j];
                if(j!=C2-1){
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}