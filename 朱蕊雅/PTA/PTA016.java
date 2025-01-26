package com.pintia.codeday2;
//L1-016 查验身份证
import java.util.Scanner;

public class PTA016 {
    public static void main(String[] args) {
        int[] quan={7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1};
        char[] M={'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        boolean resualt=true;
        String[] str=new String[n];
        for (int i = 0; i < n; i++) {
            str[i] = sc.nextLine();
        }
        loop:for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < 17; j++) {
                if(str[i].charAt(j)<'0'||str[i].charAt(j)>'9') {
                    System.out.println(str[i]);
                    resualt=false;
                    continue loop;
                }
                    sum+=(str[i].charAt(j)-'0')*quan[j];
            }
            if(M[sum%11]!=str[i].charAt(17)){
                System.out.println(str[i]);
                resualt=false;
            }
        }
        if(resualt)
            System.out.println("All passed");
    }
}
