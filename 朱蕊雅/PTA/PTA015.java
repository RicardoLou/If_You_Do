package com.pintia.codeday2;
//L1-015 跟奥巴马一起画方块
import java.util.Scanner;

public class PTA015 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        String str=sc.next();
        for (int i = 0; i < (a+1)/2; i++) {
            for (int j = 0; j <a; j++) {
                System.out.printf(str);
            }
            System.out.println();
        }
    }
}
