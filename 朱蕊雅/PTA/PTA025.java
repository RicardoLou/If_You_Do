package com.pintia.codeday2;

import java.util.Scanner;

public class PTA025 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String[] str=sc.nextLine().split(" ");
        String str2="",resualt;
        int i;
        for (i = 1; i < str.length; i++) {
            str2 += str[i] + " ";
        }
        if(i>2)
            str[1] = str2;
        for (int j = 0; j < 2; j++) {
            int k;
            for (k = 0; k < str[j].length(); k++) {
                if(str[j].charAt(k)<'0'||str[j].charAt(k)>'9')
                    break;
            }
            if(k<str[j].length()||Integer.parseInt(str[j])<1||Integer.parseInt(str[j])>1000)
                str[j]="?";
        }
        if(str[0].equals("?")&&str[1].equals("?"))
            System.out.println("? + ? = ?");
        else if(str[0].equals("?"))
            System.out.println("? + "+str[1]+" = ?");
        else if(str[1].equals("?"))
            System.out.println(str[0]+" + ? = ?");
       else {
           System.out.println(str[0]+" + "+str[1]+" = "+(Integer.parseInt(str[0])+Integer.parseInt(str[1])));
        }
    }
}

