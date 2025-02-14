package com.pintia.codeday2;

import java.util.Scanner;

public class PTA062 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            char[] ch=sc.nextLine().toCharArray();
            if((ch[0]+ch[1]+ch[2])==(ch[3]+ch[4]+ch[5]))
                System.out.println("You are lucky!");
            else System.out.println("Wish you good luck.");
        }
    }
}
