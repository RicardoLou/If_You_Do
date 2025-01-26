package com.pintia.codeday2;
//L1-017 到底有多二
import java.util.Scanner;

public class PTA017 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int length=n.length();
        int count = 0;
        double resualt=100;
        if(n.charAt(0)=='-') {
            resualt *= 1.5;
            length--;
        }
        if (n.charAt(n.length()-1)%2==0)
            resualt*=2;
        for (int i = 0; i < n.length(); i++) {
            if(n.charAt(i)=='2')
                count++;
        }
        resualt*=count*1.0/length;
        System.out.printf("%.2f",resualt);
        System.out.println("%");
    }
}
