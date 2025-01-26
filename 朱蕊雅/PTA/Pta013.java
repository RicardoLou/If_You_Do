package com.pintia.codeday2;
//L1-013 计算阶乘和
import java.util.Scanner;

public class Pta013 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=1;
        for (int i = 2; i <=n ; i++) {
            int x=1;
            for (int j = 1; j <=i ; j++)
                x=x*j;
            sum+=x;
        }
        System.out.println(sum);
    }
}
