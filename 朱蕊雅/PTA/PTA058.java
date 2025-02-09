package com.pintia.codeday2;

import java.util.Scanner;

public class PTA058 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);;
        String[] str=sc.nextLine().split(" ");
        for (int i = 0; i < str.length; i++) {
            int count=0;
            if(str[i].contains("6666")) {
                int index=str[i].indexOf("6666");
                for (int j = index; j < str[i].length(); j++) {
                    if (str[i].charAt(j) == '6') {
                        count++;
                    }
                }
                if(count<=9)
                    str[i]=str[i].replaceFirst(str[i].substring(index,index+count),"9");
                else if(count>9)
                    str[i]=str[i].replaceFirst(str[i].substring(index,index+count),"27");
            }

        }
        for (int i = 0; i < str.length; i++) {
            if(i+1==str.length)
                System.out.println(str[i]);
            else
                System.out.print(str[i]+" ");
        }
    }
}
