package com.pintia.codeday2;

import java.util.Scanner;

public class PTA059 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        String[][] str= new String[n][2];
        for (int i = 0; i < n; i++) {
            str[i]=sc.nextLine().split(",");
            String front=str[i][0];
            if(str[i][0].length() >= 3)
                front=str[i][0].substring(str[i][0].length()-3);
            String after=str[i][1].substring(str[i][1].length()-4,str[i][1].length()-1);
            if(front.equals("ong")&&after.equals("ong")){
                System.out.print(str[i][0]+",");
                String[] subString=str[i][1].split(" ");
                for (int j = 0; j < subString.length-3; j++) {
                    System.out.print(subString[j]+" ");
                }
                System.out.println("qiao ben zhong.");
            }
            else System.out.println("Skipped");
        }
    }
}
