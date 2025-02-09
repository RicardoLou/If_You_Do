package com.pintia.codeday2;

import java.util.Scanner;

public class PTA044 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        String move=sc.next();
        int count=0;
        while (!move.equals("End")){
            if (count==n){
                System.out.println(move);
                count=0;
            }
            else {
                if (move.equals("ChuiZi"))
                    System.out.println("Bu");
                else if (move.equals("JianDao"))
                    System.out.println("ChuiZi");
                else System.out.println("JianDao");
                count++;
            }
            move = sc.next();
        }
    }
}
