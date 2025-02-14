package com.pintia.codeday2;

//import java.math.BigInteger;
//import java.util.Scanner;
//
//public class PTA046 {
//    public static void main(String[] args) {
//        Scanner sc=new Scanner(System.in);
//        int n=sc.nextInt();
//        int count=1;
//        long s=1;
//        long num=1;
//        while (num%n!=0){
//            num*=10;
//            num++;
//            count++;
//        }
//        System.out.println(num/n+" "+count);
//    }
//}

import java.math.BigInteger;
import java.util.Scanner;

public class PTA046 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger n = BigInteger.valueOf(sc.nextInt());
        StringBuilder num = new StringBuilder("1");
        BigInteger numB = new BigInteger(num.toString());
        int c = 1;
        while (!numB.mod(n).toString().equals("0")){
            num.append("1");
            numB = new BigInteger(num.toString());
            c++;
        }
        System.out.println(numB.divide(n).toString() + " " + c);

    }
}

