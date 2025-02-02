package com.pintia.codeday2;
//L1-035 情人节
import java.util.Scanner;

public class PTA035 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String[] lucky=new String[2];
        int i=1;
        while (true) {
            String name=sc.next();
            if(i==2)
                lucky[0]=name;
            if(i==14)
                lucky[1]=name;
            if(name.equals(".")) {
                i--;
                break;
            }
            i++;
        }
        if(i<2)
            System.out.println("Momo... No one is for you ...");
        else if(i<14)
            System.out.println(lucky[0]+" is the only one for you...");
        else System.out.println(lucky[0]+" and "+lucky[1]+" are inviting you to dinner...");
    }
}
