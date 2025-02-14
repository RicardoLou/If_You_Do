package com.pintia.codeday2;

import java.util.Scanner;

public class PTA047 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for (int i = 0; i < n; i++) {
            String name=sc.next();
            int breathe=sc.nextInt();
            int pulse= sc.nextInt();
            if(breathe<15||breathe>20||pulse<50||pulse>70)
                System.out.println(name);

        }
    }
}
