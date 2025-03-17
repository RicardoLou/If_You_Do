#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void power_of_2(int n) {
    int a[MAX_LENGTH] = {0};
    a[0] = 1;  // 初始值 2^0 = 1
    int carry = 0;  // 进位变量
    int length = 1;  // 当前结果的位数

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < length; j++) {
            int temp = a[j] * 2 + carry;
            a[j] = temp % 10;
            carry = temp / 10;
        }
        
        // 处理最高位的进位
        // 1267650600228229401496703205376
        if (carry) {
            a[length++] = carry % 10;
            carry /= 10;
        }
    }

    // 输出结果
    printf("2^%d = ", n);
    for (int i = length - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    power_of_2(100);  // 计算 2^100
    return 0;
}
