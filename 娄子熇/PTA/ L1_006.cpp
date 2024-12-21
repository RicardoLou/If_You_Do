#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, flag = 0;
  scanf("%d", &n);
  for(int len = 11; len > 0; len--) { // 因为要找最小的连续
    for(int i = 2; i <= sqrt(n); i++) {
      int sum = 1;
      for(int j = i; j < i + len; j++) {
        sum *= j;
        if(sum > n) break; // 累乘结果大于n了, 说明以i为起点的连乘不存在等于n的连续因子, 直接break 
      }
      if(n % sum == 0) {
        a = i;
        b = i+len-1;
        flag = 1;
        break;
      }
    }
    if(flag) break;
  }
  if(flag) {
    printf("%d\n", b-a+1);
    for(int i = a; i <= b; i++) {
      if(i == a) printf("%d", i);
      else
        printf("*%d", i);
    }
    printf("\n");
  } else {
    printf("1\n%d\n", n);//因为上面遍历不是从1开始的而是从2开始的，所以素数是找不到连续因子的 
  }
  return 0;
}