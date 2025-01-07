package com.pintia.codeday2;

import java.util.Scanner;

public class L101 {
        public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            int n=sc.nextInt(),count=0;
            String[] no=new String[n];
            for (int i = 0; i < n; i++) {
                no[i]=sc.next();
            }
            int k=sc.nextInt();
            sc.nextLine();
            String repalce="huandiao";
            int len=repalce.length();
            String replaceTo="<censored>";
            StringBuilder str=new StringBuilder(sc.nextLine());
            for (int i = 0; i < n; i++) {
                int rlen=no[i].length();
                int index=0;
                while (index>=0){
                    index=str.indexOf(no[i]);
                    if(index>=0){
                        str=str.replace(index,index+rlen,repalce);
                        count++;
                    }
                }
            }
            if(count>k){
                System.out.println(count);
                System.out.println("He Xie Ni Quan Jia!");
            }
            else {
                for (int i = 0; i < count; i++) {
                    int index=0;
                    while (index>=0){
                        index=str.indexOf(repalce);
                        if(index>=0)
                            str=str.replace(index,index+len,replaceTo);
                    }
                }
                System.out.println(str);
            }
        }
}
