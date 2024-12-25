package com.pintia.codeday2;
//L1-002 打印沙漏
import java.util.Scanner;

public class L002 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int count=0;
        int i;
        int h=0;
        String s=sc.next();
        int t=(int)(Math.round(n/2.0));
        if(n>4&&n<=1000) {
            for (i = 1; i <= n / 2; i += 2) {
                if (t - i < 0)//t t
                    break;
                t = t - i;//8 5
                h++;//1 2
            }
            int x = i - 2;
            for (int j = 1; j <= h; j++) {
                for (int k = 0; k < x; k++) {//5
                    count++;
                    System.out.print(s);
                }
                x = x - 2;//3
                System.out.print("\n");
                for (int k = 0; k < j; k++) {
                    if (j != h)
                        System.out.print(" ");
                }
            }
            x = x + 2;
            for (int j = h - 1; j > 0; j--) {//2
                x = x + 2;
                for (int k = j; k > 1; k--) {//2
                    System.out.print(" ");
                }
                for (int k = 0; k < x; k++) {
                    count++;
                    System.out.print(s);
                }
                System.out.print("\n");
            }
        }
        else if(n>0){
            if(n==3)
                for (int j = 0; j < n; j++) {
                    System.out.print(s);
                    count++;
                }
            else {
                System.out.print(s);
                count = 1;
            }
            System.out.print("\n");
        }
        System.out.println(n-count);
    }
}
