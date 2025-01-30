package com.pintia.codeday2;

import java.util.Scanner;

public class PTA028 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int num;
        for (int i = 0; i < n; i++) {
            num= sc.nextInt();
            if (su(num))
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
    public static boolean su(int n){
        if(n<1)
            return false;
        int i;
        for (i = 2; i < (int)Math.sqrt(n) + 1; i++) {
            if(n%i==0)
                break;
        }
        if(i>=(int)Math.sqrt(n) + 1)
            return true;
        return false;
    }
}


