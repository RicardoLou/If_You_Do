package com.pintia.codeday2;
//L-032 Left-pad
import java.util.Scanner;

public class PTA032 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char symbol = sc.next().charAt(0);
        String tostr = "";
        sc.nextLine();
        String str = sc.nextLine();
        if (str.length() < n){
            for (int i = 0; i < n - str.length(); i++)
                tostr += symbol;

            System.out.println(tostr+str);
            }
        else if (str.length() > n) {
            for (int i = str.length() - n; i < str.length(); i++)
                tostr += str.charAt(i);
            System.out.println(tostr);
        }
        else
            System.out.println(str);
    }
}
