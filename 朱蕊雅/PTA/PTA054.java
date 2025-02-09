package com.pintia.codeday2;

import java.util.Scanner;

public class PTA054 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char symbol = sc.next().charAt(0);
        int n = sc.nextInt();
        sc.nextLine();
        String[] str=new String[n];
        String[] str2=new String[n];
        for (int i = 0; i < n; i++) {
            StringBuilder sb=new StringBuilder(sc.nextLine());
            str[i]=sb.reverse().toString();
            char[] chars=str[i].toCharArray();
            for (int j = 0; j < chars.length; j++) {
                if(chars[j]!=' ')
                    chars[j]=symbol;
            }
            str[i]=new String(chars);
        }
        boolean flag=true;
        for (int i = 0; i < n; i++) {
            if(!str[i].equals(str[n-i-1])) {
                flag=false;
            }
        }
        if(flag){
            System.out.println("bu yong dao le");
        }
        for (int i = str.length-1; i >=0; i--) {
            System.out.println(str[i]);
        }
    }
}
