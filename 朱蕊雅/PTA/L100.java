package com.pintia.codeday2;

import java.util.Scanner;

public class L100 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n= sc.nextInt(), m = sc.nextInt(),sum=0;
            for (int i = 0; i < m; i++) {
                sum=sum+sc.nextInt();
            }
            if(sum/n==m)
                System.out.println(n);
            else if(sum/n==m-1)
                System.out.println(sum-n*(m-1));
            else
                System.out.println(0);
        }
}
