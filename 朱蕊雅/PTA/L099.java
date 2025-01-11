package com.pintia.codeday2;
//L1-099 帮助色盲
import java.util.Scanner;

public class L099 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int a = sc.nextInt(), b = sc.nextInt();
            if(b==1){
                System.out.println("-");
                if(a==0)
                    System.out.println("stop");
                else if(a==1)
                    System.out.println("move");
                else if(a==2){
                    System.out.println("stop");
                }
            }
            else {
                if(a==0){
                    System.out.println("biii");
                    System.out.println("stop");
                }
                else if(a==1){
                    System.out.println("dudu");
                    System.out.println("move");
                }
                else if(a==2){
                    System.out.println("-");
                    System.out.println("stop");
                }
            }
        }
}
