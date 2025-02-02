package com.pintia.codeday2;

import java.util.HashSet;
import java.util.Scanner;

//L1-033 出生年
public class PTA033 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int year=sc.nextInt();
        int initialYear=year;
        int n=sc.nextInt();
        while (true){
            if(countDistanctyear(year)==n)
                break;
            year++;
        }
        System.out.printf("%d %04d",year-initialYear,year);

    }
    public static int countDistanctyear(int year){
        String yearStr=String.format("%04d",year);
        HashSet<Character> yearSet=new HashSet<>();
        for (char c:yearStr.toCharArray()) {
            yearSet.add(c);
        }
        return yearSet.size();
    }
}