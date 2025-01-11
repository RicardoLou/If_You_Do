package com.pintia.codeday2;

import java.util.Scanner;

public class L102 {
    //兰州牛肉面
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        double[] price=new double[n];
        int[] count=new int[n];
        double sum=0;
        for (int i = 0; i <n; i++) {
            price[i]=sc.nextDouble();
        }
        int m=sc.nextInt(),c=sc.nextInt();
        for (int i = 0; m!=0; i++) {
            sum=sum+price[m-1]*c;
            count[m-1]=count[m-1]+c;
            System.out.println(count[m-1]);
            m=sc.nextInt();
            c=sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            System.out.println(count[i]);
        }
        System.out.println(sum);
    }
}
