package com.pintia.codeday2;
//L1-009 N个数求和
import java.util.Scanner;

public class PTA009 {
    public static long gcd(long a,long b){
        while (b!=0){
            long temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        String[] nums=sc.nextLine().split(" ");
        long sumfenzi=0;
        long sumfenmu=1;
        for (String num:nums) {
            String[] stand=num.split("/");
            long fenzi=Long.parseLong(stand[0]);
            long fenmu=Long.parseLong(stand[1]);
            sumfenzi=sumfenzi*fenmu+fenzi*sumfenmu;
            sumfenmu*=fenmu;
            long share=gcd(Math.abs(sumfenzi),sumfenmu);
            sumfenzi/=share;
            sumfenmu/=share;

        }
        if(sumfenzi%sumfenmu==0)
            System.out.println(sumfenzi/sumfenmu);
        else {
            long quotient=sumfenzi/sumfenmu;
            long remainder=sumfenzi%sumfenmu;
            if(quotient==0)
                System.out.println(sumfenzi+"/"+sumfenmu);
            else
                System.out.println(quotient+" "+remainder+"/"+sumfenmu);
        }
    }
}
