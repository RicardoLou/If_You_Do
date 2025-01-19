package com.pintia.codeday2;
//L1-007 念数字
import java.util.Scanner;

public class ptaL007 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String num=sc.next();
        String[] trans={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
        String[] after=new String[num.length()];
        String resualt="";
        for (int i = 0; i < num.length(); i++) {
            if(num.charAt(i)-'0'<0) {
                after[0] = "fu";
                i++;
            }
            after[i]=trans[num.charAt(i)-'0'];
        }
        for (int i = 0; i < after.length; i++) {
            if(i==after.length-1)
                resualt=resualt+after[i];
            else
                resualt=resualt+after[i]+" ";
        }
        System.out.println(resualt);
    }
}
