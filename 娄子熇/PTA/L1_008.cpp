#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int index = 0;
    int sum = 0;
    for(int i = a; i <= b; i ++) {
        printf("%5d", i);
        index ++;
        sum += i;
        if (index % 5 == 0 && i != b)
            printf("\n");
    }
    printf("\nSum = %d\n", sum);
    return 0;
}