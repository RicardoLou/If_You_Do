package com.pintia.codeday2;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class PTA027 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String[] number=sc.nextLine().split("");
        Set<String> set=new HashSet<>();
        for (int i = number.length-1; i >=0; i--) {
            set.add(number[i]);
        }
        String[] num=set.toArray(new String[0]);
        for (int i = 0; i < num.length / 2; i++) {
            String temp = num[i];
            num[i] = num[num.length - i - 1];
            num[num.length - i - 1] = temp;
        }
        System.out.print("int[] arr = new int[]{");
        for (int i = 0; i < num.length-1; i++) {
            System.out.print(num[i]+",");
        }
        System.out.println(num[num.length-1]+"};");
        int[] index=new int[number.length];
        for (int i = 0,k=0; i < number.length; i++,k++) {
            for (int j = 0; j < num.length ; j++) {
                if(num[j].equals(number[i])) {
                    index[k] = j;
                    break;
                }
            }
        }
        System.out.print("int[] index = new int[]{");
        for (int i = 0; i < index.length-1; i++) {
            System.out.print(index[i]+",");
        }
        System.out.println(index[index.length-1]+"};");
    }
}
