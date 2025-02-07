package com.pintia.codeday2;
//L-031 到底是不是太胖了
import java.util.Scanner;

public class PTA031 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for (int i = 0; i < n; i++) {
            int tall=sc.nextInt();
            int weight=sc.nextInt();
            if(Math.abs(weight-(tall-100)*0.9*2)<(tall-100)*0.9*2*0.1)
                System.out.print("You are wan mei!");
            else if(weight-(tall-100)*0.9*2<0)
                System.out.print("You are tai shou le!");
            else System.out.print("You are tai pang le!");
            if(i+1!=n)
                System.out.println();
        }
    }
}
