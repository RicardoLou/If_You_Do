package com.pintia.codeday2;
//L1-008 求整数段和
import java.util.Scanner;

public class PTA008 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int start=sc.nextInt(),end=sc.nextInt();
        int sum=0,count=0;
        for (int i = start; i <=end ; i++) {
            System.out.printf("%5d",i);
            sum+=i;
            count++;
            if(count%5==0)
                System.out.println();
        }
        if(count%5!=0){
            System.out.println();
        }
        System.out.println("Sum = "+sum);
    }
}


