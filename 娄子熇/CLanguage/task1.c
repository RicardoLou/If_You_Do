#include<stdio.h>

void fun(int a[55], int n) {
    int i, k;
    int b[55];
    for(i = 0; i < n; i ++) {
        for(k = 1; k <= 27; k ++) {
            b[2 * k - 1] = a[k];
            b[2 * k] = a[27 + k];
        }
        for(i = 0; i < n; i ++) {
            a[i] = b[i];
        }
    }
}

int main() {
    int m, a[55], i;
    printf("请输入");
    scanf("%d", &m);
    for(i = 1; i < 55; i ++) {
        a[i] = i;
    }
    fun(a, m);

    for(i = 1; i < 55; i ++) {
        printf("%d", a[i]);
    }
    system("pause");
    return 0;
}