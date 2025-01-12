package com.pintia.codeday2;
//L006 连续因子
import java.util.Scanner;

public class L006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count, maxcount = 0;
        int result, index = 0;
        int[] factor = new int[(int) Math.sqrt(n)];
        for (int i = 2; i <= (int) Math.sqrt(n); i++) {
            int j = i;
            count=0;
            int temp=n;
            while (temp % j == 0) {
                temp = temp / j;
                j++;
                count++;
            }
            if (count > maxcount) {
                maxcount = count;
                index = i;
            }
        }
        if (maxcount > 0) {
            System.out.println(maxcount);
            for (int i = index; i < index + maxcount; i++) {  // 输出连续因子序列
                if (i > index) {
                    System.out.print("*");
                }
                System.out.print(i);
            }
        }
        else {
            System.out.println(1);
            System.out.println(n);
        }
    }
}
