package com.pintia.codeday2;

import java.util.Scanner;

public class PTA050 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int num=(int)Math.pow(26,n)-sc.nextInt();
        StringBuilder sb=new StringBuilder();
        int pow=(int)Math.pow(26,n-1);
        for (int i = 0; i < n; i++) {
            sb.append((char)('a'+num/pow));
            num%=pow;
            pow/=26;
        }
        System.out.println(sb);
    }
}


